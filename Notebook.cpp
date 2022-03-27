#include "Notebook.hpp"
constexpr int COL_LIMIT = 99;
constexpr int COL_AMOUNT = 100;
constexpr int SAFTEY_MUL = 3;
constexpr int SAFTEY_ADD = 5;
constexpr int NOT_VERTICAL = 0;
constexpr int DEFAULT_PAGE_SIZE = 0;

// hours wasted: 72
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

    void first_check(int page = 0, int row = 0, int column = 0)
    {
        if (page < 0 || row < 0 || column < 0)
        {
            throw std::invalid_argument("negative input ");
        }
    }
    void second_check(string const &txt, int column)
    {
        unsigned int size_of_str1 = txt.size();
        unsigned int u_column = unsigned(column);
        if (column > COL_LIMIT || size_of_str1 + u_column > COL_LIMIT)
        {
            throw std::invalid_argument("column can't be greater that 99 , bad index");
        }
    }

    void increase_page_size(vector<vector<char>> &matrix, string const &txt, Direction dir, unsigned int row)
    {
        unsigned int initial_mat_size = matrix.size();
        unsigned int resize_counter = matrix.size();
        unsigned int size_of_str = txt.size();
        unsigned int u_row = unsigned(row);
        unsigned int vertical_size = (dir == Direction::Vertical) ? size_of_str : NOT_VERTICAL;
        cout << "matrix.size() < (u_row - SAFTEY_ADD)" << matrix.size() << " < " << (u_row - SAFTEY_ADD) << endl;
        while (matrix.size() < (u_row + SAFTEY_ADD))
        {
            matrix.resize(matrix.size() * SAFTEY_MUL);
        }
        unsigned int resize_amount = matrix.size() - resize_counter;
        std::cout << "resize_amount : " << resize_amount << endl;
        for (size_t i = initial_mat_size - 1; i < initial_mat_size + resize_amount; i++)
        {
            matrix[i].resize(COL_AMOUNT, '_');
        }
    }

    void increase_page_size_read(vector<vector<char>> &matrix, unsigned int length, Direction dir, unsigned int row)
    {
        unsigned int initial_mat_size = matrix.size();
        unsigned int resize_counter = matrix.size();
        unsigned int size_of_str = length;
        unsigned int u_row = unsigned(row);
        unsigned int vertical_size = (dir == Direction::Vertical) ? size_of_str : NOT_VERTICAL;
        cout << "matrix.size() < (u_row - SAFTEY_ADD)" << matrix.size() << " < " << (u_row - SAFTEY_ADD) << endl;
        while (matrix.size() < (u_row + SAFTEY_ADD))
        {
            matrix.resize(matrix.size() * SAFTEY_MUL);
        }
        unsigned int resize_amount = matrix.size() - resize_counter;
        std::cout << "resize_amount : " << resize_amount << endl;
        for (size_t i = initial_mat_size - 1; i < initial_mat_size + resize_amount; i++)
        {
            matrix[i].resize(COL_AMOUNT, '_');
        }
    }

    void horizontal_direction_write_found(string const &txt, vector<vector<char>> &matrix, unsigned int u_column, unsigned int u_row)
    {
        unsigned int size_of_str = txt.size();
        unsigned int counter = 0;

        for (unsigned int i = u_column; i < size_of_str + u_column; i++)
        {
            if (matrix.at(u_row).at(i) != '_')
            {
                throw std::invalid_argument("index already taken ");
            }
            matrix.at(u_row).at(i) = txt[counter];
            counter++;
        }
    }

    void vertical_direction_write_found(string const &txt, vector<vector<char>> &matrix, unsigned int u_column, unsigned int u_row)
    {
        unsigned int size_of_str = txt.size();
        unsigned int counter = 0;
        for (unsigned int i = u_row; i < size_of_str + u_row; i++)
        {
            if (matrix[i][u_column] != '_')
            {
                throw std::invalid_argument("index already taken ");
            }
            matrix[i][u_column] = txt[counter];
            counter++;
        }
    }

    /*
     *
     *
     *
     *
     *
     *
     *
     *
     *
     */

    void Notebook::write(int page, int row, int column, Direction dir, string const &txt)
    {
        first_check(page, row, column);
        second_check(txt, column);
        unsigned int u_column = unsigned(column);
        unsigned int u_row = unsigned(row);
        map<int, vector<vector<char>>>::iterator it = my_notebook.find(page);
        if (it != my_notebook.end())
        {
            // found
            vector<vector<char>> matrix;
            matrix = it->second;
            increase_page_size(matrix, txt, dir, u_row);
            if (dir == Direction::Horizontal)
            {
                horizontal_direction_write_found(txt, matrix, u_column, u_row);
            }
            else if (dir == Direction::Vertical)
            {
                horizontal_direction_write_found(txt, matrix, u_column, u_row);
            }
            it->second = matrix;
        }
        else
        {
            // not found
            vector<vector<char>> matrix(u_row, vector<char>(COL_AMOUNT, '_'));
            increase_page_size(matrix, txt, dir, u_row);

            if (dir == Direction::Horizontal)
            {
                horizontal_direction_write_found(txt, matrix, u_column, u_row);
            }
            else if (dir == Direction::Vertical)
            {
                vertical_direction_write_found(txt, matrix, u_column, u_row);
            }
            my_notebook.insert(std::pair<int, vector<vector<char>>>(page, matrix));
        }
    }

    string Notebook::read(int page, int row, int column, Direction dir, int length)
    {
        first_check(page, row, column);
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
            increase_page_size_read(matrix, ulength, dir, u_row);
            if (dir == Direction::Horizontal)
                for (unsigned int i = u_column; i < u_column + ulength; i++)
                {
                    output += matrix[u_row][i];
                }
            else
            {
                for (unsigned int i = u_row; i < u_row + ulength; i++)
                {
                    output += matrix[i][u_column];
                }
            }
        }
        else
        {
            // not found
            vector<vector<char>> matrix(u_row, vector<char>(COL_AMOUNT, '_'));
            increase_page_size_read(matrix, ulength, dir, u_row);
            if (dir == Direction::Horizontal)
                for (unsigned int i = u_column; i < u_column + ulength; i++)
                {
                    output += matrix[u_row][i];
                }
            else
            {
                for (unsigned int i = u_row; i < u_row + ulength; i++)
                {
                    output += matrix[i][u_column];
                }
            }
        }
        return output;
    }

    void Notebook::erase(int page, int row, int column, Direction dir, int length)
    {
        first_check(page, row, column);
        unsigned int u_length = unsigned(length);
        unsigned int u_column = unsigned(column);
        unsigned int u_row = unsigned(row);
        map<int, vector<vector<char>>>::iterator it = my_notebook.find(page);

        if (it != my_notebook.end())
        {
            // found
            vector<vector<char>> matrix;
            matrix = it->second;
            increase_page_size_read(matrix, u_length, dir, u_row);

            if (dir == Direction::Horizontal)
            {
                unsigned int size_of_str = u_length;
                unsigned int counter = 0;
                for (unsigned int i = u_column; i < size_of_str + u_column; i++)
                {
                    matrix[u_row][i] = '~';
                    counter++;
                }
            }
            else if (dir == Direction::Vertical)
            {
                unsigned int size_of_str = u_length;
                unsigned int counter = 0;
                for (unsigned int i = u_row; i < size_of_str + u_row; i++)
                {
                    matrix[i][u_column] = '~';
                    counter++;
                }
                it->second = matrix;
            }
        }
        else
        {
            // not found
            vector<vector<char>> matrix(u_row, vector<char>(COL_AMOUNT, '_'));
            increase_page_size_read(matrix, u_length, dir, u_row);
            if (dir == Direction::Horizontal)
            {
                unsigned int size_of_str = u_length;
                unsigned int counter = 0;
                for (unsigned int i = u_column; i < size_of_str + u_column; i++)
                {
                    if (matrix[u_row][i] != '_')
                    {
                        throw std::invalid_argument("index already taken ");
                    }
                    matrix[u_row][i] = '~';
                    counter++;
                }
            }
            else if (dir == Direction::Vertical)
            {
                unsigned int size_of_str = u_length;
                unsigned int counter = 0;
                for (unsigned int i = u_row; i < size_of_str + u_row; i++)
                {
                    if (matrix[i][u_column] != '_')
                    {
                        throw std::invalid_argument("index already taken ");
                    }
                    matrix[i][u_column] = '~';
                    counter++;
                }
            }
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
            vector<vector<char>> matrix(DEFAULT_PAGE_SIZE, vector<char>(COL_AMOUNT, '_'));
            for (unsigned int i = 0; i < matrix.size(); ++i)
            {
                for (unsigned int j = 0; j < matrix[i].size(); ++j)
                {
                    output += matrix[i][j];
                }
                output += '\n';
            }
            cout << output << endl;
            my_notebook.insert(std::pair<int, vector<vector<char>>>(page, matrix));
        }
    }

}
