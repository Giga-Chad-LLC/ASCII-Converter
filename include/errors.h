#ifndef ERRORS_H_
#define ERRORS_H_

#include <cstdint>
#include <exception>
#include <stdexcept>

namespace ascii_converter {
struct missing_arguments : std::runtime_error {
    explicit missing_arguments(const std::string use) : std::runtime_error("Missing arguments. Use: " + use) {
    }
};

struct file_does_not_exist : std::runtime_error {
    explicit file_does_not_exist(const std::string& filepath) : std::runtime_error("'" + filepath + "': file does not exist") {
    }
};

struct unable_to_open_file : std::runtime_error {
    explicit unable_to_open_file(const std::string &filename)
        : std::runtime_error("Unable to open file: \"" + filename + "\"") {
    }
};

struct invalid_bmp_format : std::runtime_error {
    explicit invalid_bmp_format(std::uint32_t header_size)
        : std::runtime_error(
              "Invalid BMP: expected version 3 and header size 40, but header "
              "size is " +
              std::to_string(header_size)) {
    }
};

struct invalid_bmp_image_height : std::runtime_error {
    explicit invalid_bmp_image_height(std::int32_t image_height)
        : std::runtime_error("Invalid BMP: expected positive biHeight, got " +
                             std::to_string(image_height)) {
    }
};

struct invalid_bmp_image_bit_count : std::runtime_error {
    explicit invalid_bmp_image_bit_count(std::uint16_t bit_count)
        : std::runtime_error("Invalid BMP: expected 24 bits per pixel, got " +
                             std::to_string(bit_count)) {
    }
};

struct invalid_bmp_image_pallete : std::runtime_error {
    explicit invalid_bmp_image_pallete()
        : std::runtime_error("Invalid BMP: color palette is unsupported") {
    }
};

struct insufficient_memory : std::runtime_error {
    explicit insufficient_memory() : std::runtime_error("Insufficient memory") {
    }
};
}  // namespace ascii_converter

#endif