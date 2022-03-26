#include "Notebook.hpp"
constexpr int COL_LIMIT = 99;
constexpr int COL_AMOUNT = 100;
constexpr int SAFTEY_ADD = 2;

// hours wasted: 48
// used searches
// https://stackoverflow.com/questions/3136520/determine-if-map-contains-a-value-for-a-key
// https://stackoverflow.com/questions/65877299/wsign-conversion-error-when-getting-index-for-vector
// https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/
// https://stackoverflow.com/questions/191757/how-to-concatenate-a-stdstring-and-an-int
// https://stackoverflow.com/questions/4527686/how-to-update-stdmap-after-using-the-find-method
// https://stackoverflow.com/questions/44467268/how-to-extend-vector-size-by-one-element-and-fill-it-with-variable
// https://stackoverflow.com/questions/15889578/how-can-i-resize-a-2d-vector-of-objects-given-the-width-and-height

using namespace std;
namespace ariel
{

    void Notebook::write(int page, int row, int column, Direction dir, string const &txt)
    {

        unsigned int size_of_str1 = txt.size();
        unsigned int u_column = unsigned(column);
        if (column > COL_LIMIT || size_of_str1 + u_column > COL_LIMIT)
        {
            throw std::invalid_argument("column can't be greater that 99 , bad index");
        }
        map<int, vector<vector<char>>>::iterator it = my_notebook.find(page);
        unsigned int u_row = unsigned(row);

        if (it != my_notebook.end())
        {
            // found
            std::cout << "page found :\n";
            vector<vector<char>> matrix;
            matrix = it->second;
            unsigned int resize_counter = matrix.size();
            while (matrix.size() < u_row)
            {
                matrix.resize(matrix.size() * SAFTEY_ADD);
            }
            unsigned int resize_amount = matrix.size() - resize_counter;

            // std::cout << "matrix[100][51] : " << matrix[100][51] << endl;
            if (dir == Direction::Horizontal)
            {
                unsigned int size_of_str = txt.size();
                // cout << "size of str: " << size_of_str << endl;
                unsigned int counter = 0;
                for (unsigned int i = u_column; i < size_of_str + u_column; i++)
                {
                    // std::cout << "txt[counter] : " << txt[counter] << endl;
                    if (matrix[u_row][i] != '_')
                    {
                        throw std::invalid_argument("index already taken ");
                    }
                    matrix[u_row][i] = txt[counter];
                    counter++;
                }
                // std::cout << "matrix[100][51] : " << matrix[100][51] << endl;
            }
            else if (dir == Direction::Vertical)
            {
                unsigned int size_of_str = txt.size();
                // std::cout << "size of str: " << size_of_str << endl;
                unsigned int counter = 0;
                for (unsigned int i = u_row; i < size_of_str + u_row; i++)
                {
                    // std::cout << "txt[counter]: " << txt[counter] << endl;
                    if (matrix[i][u_column] != '_')
                    {
                        throw std::invalid_argument("index already taken ");
                    }
                    matrix[i][u_column] = txt[counter];
                    // std::cout << "matrix[i][u_column]: " << matrix[i][u_column] << endl;
                    counter++;
                }
                it->second = matrix;
            }
        }
        else
        {
            // not found
            std::cout << "page not found :\n";
            // std::cout << "u_row:" << u_row << endl;
            vector<vector<char>> matrix(u_row, vector<char>(COL_AMOUNT, '_'));
            unsigned int resize_counter = matrix.size();
            while (matrix.size() <= u_row)
            {
                matrix.resize(matrix.size() * SAFTEY_ADD);
            }
            unsigned int resize_amount = matrix.size() - resize_counter;
            // std::cout << "dolev: " << matrix.size() << endl;
            for (unsigned int i = resize_counter - 1; i < matrix.size(); i++)
            {
                // std::cout << i << endl;
                matrix[i].resize(COL_AMOUNT, '_');
            }
            // std::cout << "dolev2: " << matrix[99].size() << endl;

            if (dir == Direction::Horizontal)
            {
                unsigned int size_of_str = txt.size();
                // cout << "size of str: " << size_of_str << endl;
                unsigned int counter = 0;
                for (unsigned int i = u_column; i < size_of_str + u_column; i++)
                {
                    // std::cout << "size: " << matrix.size() << endl;
                    if (matrix[u_row][i] != '_')
                    {
                        throw std::invalid_argument("index already taken ");
                    }
                    // std::cout << "txt[counter] : " << txt[counter] << endl;
                    matrix[u_row][i] = txt[counter];
                    counter++;
                }
            }
            else if (dir == Direction::Vertical)
            {
                unsigned int size_of_str = txt.size();
                // std::cout << "size of str: " << size_of_str << endl;
                unsigned int counter = 0;
                for (unsigned int i = u_row; i < size_of_str + u_row; i++)
                {
                    // std::cout << "txt[counter]: " << txt[counter] << endl;
                    if (matrix[i][u_column] != '_')
                    {
                        throw std::invalid_argument("index already taken ");
                    }
                    matrix[i][u_column] = txt[counter];
                    // std::cout << "matrix[i][u_column]: " << matrix[i][u_column] << endl;
                    counter++;
                }
            }
            std::cout << "finish write " << endl;
            my_notebook.insert(std::pair<int, vector<vector<char>>>(page, matrix));
        }
    }

