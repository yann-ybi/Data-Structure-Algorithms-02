#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include "maze.h"
#include <fstream>



int main(int argc, char** argv){
    int rows, columns, seed, i, j;
    rows = stoi(argv[2]);
    columns = stoi(argv[3]);
    seed = stoi(argv[1]);
    srand(seed);
    //cout<<seed;
    Maze maze1(rows,columns,seed);
    ofstream MyFile(argv[4]);

    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            MyFile << maze1.m_maze[i][j] << " ";
        }
        MyFile << "\n";
    }
    MyFile.close();
    
}