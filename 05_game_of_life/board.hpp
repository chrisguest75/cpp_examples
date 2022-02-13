#ifndef BOARD_H
#define BOARD_H 

class Board {
    private: 
        int width; 
        int height; 

    public:
        Board(int width, int height);

        int getWidth();
        int getHeight();
};

#endif