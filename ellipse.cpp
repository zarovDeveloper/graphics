#include "ellipse.h"

ellipse::ellipse() //constructor
{
    //standart val
    radius = 0;
    radius1 = 0;
}


void ellipse::draw(QImage &im) //draw ellipse
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

    switch (pen.getStyle()) //choose style line
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
    switch (brush.getStyle()) //choose style brush
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

    //set pen and brush
    painter.setPen(qpen);
    painter.setBrush(qbrush);

    //drawing ellipse
    int x, y;
    getXY(x, y);
    painter.drawEllipse(x, y, radius * 2, radius1 * 2);
}


//setter


bool ellipse::setRadAndRad1(int r, int r1) //set width and height in ellipse
{
    if (r < 0 or r1 < 0 or r > 10000 or r1 > 1000) //check correct val
        return 0;

    radius = r;
    radius1 = r1;
    return 1;
}


