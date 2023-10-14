#include "Screen.hpp"

Screen::Screen(int width, int height)
{
    this->width = width;
    this->height = height;
    screen = new char *[height];
    for (int i = 0; i < height; i++)
    {
        screen[i] = new char[width + 1];
    }
    for (int i = 0; i < height; i++)
    {
        screen[i][width] = '\0';
    }
}

const int Screen::getWidth()
{
    return width;
}

const int Screen::getHeigh()
{
    return height;
}

void Screen::place(const Img &img, int x, int y)
{
    if ((x + img.width > width || y + img.height > height) && (x + img.width <= 0 || y + img.height <= 0))
    {
        return;
    }

    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.width; j++)
        {
            screen[i + y][j + x] = img.img[i][j];
        }
    }
}

void Screen::frame(char character)
{
    for (int i = 0; i < width; i++)
    {
        screen[0][i] = character;
    }

    for (int i = 0; i < width; i++)
    {
        screen[height - 1][i] = character;
    }

    for (int i = 1; i < height - 1; i++)
    {
        screen[i][0] = character;
        screen[i][width - 1] = character;
    }
}

void Screen::unflip()
{
    for (int i = 0; i < height; i++)
    {
        std::cout << screen[i] << std::endl;
    }
}

void Screen::clear()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            screen[i][j] = ' ';
        }
    }
}

Screen::~Screen()
{
    // destructor
}
