#ifndef __IMG_HPP__
#define __IMG_HPP__
#include <fstream>

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