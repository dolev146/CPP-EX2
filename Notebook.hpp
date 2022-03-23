
#ifndef EX2
#define EX2

#include <iostream>
#include <string>
#include <stdexcept>
#include "Direction.hpp"

using namespace std;
using namespace ariel;

namespace ariel
{
    class Notebook
    {

    public:
        void write(int page, int row, int col, Direction dir, string const & txt);
        string read(int page, int row, int col, Direction dir, int length);
        void erase(int page, int row, int col, Direction dir, int length);
        void show(int page);
    };

};

#endif // EX2