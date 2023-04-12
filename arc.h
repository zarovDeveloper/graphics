#ifndef ARC_H
#define ARC_H

#include "point.h"
#include "pen.h"
#include "brush.h"
#include <QImage>
#include <QPainter>

class arc
{
public:
    arc();

    void draw(QImage &im);

    void setWidthAndHeight(int width, int height);

    void setStartAngle(int angle);

    void setDrawAngle(int angle);

    point start;

    pen pen;
    brush brush;

private:

    int width, height;

    int startAngle;

    int drawAngle;
};

#endif // ARC_H
