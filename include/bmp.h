#ifndef BMP_H_
#define BMP_H_
#include <cassert>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include "errors.h"
#include "image.h"

namespace ascii_converter {
#pragma pack(push, 1)
const std::uint16_t BPM3_FILE_FORMAT_LABEL = 0x4D42;

struct BMPFileHeader {
    std::uint16_t file_type =
        BPM3_FILE_FORMAT_LABEL;           // File type always BM which is 0x4D42
    std::uint32_t file_size = 0;          // Size of the file (in bytes)
    std::uint16_t reserved1 = 0;          // Reserved, always 0
    std::uint16_t reserved2 = 0;          // Reserved, always 0
    std::uint32_t offset_image_data = 0;  // Start position of pixel data (bytes
                                          // from the beginning of the file)
};
#pragma pack(pop)

#pragma pack(push, 1)
struct BMPInfoHeader {
    std::uint32_t header_size = 0;  // Size of this header (in bytes)
    std::int32_t image_width = 0;   // width of bitmap in pixels
    std::int32_t image_height = 0;  // height of bitmap in pixels
    std::uint16_t planes = 1;
    std::uint16_t bit_count = 0;    // No. of bits per pixel
    std::uint32_t compression = 0;  // 0 or 3 - uncompressed.
    std::uint32_t size_image = 0;   // bytes that store image (pixel data)
    std::int32_t x_pixels_per_meter = 0;
    std::int32_t y_pixels_per_meter = 0;
    std::uint32_t colors_used =
        0;  // No. color indexes in the color table. Use 0 for the max number
            // of colors allowed by bit_count
    std::uint32_t colors_important =
        0;  // No. of colors used for displaying the
            // bitmap. If 0 all colors are required
};
#pragma pack(pop)

class BMPImage final : public Image {
private:
    BMPFileHeader file_header;
    BMPInfoHeader bmp_info_header;
    static std::uint8_t get_padding_byte_count_per_row(
        std::uint32_t byte_count_per_row);

public:
    BMPImage() = default;
    void read_from_file(const std::string &filename) final;
    void write_to_file(const std::string &filename) final;
};
}  // namespace ascii_converter

#endif