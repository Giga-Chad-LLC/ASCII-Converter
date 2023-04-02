#include "../include/bmp.h"

namespace ascii_converter {
void BMPImage::read_from_file(const std::string &filename) {
    // Check that file is correctly opened
    if (!std::filesystem::exists(filename)) {
        throw file_does_not_exist();
    }

    std::ifstream is(filename, std::ios_base::in | std::ios_base::binary);

    if (!is.is_open()) {
        throw unable_to_open_file(filename);
    }

    // read the header info
    is.read(reinterpret_cast<char *>(&file_header), sizeof(file_header));
    // read bmp info header
    is.read(reinterpret_cast<char *>(&bmp_info_header),
            sizeof(bmp_info_header));

    // check that filetype is actyally BMP3
    if (file_header.file_type != BPM3_FILE_FORMAT_LABEL) {
        throw invalid_bmp_format(bmp_info_header.header_size);
    }

    // check that height is positive
    if (bmp_info_header.image_height <= 0) {
        throw invalid_bmp_image_height(bmp_info_header.image_height);
    }

    // check for 24-bits pixel color scheme (BGR == RGB little-endian)
    if (bmp_info_header.bit_count != 24) {
        throw invalid_bmp_image_bit_count(bmp_info_header.bit_count);
    }

    // check if color-table is used
    if (bmp_info_header.colors_used != 0U) {
        throw invalid_bmp_image_pallete();
    }

    // go to the pixel data location
    is.seekg(file_header.offset_image_data, std::ifstream::beg);
    std::uint32_t byte_count_per_row =
        bmp_info_header.image_width * bmp_info_header.bit_count / 8;
    std::uint8_t padding_byte_count_per_row =
        get_padding_byte_count_per_row(byte_count_per_row);

    try {
        raw_pixel_data.resize(
            (byte_count_per_row + padding_byte_count_per_row) *
            bmp_info_header.image_height);
    } catch (const std::bad_alloc &) {
        throw insufficient_memory();
    }

    is.read(reinterpret_cast<char *>(raw_pixel_data.data()),
            static_cast<std::streamsize>(raw_pixel_data.size()));
}

void BMPImage::write_to_file(const std::string &filename) {
    std::ofstream os(filename, std::ios_base::out | std::ios_base::binary);

    if (!os) {
        throw unable_to_open_file(filename);
    }

    if (!os.is_open()) {
        throw unable_to_open_file(filename);
    }

    os.write(reinterpret_cast<char *>(&file_header), sizeof(file_header));
    os.write(reinterpret_cast<char *>(&bmp_info_header),
             sizeof(bmp_info_header));

    os.write(reinterpret_cast<char *>(raw_pixel_data.data()),
             static_cast<std::streamsize>(raw_pixel_data.size()));
}

std::uint8_t BMPImage::get_padding_byte_count_per_row(
    std::uint32_t byte_count_per_row) {
    return (4 - (byte_count_per_row % 4)) % 4;
}

}