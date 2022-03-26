
#ifndef EX2
#define EX2

#include <iostream>
#include <string>
#include <stdexcept>
#include "Direction.hpp"
#include <map>
#include <string>
#include <list>
#include <vector>
#include <exception>


namespace ariel
{
    class Notebook
    {

        // map<int, vector<vector<char>> pages(10, vector<char>(n, '_'))>;

    public:
        std::map<int, std::vector<std::vector<char>>> my_notebook;
        

        void write(int page, int row, int col, Direction dir, std::string const &txt);
        std::string read(int page, int row, int col, Direction dir, int length);
        void erase(int page, int row, int col, Direction dir, int length);
        void show(int page);
    };

};

#endif // EX2