#ifndef __IMG_HPP__
#define __IMG_HPP__
#include <fstream>

/// @brief  Simple img creator with @c char[] extracting it's own file format.
class Img
{
private:
    int width, height;
    std::string file_name;
    char **img;

public:
    Img(std::string file_name);
    int init();
    int const getWidth();
    int const getHeight();
    std::string const getFileName();
    ~Img();
};

#endif // __IMG_HPP__