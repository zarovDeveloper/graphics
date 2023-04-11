#include "arc.h"

arc::arc()
{

}

void arc::draw(QImage &im)
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


void arc::setWidthAndHeight(int w, int h)
{
    width = w;
    height = h;
}

void arc::setWidthPen(int width)
{
    widthPen = width;
}

void arc::setStartAngle(int angle)
{
    startAngle = angle;
}

void arc::setDrawAngle(int angle)
{
    drawAngle = angle;
}
