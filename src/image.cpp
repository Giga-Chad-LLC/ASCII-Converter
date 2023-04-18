#include "../include/image.h"
#include "../include/bmp.h"

namespace ascii_converter {
std::string Image::get_filename() const noexcept {
    return m_filename;
}

std::vector <std::uint8_t>& Image::get_raw_data() {
    return raw_pixel_data;
}
}  // namespace ascii_converter