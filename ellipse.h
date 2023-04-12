#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "point.h"
#include "pen.h"
#include "brush.h"
#include <QImage>
#include <QPainter>

class ellipse
{
public:
    ellipse();

    void draw(QImage &im);

    void setWidthAndHeight(int width, int height);

    point start;

    pen pen;
    brush brush;

private:

    int width, height;

};

#endif // ELLIPSE_H
