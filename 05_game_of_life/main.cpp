#include <iostream>
#include <gtest/gtest.h>
#include "board.hpp"

int main(int argc, char **argv) {
    if ((argc == 2) && std::string(argv[1]).compare("test") == 0) {
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    } else {
        std::cout << "Game of life:" << std::endl;

        std::cout << "argc = " << argc << std::endl;
        argc > 1 ? std::cout << "argv[1] = " << argv[1] : std::cout << "argv = ";
        std::cout << std::endl;
   }
}