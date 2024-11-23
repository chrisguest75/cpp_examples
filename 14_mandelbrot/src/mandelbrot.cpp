#include <iostream>
#include "boost/program_options.hpp"
namespace po = boost::program_options;

using namespace std;

void generate(int b) {
    cout << "generate(b:" << b << ")" << endl;
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

