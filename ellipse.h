#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "point.h"
#include "pen.h"
#include "brush.h"
#include <QImage>
#include <QPainter>

class ellipse : public point
{
public:
    ellipse();

    void draw(QImage &im);

    bool setRadAndRad1(int rad, int rad1);

    pen pen;
    brush brush;

private:

    int radius, radius1;

};

#endif // ELLIPSE_H
