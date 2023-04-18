#ifndef IMAGE_H_
#define IMAGE_H_
#include <cstdint>
#include <string>
#include <vector>

namespace ascii_converter {
// Image interface

// NOLINTNEXTLINE
class Image {
public:
    virtual ~Image() = default;
    virtual void read_from_file(const std::string &filename) = 0;
    virtual void write_to_file(const std::string &filename) = 0;
    [[nodiscard]] std::string get_filename() const noexcept;
    std::vector <std::uint8_t>& get_raw_data();

protected:
    // NOLINTNEXTLINE
    std::vector<std::uint8_t> raw_pixel_data;
    // NOLINTNEXTLINE
    std::string m_filename;
};
}  // namespace ascii_converter

#endif  // IMAGE_H_