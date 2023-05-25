#ifndef BITMAP_HPP
#define BITMAP_HPP

#include <vector>
#include <string>
using namespace std;

class BitMap{
    private:
        vector<unsigned char> map;
        unsigned rows;
        unsigned cols;
    public:
        BitMap(){
            map = vector<unsigned char>(0);
            rows = 0;
            cols = 0;
        }

        BitMap(string path_file);

        void writeBitMap(string path);

        unsigned char getIndex(unsigned i, unsigned j);

        unsigned getRows();

        unsigned getCols();
};

#endif