#include "pen.h"

pen::pen() //конструктор
{
    //standart val
    width=1;
    style=1;
}


//setter


bool pen::setWidth(int n_width) //set width
{
    if (n_width < 0 or n_width > 100) //check correct val
        return 0;

    width = n_width;
    return(1);
}

bool pen::setStyle(int n_style) //set style
{
    if (n_style < 0 or n_style > 7) //check correct val
        return 0;

    style = n_style;
    return(1);
}


//getter


int pen::getWidth(void) //get width
{
    return(width);
}

int pen::getStyle(void) //get style
{
    return(style);
}
