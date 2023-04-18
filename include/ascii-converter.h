#ifndef ASCII_CONVERTER_H_
#define ASCII_CONVERTER_H_

#include <string>
#include <cstdint>
#include <vector>


namespace ascii_converter {

class AsciiConverter {
private:
    inline static std::string ascii_chars = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
    
    static std::uint8_t get_gray_scale_pixel_value(std::uint8_t red, std::uint8_t green, std::uint8_t blue);

public:
    static std::string convert_raw_image_data_to_ascii_string(std::uint32_t bytes_per_pixel, std::uint32_t width, std::uint32_t height, const std::vector <std::uint8_t>& data);
};

}

#endif