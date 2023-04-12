#ifndef POINT_H
#define POINT_H


class point
{
public:
    point();

    //setter

    bool setX(int newX);
    bool setY(int newY);
    bool setXY(int newX, int newY);

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
