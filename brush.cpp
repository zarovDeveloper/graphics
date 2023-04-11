#include "brush.h"

brush::brush()
{
    style = 0;
}

bool brush::setStyle(int n_style)
{
    //ПРОВЕРКИ
    style=n_style;
    return(true);
}
int brush::getStyle(void)
{
    return(style);
}
