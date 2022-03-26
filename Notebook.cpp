#include "Notebook.hpp"
#define COL_LIMIT 99
#define COL_AMOUNT 100
#define SAFTEY_ADD 50
// https://stackoverflow.com/questions/3136520/determine-if-map-contains-a-value-for-a-key

using namespace std;
namespace ariel
{

    void Notebook::write(int page, int row, int column, Direction dir, string const &txt)
    {
        int size_of_str1 = txt.size();
        if (column > COL_LIMIT || size_of_str1 + column > COL_LIMIT)
        {
            throw std::invalid_argument("column can't be greater that 99 , bad index");
        }
        map<int, vector<vector<char>>>::iterator it = my_notebook.find(page);

        if (it != my_notebook.end())
        {
            // found
            vector<vector<char>> matrix;
            matrix = it->second;
            if (dir == Direction::Horizontal)
            {
                int size_of_str = txt.size();
                printf("size of str: %d", size_of_str);
                int counter = 0;
                for (int i = column; i < size_of_str; i++)
                {
                    printf("txt[counter] : %c", txt[counter]);
                    matrix[row][i] = txt[counter];
                    counter++;
                }
            }
            else
            {
            }
        }
        else
        {
            // not found
            vector<vector<char>> matrix(row + SAFTEY_ADD, vector<char>(COL_AMOUNT, '_'));
            if (dir == Direction::Horizontal)
            {
                int size_of_str = txt.size();
                printf("size of str: %d", size_of_str);
                int counter = 0;
                for (int i = column; i < size_of_str; i++)
                {
                    printf("txt[counter] : %c", txt[counter]);
                    matrix[row][i] = txt[counter];
                    counter++;
                }
            }
            else if (dir == Direction::Vertical)
            {
                int size_of_str = txt.size();
                printf("size of str: %d", size_of_str);
                int counter = 0;
                for (int i = row; i < size_of_str; i++)
                {
                    printf("txt[counter] : %c", txt[counter]);
                    matrix[i][column] = txt[counter];
                    counter++;
                }
            }

            my_notebook.insert(std::pair<int, vector<vector<char>>>(page, matrix));
        }
    }

    string Notebook::read(int page, int row, int column, Direction dir, int length)
    {

        this->erase(1, 1, 1, Direction::Horizontal, 1);
        return " ";
    }
    void Notebook::erase(int page, int row, int column, Direction dir, int length)
    {
    }
    void Notebook::show(int page)
    {
        std::string output;
        map<int, vector<vector<char>>>::iterator it = my_notebook.find(page);
        std::string output;
        if (it != my_notebook.end())
        {
            // found
            vector<vector<char>> matrix;
            matrix = it->second;
            for (int i = 0; i <  matrix.size(); ++i)
            {
                for (int j = 0; j < matrix[i].size(); ++j)
                {
                    output += matrix[i][j];
                }
                output += '\n';
            }
        }
    }
}
