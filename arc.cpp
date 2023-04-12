#include "arc.h"

arc::arc()
{

}

void arc::draw(QImage &im)
{
    QPainter painter(&im);
    QColor color;
    QPen qpen;
    QBrush qbrush;

    int r, g, b, a;
    pen.getRGBA(r, g, b, a);

    color.setRgb(r, g, b, a);

    qpen.setWidth(pen.getWidth());
    qpen.setColor(color);

    switch (pen.getStyle())
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

    brush.getRGBA(r, g, b, a);
    color.setRgb(r, g, b, a);

    qbrush.setColor(color);
    switch (brush.getStyle())
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

    painter.setPen(qpen);
    painter.setBrush(qbrush);

    int x, y;
    start.getXY(x, y);
    painter.drawArc(x, y, width, height, startAngle, drawAngle);
}


void arc::setWidthAndHeight(int w, int h)
{
    width = w;
    height = h;
}

void arc::setStartAngle(int angle)
{
    startAngle = angle;
}

void arc::setDrawAngle(int angle)
{
    drawAngle = angle * 16;
}
