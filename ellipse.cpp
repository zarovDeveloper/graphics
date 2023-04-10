#include "ellipse.h"

ellipse::ellipse()
{
    widthPen = 1;
    width = 0;
    height = 0;
}


void ellipse::draw(QImage &im)
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

    painter.drawEllipse(x, y, width, height);
}


void ellipse::setWidthAndHeight(int w, int h)
{
    width = w;
    height = h;
}

void ellipse::setWidthPen(int width)
{
    widthPen = width;
}
