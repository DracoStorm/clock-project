#ifndef __SCREEN_HPP__
#define __SCREEN_HPP__
#include "Img.hpp"

class Screen
{
private:
    char **screen;
    int width, height;

public:
    Screen(int width, int height);
    void draw(Img img);
    void frame(char character);
    void clear();
    ~Screen();
};

#endif // __SCREEN_HPP__