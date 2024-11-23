#include <iostream>
#include "boost/program_options.hpp"
#include <png.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <complex>

namespace po = boost::program_options;

using namespace std;

// Convert HSV to RGB
void hsvToRgb(double h, double s, double v, unsigned char& r, unsigned char& g, unsigned char& b) {
    double c = v * s;
    double x = c * (1 - std::fabs(std::fmod(h / 60.0, 2) - 1));
    double m = v - c;

    double r_prime, g_prime, b_prime;
    if (h >= 0 && h < 60) {
        r_prime = c, g_prime = x, b_prime = 0;
    } else if (h >= 60 && h < 120) {
        r_prime = x, g_prime = c, b_prime = 0;
    } else if (h >= 120 && h < 180) {
        r_prime = 0, g_prime = c, b_prime = x;
    } else if (h >= 180 && h < 240) {
        r_prime = 0, g_prime = x, b_prime = c;
    } else if (h >= 240 && h < 300) {
        r_prime = x, g_prime = 0, b_prime = c;
    } else {
        r_prime = c, g_prime = 0, b_prime = x;
    }

    r = static_cast<unsigned char>((r_prime + m) * 255);
    g = static_cast<unsigned char>((g_prime + m) * 255);
    b = static_cast<unsigned char>((b_prime + m) * 255);
}

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


void generateMandelbrot(std::vector<unsigned char> &buffer, int width, int height, int maxIterations, double xmin = -2.5, double xmax = 1.0, double ymin = -1.0, double ymax = 1.0) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            double cr = xmin + (xmax - xmin) * x / width;
            double ci = ymin + (ymax - ymin) * y / height;

            std::complex<double> c(cr, ci);
            std::complex<double> z(0, 0);
            int iterations = 0;

            while (std::abs(z) <= 2.0 && iterations < maxIterations) {
                z = z * z + c;
                iterations++;
            }

            // Smooth coloring formula for continuous gradient
            double smoothIter = iterations - std::log2(std::log2(std::abs(z))) + 4.0;

            // Map iterations to color
            double hue = 360.0 * smoothIter / maxIterations; // Cycle hue
            double saturation = 1.0;
            double value = iterations < maxIterations ? 1.0 : 0.0; // Inside set is black

            unsigned char r, g, b;
            hsvToRgb(hue, saturation, value, r, g, b);

            int index = (y * width + x) * 3;
            buffer[index] = r;
            buffer[index + 1] = g;
            buffer[index + 2] = b;
        }
    }
}

void generateRed(std::vector<unsigned char> &buffer, int width, int height) {
    // Fill the buffer with red color
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            buffer[index] = 255;     // Red
            buffer[index + 1] = 0;   // Green
            buffer[index + 2] = 0;   // Blue
        }
    }
}

int main(const int argc, const char **argv)
{
    po::options_description desc("Allowed options");
    desc.add_options()
    ("help", "produce help message")
    ("red", "Generate red square")
    ("mandelbrot", "Generate the mandelbrot");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);  

    if (vm.count("help")) {
        cout << desc << "\n";
        return 1;
    }

    bool selected = false;
    if (vm.count("mandelbrot")) {
        // Image dimensions and Mandelbrot parameters
        int width = 1920;
        int height = 1080;
        int maxIterations = 1000;

        std::vector<unsigned char> buffer(width * height * 3); // RGB buffer

        double xmin = -1.0, xmax = 0.2;
        double ymin = -0.5, ymax = 0.5;

        // Generate Mandelbrot image
        generateMandelbrot(buffer, width, height, maxIterations, xmin, xmax, ymin, ymax);

        // Save to PNG
        saveBufferToPng("./out/mandelbrot.png", buffer, width, height);
        selected = true;
    }

    if (vm.count("red")) {
        // Example: Create a red image (100x100)
        int width = 100;
        int height = 100;
        std::vector<unsigned char> buffer(width * height * 3); // RGB image

        generateRed(buffer, width, height);

        // Save to PNG
        saveBufferToPng("./out/output.png", buffer, width, height);

        selected = true;
    } 

    if (!selected) {
        cout << desc << endl;
    }
}

