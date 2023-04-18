#include <algorithm>
#include <iostream>
#include <string>

#include "../include/bmp.h"
#include "../include/errors.h"
#include "../include/ascii-converter.h"

int main(int argc, char *argv[]) {
    try {
        if (argc < 3) {
            throw ascii_converter::missing_arguments("[exec] path/to/bmp path/to/output/file");
        }
    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
        return 1;
    }

    std::string in_filename(argv[1]);
    std::string out_filename(argv[2]);

    try {
        ascii_converter::BMPImage img;
        img.read_from_file(in_filename);

        auto width = img.get_width();
        auto height = img.get_height();
        auto& raw_data = img.get_raw_data();
        auto bpp = img.get_bytes_per_pixel();

        std::cout << "BMP image metadata:" << std::endl;
        std::cout << "Width: " << width << std::endl;
        std::cout << "Height: " << height << std::endl;
        std::cout << "Raw data size: " << raw_data.size() << std::endl;
        std::cout << "Bytes per pixel: " << bpp << std::endl;

        auto result = ascii_converter::AsciiConverter::convert_raw_image_data_to_ascii_string(bpp, width, height, raw_data);


        std::ofstream os(out_filename, std::ios_base::out);

        if (!os) {
            throw ascii_converter::unable_to_open_file(out_filename);
        }

        if (!os.is_open()) {
            throw ascii_converter::unable_to_open_file(out_filename);
        }

        os << result;
        os.close();

        std::cout << std::endl;
        std::cout << "==== ASCII image generated successfully! ====" << std::endl;
        std::cout << "Output filepath is '" << out_filename << "'" << std::endl;

    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
        return 1;
    }

    return 0;
}