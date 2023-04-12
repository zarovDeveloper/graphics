#include "line.h"

line::line() //constructor
{

}


void line::draw(QImage &im) //drawing line
{
    QPainter painter(&im);
    QColor color;

    //set pen color
    int r, g, b, a;
    pen.getRGBA(r, g, b, a);

    color.setRgb(r, g, b, a);

    QPen qpen;
    qpen.setWidth(pen.getWidth());
    qpen.setColor(color);

    switch (pen.getStyle()) //set line style
    {
    case 0:
    {//choose No Pen(   )
        qpen.setStyle(Qt::NoPen);
        break;
    }
    case 1:
    {//choose solid line(------)
        qpen.setStyle(Qt::SolidLine);
        break;
    }
    case 2:
    {//choose dash line (- - - - - -)
        qpen.setStyle(Qt::DashLine);
        break;
    }
    case 3:
    {//choose dot line (.....)
        qpen.setStyle(Qt::DotLine);
        break;
    }
    case 4:
    {//choose dash and dot line(-.-.-.-.-)
        qpen.setStyle(Qt::DashDotLine);
        break;
    }
    case 5:
    {//choose dash dot dot line (-..-..-..-)
        qpen.setStyle(Qt::DashDotDotLine);
        break;
    }
    }

    //set pen in painter
    painter.setPen(qpen);

    //drawing line
    int x1, x2, y1, y2;
    start.getXY(x1, y1);
    end.getXY(x2,y2);
    painter.drawLine(x1, y1, x2, y2);
}
