#ifndef RECT_H
#define RECT_H

#include "pen.h"
#include "point.h"
#include "brush.h"
#include <QImage>
#include <QPainter>

class rect
{
public:
    rect();

    void draw(QImage &im);

    void setWidthAndHeight(int width, int height);

    point start;

    pen pen;
    brush brush;

private:

    int w, h;

};

#endif // RECT_H
