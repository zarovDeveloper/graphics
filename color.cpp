#include "color.h"

color::color() //constructor
{
    //init val
    red = 0;
    green = 0;
    blue = 0;
    alpha = 255;
}

//setter

bool color::setRGBA(int r, int g, int b, int a)
{
    red = r;
    green = g;
    blue = b;
    alpha = a;

    return 1;
}

//getter

void color::getRGBA(int &r, int &g, int &b, int &a)
{
    r = red;
    g = green;
    b = blue;
    a = alpha;
}
