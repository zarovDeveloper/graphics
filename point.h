#ifndef POINT_H
#define POINT_H


class point
{
public:
    point();

    //setter

    void setX(int newX);
    void setY(int newY);
    void setXY(int newX, int newY);

    //getter

    int getX(void);
    int getY(void);
    void getXY(int &tempX, int&tempY);


protected:

    //coord

    int x;
    int y;
};

#endif // POINT_H
