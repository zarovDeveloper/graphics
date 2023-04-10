#include "rect.h"

rect::rect() //constructor
{

}

void rect::draw(QImage &im)
{
    QPainter painter(&im);
    QColor color;

    color.setRgb(red, green, blue, alpha);

    QPen pen;
    pen.setWidth(widthPen);
    pen.setColor(color);

    int x, y;
    start.getXY(x, y);

    painter.setPen(pen);

    painter.drawRect(x, y, w, h);
}

void rect::setWidthAndHeight(int width, int height)
{
    w = width;
    h = height;
}

void rect::setWidthPen(int width)
{
    widthPen = width;
}
