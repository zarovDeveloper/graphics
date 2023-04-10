#ifndef PIXEL_H
#define PIXEL_H

#include "point.h"
#include "color.h"
#include <QImage>
#include <QPainter>


class pixel : public point, public color
{
public:
    pixel();

    void draw(QImage &im);

    void setWidth(int width);

private:
    int w;
};

#endif // PIXEL_H
