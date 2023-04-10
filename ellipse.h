#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "point.h"
#include "color.h"
#include <QImage>
#include <QPainter>

class ellipse : public color
{
public:
    ellipse();

    void draw(QImage &im);

    void setWidthAndHeight(int width, int height);

    void setWidthPen(int width);

    point start;

private:

    int width, height;

    int widthPen;
};

#endif // ELLIPSE_H
