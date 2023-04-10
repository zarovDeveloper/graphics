#ifndef RECT_H
#define RECT_H

#include "point.h"
#include "color.h"
#include <QImage>
#include <QPainter>

class rect : public color
{
public:
    rect();

    void draw(QImage &im);

    void setWidthAndHeight(int width, int height);

    void setWidthPen(int width);

    point start;

private:

    int w, h;

    int widthPen;
};

#endif // RECT_H
