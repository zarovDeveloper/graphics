#ifndef ARC_H
#define ARC_H

#include "point.h"
#include "color.h"
#include <QImage>
#include <QPainter>

class arc : public color
{
public:
    arc();

    void draw(QImage &im);

    void setWidthAndHeight(int width, int height);

    void setStartAngle(int angle);

    void setDrawAngle(int angle);

    void setWidthPen(int width);

    point start;

private:

    int width, height;

    int widthPen;

    int startAngle;

    int drawAngle;
};

#endif // ARC_H
