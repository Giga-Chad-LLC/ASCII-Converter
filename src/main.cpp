#include <algorithm>
#include <iostream>
#include <string>
#include "../include/bmp.h"
#include "../include/errors.h"

int main(int argc, char *argv[]) {
    try {
        if (argc < 3) {
            throw ascii_converter::missing_arguments();
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
        img.write_to_file(out_filename);
    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
        return 1;
    }

    return 0;
}