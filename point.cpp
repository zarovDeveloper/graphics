#include "point.h"

point::point() //constructor
{
    //init values
    x = 0;
    y = 0;
}


//setter


void point::setX(int newX)
{
    x = newX;
}

void point::setY(int newY)
{
    y = newY;
}

void point::setXY(int newX, int newY)
{
    x = newX;
    y = newY;
}


//getter


int point::getX(void)
{
    return x;
}

int point::getY(void)
{
    return y;
}

void point::getXY(int &tempX, int &tempY)
{
    tempX = x;
    tempY = y;
}
