#include <iostream>
#include "boost/program_options.hpp"
#include <png.h>
#include <fstream>
#include <iostream>
#include <vector>

namespace po = boost::program_options;

using namespace std;

void saveBufferToPng(const char* filename, const std::vector<unsigned char>& buffer, int width, int height) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (!png) {
        std::cerr << "Failed to create png write struct." << std::endl;
        fclose(fp);
        return;
    }

    png_infop info = png_create_info_struct(png);
    if (!info) {
        std::cerr << "Failed to create png info struct." << std::endl;
        png_destroy_write_struct(&png, nullptr);
        fclose(fp);
        return;
    }

    if (setjmp(png_jmpbuf(png))) {
        std::cerr << "Error during png creation." << std::endl;
        png_destroy_write_struct(&png, &info);
        fclose(fp);
        return;
    }

    png_init_io(png, fp);

    // Write header (8 bit color depth)
    png_set_IHDR(png, info, width, height, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    png_write_info(png, info);

    // Write image data
    std::vector<png_bytep> row_pointers(height);
    for (int y = 0; y < height; y++) {
        row_pointers[y] = (png_bytep)(buffer.data() + y * width * 3); // 3 bytes per pixel (RGB)
    }
    png_write_image(png, row_pointers.data());

    // End write
    png_write_end(png, nullptr);

    // Cleanup
    png_destroy_write_struct(&png, &info);
    fclose(fp);
    std::cout << "PNG file saved: " << filename << std::endl;
}


void generate(int b) {
    cout << "generate(b:" << b << ")" << endl;
        // Example: Create a red image (100x100)
    int width = 100;
    int height = 100;
    std::vector<unsigned char> buffer(width * height * 3); // RGB image

    // Fill the buffer with red color
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            buffer[index] = 255;     // Red
            buffer[index + 1] = 0;   // Green
            buffer[index + 2] = 0;   // Blue
        }
    }

    // Save to PNG
    saveBufferToPng("output.png", buffer, width, height);
}

int main(const int argc, const char **argv)
{
    po::options_description desc("Allowed options");
    desc.add_options()
    ("help", "produce help message")
    ("generate", "Generate the mandelbrot");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);  

    if (vm.count("help")) {
        cout << desc << "\n";
        return 1;
    }
    
    if (vm.count("generate")) {
        generate(0);
    } else {
        cout << desc << endl;
    }


}

