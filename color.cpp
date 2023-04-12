#include "color.h"

color::color() //constructor
{
    //standart val
    red = 0;
    green = 0;
    blue = 0;
    alpha = 255;
}


//setter


bool color::setRGBA(int r, int g, int b, int a) //set RGBA
{
    if (r < 0 or g < 0 or b < 0 or a < 0 or r > 255 or g > 255 or b > 255 or a > 255) //check correct val
        return 0;

    red = r;
    green = g;
    blue = b;
    alpha = a;

    return 1;
}


//getter


void color::getRGBA(int &r, int &g, int &b, int &a) //get RGBA
{
    r = red;
    g = green;
    b = blue;
    a = alpha;
}
