#include "maze.h"


Maze::Maze(int rows, int columns, int seed){
    m_rows = rows;
    m_columns = columns;
    m_seed = seed;
    int i, j;

    //Creates Empty Cells
    for(i = 0; i < rows; i++){
        std::vector<int>temp;
        std::vector<bool>tempBool;

        for(j = 0; j < columns; j++){
            temp.push_back(15);
            tempBool.push_back(false);
        }
        m_maze.push_back(temp);
        m_maze_bool.push_back(tempBool);
    }

    //Creates path
    std::vector<int> A;
    std::vector<int> Ax;
    std::vector<int> Ay;
    int current, current_x = 0, current_y = 0, idx;
    std::vector<char> neighbors;
    std::vector<char> newNeighbors;
    char RandomCell;
    m_maze[0][0] -= 8;
    m_maze[m_rows-1][m_columns-1] -= 4;
    A.push_back(m_maze[0][0]);
    Ax.push_back(current_x);
    Ay.push_back(current_y);

    //Checkpoint


    while(A.size()!=0){
        //`current` <- remove last element from `A`
        current = A[A.size()-1];
        current_x = Ax[Ax.size()-1];
        current_y = Ay[Ay.size()-1];
        //std::cout<<"A has size:"<<A.size()<<" and just added:"<<current<<" at to:("<<current_y<<","<<current_x<<")"<<"\n";
        A.pop_back();
        Ax.pop_back();
        Ay.pop_back();
        m_maze_bool[current_x][current_y] = true;
        neighbors.clear();
        //`neighbors` <- `current`'s neighbors not visited yet
        if(current_x>0){
            if(!m_maze_bool[current_x-1][current_y]){
                //std::cout<<"N has not been checked";
                neighbors.push_back('N');
            }
        }
        if(current_x<m_rows-1){
            if(!m_maze_bool[current_x+1][current_y]){
                //std::cout<<"S has not been checked";
                neighbors.push_back('S');
            }
        }
        if(current_y<m_columns-1){
            if(!m_maze_bool[current_x][current_y+1]){
                //std::cout<<"E has not been checked";
                neighbors.push_back('E');
            }
        }
        if(current_y>0){
            if(!m_maze_bool[current_x][current_y-1]){
                //std::cout<<"W has not been checked";
                neighbors.push_back('W');
            }
        }
        //std::cout<<". Size is"<<neighbors.size()<<"\n";
        //if `neighbors` is not empty
        if(neighbors.size()!=0){
            //insert `current` at the end of `A`
            Ax.push_back(current_x);
            Ay.push_back(current_y);
            //`neigh` <- pick a random neighbor from `neighbors`
            idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size());
            RandomCell = neighbors[idx];
            //remove the wall between `current` and `neigh`
            if(RandomCell=='N'){
                current -= 8;
                m_maze[current_x][current_y] = current;
                A.push_back(m_maze[current_x][current_y]);
                //std::cout<<m_maze[current_x][current_y];
                current_x--;
                m_maze[current_x][current_y] -= 4;
            } else if(RandomCell=='S'){
                current -= 4;
                m_maze[current_x][current_y] = current;
                A.push_back(m_maze[current_x][current_y]);
                //std::cout<<m_maze[current_x][current_y];
                current_x++;
                m_maze[current_x][current_y] -= 8;
            } else if(RandomCell=='E'){
                current -= 2;
                m_maze[current_x][current_y] = current;
                A.push_back(m_maze[current_x][current_y]);
                //std::cout<<m_maze[current_x][current_y];
                current_y++;
                m_maze[current_x][current_y] -= 1;
            } else if(RandomCell=='W'){
                current -= 1;
                m_maze[current_x][current_y] = current;
                A.push_back(m_maze[current_x][current_y]);
                //std::cout<<m_maze[current_x][current_y];
                current_y--;
                m_maze[current_x][current_y] -= 2;
            }
            //mark `neigh` as visited
            m_maze_bool[current_x][current_y] = true;
            for(i=0; i < neighbors.size(); i++){
                if (neighbors[i]!=RandomCell){
                    newNeighbors.push_back(neighbors[i]);
                }
            }
            //insert `neigh` at the end of `A`
            //std::cout<<m_maze[current_x][current_y];
            A.push_back(m_maze[current_x][current_y]);
            Ax.push_back(current_x);
            Ay.push_back(current_y);
        }

    }
    //std::cout<<"done";
}

void Maze::print()
{
    int i, j;
    for(i = 0; i < m_rows; i++){
        for(j = 0; j < m_columns; j++){
            std::cout << m_maze[i][j] << " ";
        }
        std::cout << "\n";
    }
}

