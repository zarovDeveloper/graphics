#include "rect.h"

rect::rect() //constructor
{
    //standart value
    w = 0;
    h = 0;
}

void rect::draw(QImage &im) //draw rect
{
    QPainter painter(&im);
    QColor color;
    QPen qpen;
    QBrush qbrush;


    //set pen color
    int r, g, b, a;
    pen.getRGBA(r, g, b, a);

    color.setRgb(r, g, b, a);

    qpen.setWidth(pen.getWidth());
    qpen.setColor(color);

    switch (pen.getStyle()) //choose line style
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

    //set brush color
    brush.getRGBA(r, g, b, a);
    color.setRgb(r, g, b, a);

    qbrush.setColor(color);
    switch (brush.getStyle()) //choose brush style
    {
    case 0:
    {//choose no brush
        qbrush.setStyle(Qt::NoBrush);
        break;
    }
    case 1:
    {//choose solid brush
        qbrush.setStyle(Qt::SolidPattern);
        break;
    }
    case 2:
    {//choose hor brush
        qbrush.setStyle(Qt::HorPattern);
        break;
    }
    case 3:
    {//chose ver brush
        qbrush.setStyle(Qt::VerPattern);
        break;
    }
    case 4:
    {//choose cross brush
        qbrush.setStyle(Qt::CrossPattern);
        break;
    }
    case 5:
    {//choose diagonal cross brush
        qbrush.setStyle(Qt::DiagCrossPattern);
        break;
    }
    }

    //set pen and brush in painter
    painter.setPen(qpen);
    painter.setBrush(qbrush);

    //drawing rect
    int x, y, x1, y1;
    start.getXY(x, y);
    end.getXY(x1, y1);

    w = abs(x1 - x);
    h = abs(y1 - y);

    painter.drawRect(x, y, w, h);
}