    string Notebook::read(int page, int row, int column, Direction dir, int length)
    {
        unsigned int u_row = unsigned(row);
        unsigned int u_column = unsigned(column);
        unsigned int ulength = unsigned(length);

        std::string output;
        map<int, vector<vector<char>>>::iterator it = my_notebook.find(page);

        if (it != my_notebook.end())
        {
            // found
            vector<vector<char>> matrix;
            matrix = it->second;
            if (dir == Direction::Horizontal)
                for (unsigned int i = u_column; i < u_column + ulength; i++)
                {
                    output += matrix[u_row][i];
                }

            else
            {
                // std::cout << "dick :" << endl;
                for (unsigned int i = u_row; i < u_row + ulength; i++)
                {
                    output += matrix[i][u_column];
                }
            }
        }
        // this->erase(1, 1, 1, Direction::Horizontal, 1);
        return output;
    }
    void Notebook::erase(int page, int row, int column, Direction dir, int length)
    {

        unsigned int length1 = unsigned(length);
        unsigned int u_column = unsigned(column);
        if (column > COL_LIMIT || length1 + u_column > COL_LIMIT)
        {
            throw std::invalid_argument("column can't be greater that 99 , bad index");
        }
        map<int, vector<vector<char>>>::iterator it = my_notebook.find(page);
        unsigned int u_row = unsigned(row);

        if (it != my_notebook.end())
        {
            // found
            std::cout << " erase ::: $$  page found :\n";
            vector<vector<char>> matrix;
            matrix = it->second;
            unsigned int resize_counter = matrix.size();
            while (matrix.size() < u_row)
            {
                matrix.resize(matrix.size() * SAFTEY_ADD);
            }
            unsigned int resize_amount = matrix.size() - resize_counter;

            // std::cout << "matrix[100][51] : " << matrix[100][51] << endl;
            if (dir == Direction::Horizontal)
            {
                unsigned int size_of_str = length1;
                // cout << "size of str: " << size_of_str << endl;
                unsigned int counter = 0;
                for (unsigned int i = u_column; i < size_of_str + u_column; i++)
                {
                    // std::cout << "txt[counter] : " << txt[counter] << endl;
                    matrix[u_row][i] = '~';
                    counter++;
                }
                // std::cout << "matrix[100][51] : " << matrix[100][51] << endl;
            }
            else if (dir == Direction::Vertical)
            {
                unsigned int size_of_str = length1;
                // std::cout << "size of str: " << size_of_str << endl;
                unsigned int counter = 0;
                for (unsigned int i = u_row; i < size_of_str + u_row; i++)
                {
                    // std::cout << "txt[counter]: " << txt[counter] << endl;
                    matrix[i][u_column] = '~';
                    // std::cout << "matrix[i][u_column]: " << matrix[i][u_column] << endl;
                    counter++;
                }
                it->second = matrix;
            }
        }
        else
        {
            // not found
            std::cout << "erase ::: $$ page not found :\n";
            // std::cout << "u_row:" << u_row << endl;
            vector<vector<char>> matrix(u_row, vector<char>(COL_AMOUNT, '_'));
            unsigned int resize_counter = matrix.size();
            while (matrix.size() <= u_row)
            {
                matrix.resize(matrix.size() * SAFTEY_ADD);
            }
            unsigned int resize_amount = matrix.size() - resize_counter;
            // std::cout << "dolev: " << matrix.size() << endl;
            for (unsigned int i = resize_counter - 1; i < matrix.size(); i++)
            {
                // std::cout << i << endl;
                matrix[i].resize(COL_AMOUNT, '_');
            }
            // std::cout << "dolev2: " << matrix[99].size() << endl;

            if (dir == Direction::Horizontal)
            {
                unsigned int size_of_str = length1;
                // cout << "size of str: " << size_of_str << endl;
                unsigned int counter = 0;
                for (unsigned int i = u_column; i < size_of_str + u_column; i++)
                {
                    // std::cout << "size: " << matrix.size() << endl;
                    if (matrix[u_row][i] != '_')
                    {
                        throw std::invalid_argument("index already taken ");
                    }
                    // std::cout << "txt[counter] : " << txt[counter] << endl;
                    matrix[u_row][i] ='~';
                    counter++;
                }
            }
            else if (dir == Direction::Vertical)
            {
                unsigned int size_of_str = length1;
                // std::cout << "size of str: " << size_of_str << endl;
                unsigned int counter = 0;
                for (unsigned int i = u_row; i < size_of_str + u_row; i++)
                {
                    // std::cout << "txt[counter]: " << txt[counter] << endl;
                    if (matrix[i][u_column] != '_')
                    {
                        throw std::invalid_argument("index already taken ");
                    }
                    matrix[i][u_column] = '~';
                    // std::cout << "matrix[i][u_column]: " << matrix[i][u_column] << endl;
                    counter++;
                }
            }
            std::cout << "finish write " << endl;
            my_notebook.insert(std::pair<int, vector<vector<char>>>(page, matrix));
        }
    }
    void Notebook::show(int page)
    {
        std::string output;
        map<int, vector<vector<char>>>::iterator it = my_notebook.find(page);
        if (it != my_notebook.end())
        {
            // found
            vector<vector<char>> matrix;
            matrix = it->second;
            for (unsigned int i = 0; i < matrix.size(); ++i)
            {
                // output = output + std::to_string(i);
                // output += ':';
                for (unsigned int j = 0; j < matrix[i].size(); ++j)
                {

                    output += matrix[i][j];
                }
                output += '\n';
            }
            cout << output << endl;
        }
        else
        {
            cout << "page not found" << endl;
        }
    }
}
