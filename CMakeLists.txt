cmake_minimum_required(VERSION 3.10)

project(ascii-converter CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)
add_executable(ascii_converter src/main.cpp src/bmp.cpp src/image.cpp)

# add_executable(bmp-test src/doctest_main.cpp src/image_test.cpp)
# target_include_directories(bmp-test PRIVATE doctest)