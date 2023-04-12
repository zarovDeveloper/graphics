#include "arc.h"

arc::arc() //constructor
{
    //standart value
    width = 0;
    height = 0;
    startAngle = 0;
    drawAngle = 0;
}


void arc::draw(QImage &im) //draw arc
{
    //create
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

    switch (pen.getStyle()) //style line
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
    switch (brush.getStyle()) //style brush
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

    //set brush and pen in painter
    painter.setPen(qpen);
    painter.setBrush(qbrush);

    //drawing arc
    int x, y;
    start.getXY(x, y);
    painter.drawArc(x, y, width, height, startAngle, drawAngle);
}


//setter


bool arc::setWidthAndHeight(int w, int h) //set width and height in arc
{
    if (w > 1060 or h > 800 or w < 0 or h < 0) //check correct val
        return 0;

    width = w;
    height = h;
    return 1;

}

bool arc::setStartAngle(int angle) //set start angle in arc
{
    if (angle > 360 or angle < 0) //check correct val
        return 0;

    startAngle = angle;
    return 1;

}

bool arc::setDrawAngle(int angle) //set draw angle in arc
{
    if (angle > 360 or angle < -360) //check correct val
        return 0;

    drawAngle = angle * 16;
    return 1;

}
