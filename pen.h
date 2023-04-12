#ifndef MPEN_H
#define MPEN_H

#include "color.h"


class pen : public color
{
public:
    pen();
    bool setWidth(int n_width);

    int getWidth(void);

    bool setStyle(int n_style);

    int getStyle(void);

protected:
    int width;
    int style;
};

#endif // MPEN_H
