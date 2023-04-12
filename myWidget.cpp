#include "myWidget.h"

myWidget::myWidget(QWidget *parent) : QWidget(parent) //constructor
{
    imCreated = false;
}


void myWidget::paintEvent(QPaintEvent *) //paint
{
    if (imCreated)
    {
        QPainter painter(this);
        painter.drawImage(0, 0, im);
    }
    else
        QMessageBox::information(this, "Ошибка", "Непредвиденная ошибка", QMessageBox::Ok);

}


void myWidget::createIm(int sizeX, int sizeY) //init image
{
    im = QImage(sizeX, sizeY, QImage::Format_ARGB32_Premultiplied);
    imCreated = true;
}

void myWidget::clear() //clear image
{
    im.fill(0);
    imCreated = true;
}
