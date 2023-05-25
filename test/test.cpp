#include <iostream>
#include <bitmap.hpp>
#include <string>

using namespace std;

int main(void){
    string path = "./maps/room1.pgm";
    BitMap mapa_prueba(path);
    cout<<"Rows: " << mapa_prueba.getRows() << " Cols: " <<mapa_prueba.getCols() << endl;

    for(unsigned i = 0 ; i < mapa_prueba.getRows() ; i++){
        for(unsigned j = 0 ; j < mapa_prueba.getCols() ; j++){
            cout <<int(mapa_prueba.getIndex(i,j));
        }
        cout << endl;
    }
    
}
