#ifndef LINE_H
#define LINE_H

#include "point.h"
#include "pen.h"
#include <QImage>
#include <QPainter>

class line
{
public:
    line();

    void draw(QImage &im);

    point start;
    point end;

    pen pen;
};

#endif // LINE_H
