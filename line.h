#ifndef LINE_H
#define LINE_H

#include "point.h"
#include "color.h"
#include <QImage>
#include <QPainter>

class line : public color
{
public:
    line();

    void draw(QImage &im, int width);

    point start;
    point end;
};

#endif // LINE_H
