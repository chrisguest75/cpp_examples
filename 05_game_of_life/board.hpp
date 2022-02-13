#ifndef BOARD_H
#define BOARD_H 

#include <vector>
#include <string>

class Board {
    private: 
        int width; 
        int height; 
        int *board;

    public:
        Board(int width, int height);

        int getWidth();
        int getHeight();

        std::vector<std::string> stateString(); 
};

#endif