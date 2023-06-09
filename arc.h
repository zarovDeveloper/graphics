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

    bool setWidthAndHeight(int width, int height);

    bool setStartAngle(int angle);

    bool setDrawAngle(int angle);

    point start;

    pen pen;
    brush brush;

private:

    int width, height;

    int startAngle;

    int drawAngle;
};

#endif // ARC_H
