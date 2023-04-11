#ifndef BRUSH_H
#define BRUSH_H

#include "color.h"


class brush : public color
{
public:
    brush();

    bool setStyle(int n_style);
    int getStyle(void);

protected:
    int style;
};

#endif // BRUSH_H
