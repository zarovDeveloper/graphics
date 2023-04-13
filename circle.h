#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"
#include "pen.h"
#include "brush.h"
#include <QImage>
#include <QPainter>

class circle : public point
{
public:
    circle();

    void draw(QImage &im);

    bool setRadius(int rad);

    pen pen;
    brush brush;

private:

    int radius;

};

#endif // CIRCLE_H
