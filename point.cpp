#include "point.h"

point::point() //constructor
{
    //init values
    x = 0;
    y = 0;
}


//setter


bool point::setX(int newX) //set X
{
    if (newX < 0 or newX > 10000)
        return 0;

    x = newX;
    return 1;
}

bool point::setY(int newY) //set Y
{
    if (newY < 0 or newY > 10000)
        return 0;

    y = newY;
    return 1;
}

bool point::setXY(int newX, int newY) //set X and Y
{
    if (newY < 0 or newY > 10000 or newX < 0 or newX > 10000)
        return 0;

    x = newX;
    y = newY;
    return 1;
}


//getter


int point::getX(void) //get X
{
    return x;
}

int point::getY(void) //get Y
{
    return y;
}

void point::getXY(int &tempX, int &tempY) //get X and Y
{
    tempX = x;
    tempY = y;
}
