#include <sstream>
#include <iostream>

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

void Board::setState(std::vector<std::string> rows) {
  for(std::size_t y = 0; y < rows.size(); ++y) {
      std::string row = rows[y];
      for(int x = 0; x < row.length(); ++x) {
          this->board[(y * this->width) + x] = row[x] == '1' ? 1 : 0;
      }  
  }
}

std::vector<std::string> Board::stateString() {
    std::vector<std::string> rows;

    for (int y = 0; y < this->height; y++) {
        std::stringstream row;
        for (int x = 0; x < this->width; x++) {
            if (this->board[(y * this->width) + x] == 0) {
                row << "0";
            } else {
                row << "1";
            }
        }
        rows.push_back(row.str());
    }

    return rows;
}

int Board::countNeighbors(int x, int y) {
    int count = 0;

    // wrap over the board 
    int i = -1 + this->height;

    count += this->board[(((y + i) % this->height) * this->width) + ((x - 1 + this->width) % this->width)];
    count += this->board[(((y + i) % this->height) * this->width) + ((x     + this->width) % this->width)];
    count += this->board[(((y + i) % this->height) * this->width) + ((x + 1 + this->width) % this->width)];

    i = 0 + this->height;
    count += this->board[(((y + i) % this->height) * this->width) + ((x - 1 + this->width) % this->width)];
    //count += this->board[(((y + i) % this->height) * this->width) + ((x    ) % this->width)];
    count += this->board[(((y + i) % this->height) * this->width) + ((x + 1 + this->width) % this->width)];

    i = 1 + this->height;
    count += this->board[(((y + i) % this->height) * this->width) + ((x - 1 + this->width) % this->width)];
    count += this->board[(((y + i) % this->height) * this->width) + ((x     + this->width) % this->width)];
    count += this->board[(((y + i) % this->height) * this->width) + ((x + 1 + this->width) % this->width)];

    return count;
}

void Board::applyRules() {
    int *board = new int[height * width];
    

}