#include "Notebook.hpp"
constexpr int COL_LIMIT = 99;
constexpr int COL_AMOUNT = 100;
constexpr int SAFTEY_ADD = 10;

// hours wasted: 16
// used searches
// https://stackoverflow.com/questions/3136520/determine-if-map-contains-a-value-for-a-key
// https://stackoverflow.com/questions/65877299/wsign-conversion-error-when-getting-index-for-vector
// https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/
// https://stackoverflow.com/questions/191757/how-to-concatenate-a-stdstring-and-an-int
// https://stackoverflow.com/questions/4527686/how-to-update-stdmap-after-using-the-find-method

using namespace std;
namespace ariel
{

    void Notebook::write(int page, int row, int column, Direction dir, string const &txt)
    {

        unsigned int size_of_str1 = txt.size();
        unsigned int ucolumn = unsigned(column);
        if (column > COL_LIMIT || size_of_str1 + ucolumn > COL_LIMIT)
        {
            throw std::invalid_argument("column can't be greater that 99 , bad index");
        }
        map<int, vector<vector<char>>>::iterator it = my_notebook.find(page);
        unsigned int urow = unsigned(row);

        if (it != my_notebook.end())
        {
            // found
            std::cout << "page found :\n";
            vector<vector<char>> matrix;
            matrix = it->second;
            // std::cout << "matrix[100][51] : " << matrix[100][51] << endl;
            if (dir == Direction::Horizontal)
            {
                unsigned int size_of_str = txt.size();
                // cout << "size of str: " << size_of_str << endl;
                unsigned int counter = 0;
                for (unsigned int i = ucolumn; i < size_of_str + ucolumn; i++)
                {
                    // std::cout << "txt[counter] : " << txt[counter] << endl;
                    if (matrix[urow][i] != '_')
                    {
                        throw std::invalid_argument("index already taken ");
                    }
                    matrix[urow][i] = txt[counter];
                    counter++;
                }
                // std::cout << "matrix[100][51] : " << matrix[100][51] << endl;
            }
            else if (dir == Direction::Vertical)
            {
                unsigned int size_of_str = txt.size();
                // std::cout << "size of str: " << size_of_str << endl;
                unsigned int counter = 0;
                for (unsigned int i = urow; i < size_of_str + urow; i++)
                {
                    // std::cout << "txt[counter]: " << txt[counter] << endl;
                    if (matrix[i][ucolumn] != '_')
                    {
                        throw std::invalid_argument("index already taken ");
                    }
                    matrix[i][ucolumn] = txt[counter];
                    // std::cout << "matrix[i][ucolumn]: " << matrix[i][ucolumn] << endl;
                    counter++;
                }
                it->second = matrix;
            }
        }
        else
        {
            // not found
            std::cout << "page not found :\n";
            vector<vector<char>> matrix(urow , vector<char>(COL_AMOUNT, '_'));
            if (dir == Direction::Horizontal)
            {
                unsigned int size_of_str = txt.size();
                // cout << "size of str: " << size_of_str << endl;
                unsigned int counter = 0;
                for (unsigned int i = ucolumn; i < size_of_str + ucolumn; i++)
                {
                    if (matrix[urow][i] != '_')
                    {
                        throw std::invalid_argument("index already taken ");
                    }
                    // std::cout << "txt[counter] : " << txt[counter] << endl;
                    matrix[urow][i] = txt[counter];
                    counter++;
                }
            }
            else if (dir == Direction::Vertical)
            {
                unsigned int size_of_str = txt.size();
                // std::cout << "size of str: " << size_of_str << endl;
                unsigned int counter = 0;
                for (unsigned int i = urow; i < size_of_str + urow; i++)
                {
                    // std::cout << "txt[counter]: " << txt[counter] << endl;
                    if (matrix[i][ucolumn] != '_')
                    {
                        throw std::invalid_argument("index already taken ");
                    }
                    matrix[i][ucolumn] = txt[counter];
                    // std::cout << "matrix[i][ucolumn]: " << matrix[i][ucolumn] << endl;
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
        // std::vector<std::vector<char>> twoDimVector(3, std::vector<char>(2, '_'));
        // for (int i = 0; i < twoDimVector.size(); ++i)
        // {
        //     for (int j = 0; j < twoDimVector[i].size(); ++j)
        //     {
        //         output += twoDimVector[i][j];
        //     }
        //     output += '\n';
        // }
        // printf("%s", output.c_str());
        // vector<vector<char>> matrix(SAFTEY_ADD, vector<char>(COL_AMOUNT, '_'));

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
