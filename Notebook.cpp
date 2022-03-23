#include "Notebook.hpp"

namespace ariel
{
    void Notebook::write(int page, int row, int column, Direction dir,string const &txt)
    {
      
    }
    string Notebook::read(int page, int row, int column, Direction dir, int length)
    {
        this->erase(1,1,1,Direction::Horizontal,1);
        return " ";
    }
    void Notebook::erase(int page, int row, int column, Direction dir, int length)
    {
        
    }
    void Notebook::show(int page)
    {
        
    }
}


