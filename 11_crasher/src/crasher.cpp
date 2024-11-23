#include <iostream>
#include "boost/program_options.hpp"
namespace po = boost::program_options;

using namespace std;

void divideByZero(int b) {
    cout << "divideByZero(b:" << b << ")" << endl;
    int a = 10 / b;
    cout << "a: " << a << endl;
}

void nullPointer(int *p) {
    cout << "nullPointer(p:" << p << ")" << endl;
    p[0] = 10;
}

int main(const int argc, const char **argv)
{
    po::options_description desc("Allowed options");
    desc.add_options()
    ("help", "produce help message")
    ("nullPointer", "Trigger nullPointer")
    ("divideByZero", "Trigger divideByZero");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);  

    if (vm.count("help")) {
        cout << desc << "\n";
        return 1;
    }
    
    cout << "**********************************" << endl;
    cout << "Welcome to the crasher application" << endl;
    cout << "**********************************" << endl;

    if (vm.count("nullPointer")) {
        nullPointer(0);
    } 

    if (vm.count("divideByZero")) {
        divideByZero(0);
    } 

    cout << desc << "\n";
}

