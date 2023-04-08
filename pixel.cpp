#include "pixel.h"

pixel::pixel()
{

}

void pixel::draw(QImage &im, int width)
{
    QPainter painter(&im);
    QColor color;

    color.setRgb(red, green, blue, alpha);

    QPen pen;
    pen.setWidth(width);
    pen.setColor(color);

    painter.setPen(pen);
    painter.drawPoint(x, y);
}
