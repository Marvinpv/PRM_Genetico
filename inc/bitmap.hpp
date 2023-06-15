#ifndef BITMAP_HPP
#define BITMAP_HPP

#include <vector>
#include <string>
#include "point.hpp"
using namespace std;

class BitMap{
    private:
        vector<unsigned char> map;
        unsigned rows;
        unsigned cols;

        void inflateBorders(unsigned radius);
                
    public:

        BitMap(){
            map = vector<unsigned char>(0);
            rows = 0;
            cols = 0;
        }

        BitMap(string path_file);

        void writeBitMap(string path);

        void smoothBitMap();

        void inflateObstacles(unsigned radius);

        unsigned char getIndex(unsigned i, unsigned j);

        void setIndex(unsigned i, unsigned j, unsigned char value);

        unsigned getRows();

        unsigned getCols();

        bool checkCollision(Point p1, Point p2, unsigned &dist);
};

#endif