#pragma once
#include <iostream>
#include <vector>
#include <fstream>


class Maze {
    private:
        //members
        int m_rows;
        int m_columns;
        int m_seed;

        std::vector<std::vector<bool> >m_maze_bool;

    public:
        std::vector<std::vector<int> >m_maze;
        Maze(int rows, int columns, int m_seed);
        void solve();
        void print();
        void toFile(std::string fileName);

};