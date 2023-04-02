#include "../include/image.h"
#include "../include/bmp.h"

namespace ascii_converter {
std::string Image::get_filename() const noexcept {
    return m_filename;
}
}  // namespace ascii_converter