#include "../include/ascii-converter.h"

#include <cmath>

namespace ascii_converter {

std::uint8_t AsciiConverter::get_gray_scale_pixel_value(std::uint8_t red, std::uint8_t green, std::uint8_t blue) {
    double r = static_cast<double> (red);
    double g = static_cast<double> (green);
    double b = static_cast<double> (blue);

    return static_cast<std::uint8_t> (0.21 * r + 0.72 * g + 0.07 * b);
}

std::string AsciiConverter::convert_raw_image_data_to_ascii_string(std::uint32_t bytes_per_pixel, std::uint32_t width, std::uint32_t height, const std::vector <std::uint8_t>& data) {
    std::string result = "";
    
    for (int y = height - 1; y >= 0; --y) { // because in bmp format pixels got from bottom to top
        for (int x = 0; x < width; ++x) {
            int offset = (y * width + x) * bytes_per_pixel;

            auto r = data[offset];
            auto g = data[offset + 1];
            auto b = data[offset + 2];

            auto grey_scale = get_gray_scale_pixel_value(r, g, b);
            char ascii = ascii_chars[std::ceil((ascii_chars.size() - 1) * grey_scale / 255)];

            result += ascii;
        }

        result += "\n";
    }

    return result;
}

}