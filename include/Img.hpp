#ifndef __IMG_HPP__
#define __IMG_HPP__
#include <fstream>

/// @brief  Simple img creator with @c char[] extracting it's own file format.
class Img
{
    friend class Screen;

private:
    int width, height;
    std::string file_name;
    char **img;

public:
    Img(std::string file_name);
    bool init();
    const int getWidth();
    const int getHeight();
    const std::string getFileName();
    ~Img();
};

#endif // __IMG_HPP__