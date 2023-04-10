#include "pixel.h"

pixel::pixel()
{
    w = 1;
}

void pixel::draw(QImage &im)
{
    QPainter painter(&im);
    QColor color;

    color.setRgb(red, green, blue, alpha);

    QPen pen;
    pen.setWidth(w);
    pen.setColor(color);

    painter.setPen(pen);
    painter.drawPoint(x, y);
}

void pixel::setWidth(int width)
{
    w = width;
}
