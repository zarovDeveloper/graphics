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

    void draw(QImage &im, int width);
};

#endif // PIXEL_H
