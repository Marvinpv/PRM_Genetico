#include <bitmap.hpp>
#include <imageES.hpp>

BitMap::BitMap(string path_file){
    map = LeerImagenPGM(path_file.c_str(), rows, cols);
}

unsigned char BitMap::getIndex(unsigned i, unsigned j){
    return map[i*cols + j];
}

unsigned BitMap::getRows(){
    return rows;
}

unsigned BitMap::getCols(){
    return cols;
}

void BitMap::writeBitMap(string path){
    string s(map.begin(),map.end());
    EscribirImagenPGM(path.c_str(), reinterpret_cast<const unsigned char *>(s.c_str()),rows, cols);
}
