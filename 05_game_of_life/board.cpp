#include <sstream>

#include "board.hpp"

Board::Board(int width, int height) {
    this->width = width;
    this->height = height;
    this->board = new int[height * width];
}

int Board::getWidth() {
    return this->width;
}

int Board::getHeight() {
    return this->height;
}

std::vector<std::string> Board::asString() {
    std::vector<std::string> rows;

    for (int y = 0; y < this->height; y++) {
        std::stringstream row;
        for (int x = 0; x < this->width; x++) {
            if (this->board[(y * this->height) + x] == 0) {
                row << "0";
            } else {
                row << "1";
            }
        }
        rows.push_back(row.str());
    }

    return rows;
}
