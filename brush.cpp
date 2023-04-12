#include "brush.h"

brush::brush() //constructor
{
    //standart value
    style = 0;
}


//setter


bool brush::setStyle(int n_style) //set style brush
{
    if (n_style < 0 or n_style > 7) //check correct val
        return 0;

    style = n_style;
    return(1);
}


//getter


int brush::getStyle(void) //get style brush
{
    return(style);
}
