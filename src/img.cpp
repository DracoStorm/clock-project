#include "Img.hpp"

int to_num(char str_num[3])
{
    if (str_num[0] < 48 || str_num[0] > 58)
    {
        return INT_MIN;
    }
    if (str_num[1] < 48 || str_num[1] > 58)
    {
        return INT_MIN;
    }
    return (str_num[0] - 48) * 10 + (str_num[1] - 48);
}

Img::Img(std::string file_name)
{
    width = height = 0;
    this->file_name = file_name;
    img = nullptr;
}

/**
 *  @brief  Initialice the @c Img with the given file.
 *  @return booleam if the format of the file is correct.
 *
 *  Calls @c std::fstream(__file_name) extracing the characters, the flag indicates an error in the format.
 *  If the char img is set incorrectly it din't appear. All of the array is the heap.
 */
bool Img::init()
{
    std::fstream file;
    file.open(file_name);
    char c;
    file >> c;
    if (c == 'W')
    {
        file >> c;
        if (c == ':')
        {
            char str_num[3] = {file.get(), file.get(), file.get()};
            int num = to_num(str_num);
            if (num == INT_MIN)
                return false;
            width = num + 1;
        }
        else
            return false;
    }
    else
        return false;
    file >> c;
    if (c == 'H')
    {
        file >> c;
        if (c == ':')
        {
            char str_num[3] = {file.get(), file.get(), file.get()};
            int num = to_num(str_num);
            if (num == INT_MIN)
                return 1;
            height = num;
        }
        else
            return false;
    }
    else
        return false;

    char *cols[height];
    for (int i = 0; i < height; i++)
    {
        cols[i] = new char[width];
        file.getline(cols[i], width);
    }
    img = cols;
    return true;
}

int const Img::getWidth()
{
    return width;
}

int const Img::getHeight()
{
    return height;
}

std::string const Img::getFileName()
{
    return file_name;
}

Img::~Img()
{
    delete[] img;
}