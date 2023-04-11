#include "pen.h"

pen::pen() //конструктор
{
    width=1;
    style=1;
}

bool pen::setWidth(int n_width)
{
    width = n_width;
    return(1);
}

int pen::getWidth(void)
{
    return(width);
}

bool pen::setStyle(int n_style)
{
    style = n_style;
    return(1);
}

int pen::getStyle(void)
{
    return(style);
}
