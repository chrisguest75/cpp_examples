#include "board.hpp"

Board::Board(int width, int height) {
    this->width = width;
    this->height = height;
}

int Board::getWidth() {
    return this->width;
}

int Board::getHeight() {
    return this->height;
}
