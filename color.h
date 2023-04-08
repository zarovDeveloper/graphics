#ifndef COLOR_H
#define COLOR_H


class color
{
public:
    color();

    //setter

    bool setRGBA(int red, int green, int blue, int alpha);

    //getter

    void getRGBA(int &red, int &green, int &blue, int &alpha);


protected:

    //RGB

    int red;
    int green;
    int blue;

    //Transparency

    int alpha;
};

#endif // COLOR_H
