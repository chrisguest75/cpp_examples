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
    
    for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
            int alive = this->board[(y * this->width) + x];
            int count = this->countNeighbors(x, y);

            board[(y * this->width) + x] = alive;

            // rule 1
            // Any live cell with fewer than two live neighbors dies, as if by underpopulation.
            if (alive > 0 && count < 2) {
                board[(y * this->width) + x] = 0;
            }
            // rule 2
            // Any live cell with two or three live neighbors lives on to the next generation.
            if (alive > 0 && count >= 2 && count <=3) {
                board[(y * this->width) + x] = 1;
            }
            // rule 3
            // Any live cell with more than three live neighbors dies, as if by overpopulation.
            if (alive > 0 && count > 3) {
                board[(y * this->width) + x] = 0;
            }
            // rule 4
            // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
            if (alive == 0 && count == 3) {
                board[(y * this->width) + x] = 1;
            }

        }
    }

    delete this->board;

    this->board = board;
}