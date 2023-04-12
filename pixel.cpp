#include "pixel.h"

pixel::pixel() //constructor
{
    //standart val
    w = 1;
}

void pixel::draw(QImage &im) //draw pixel
{
    QPainter painter(&im);
    QColor color;
    QPen pen;

    //set pen color
    color.setRgb(red, green, blue, alpha);
    pen.setWidth(w);
    pen.setColor(color);

    //set pen in painter
    painter.setPen(pen);

    //drawing point
    painter.drawPoint(x, y);
}


//setter


bool pixel::setWidth(int width) //set width
{
    if (width < 0 or w > 100)
        return 0;

    w = width;
    return 1;
}
