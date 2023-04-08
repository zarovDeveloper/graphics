#include "line.h"

line::line() //constructor
{

}


void line::draw(QImage &im, int width)
{
    QPainter painter(&im);
    QColor color;

    color.setRgb(red, green, blue, alpha);

    QPen pen;
    pen.setWidth(width);
    pen.setColor(color);

    painter.setPen(pen);
    int x1, x2, y1, y2;
    start.getXY(x1, y1);
    end.getXY(x2,y2);
    painter.drawLine(x1, y1, x2, y2);
}
