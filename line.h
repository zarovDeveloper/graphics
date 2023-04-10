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

    void draw(QImage &im);

    point start;
    point end;

    void setWidth(int width);


private:

    int w;
};

#endif // LINE_H
