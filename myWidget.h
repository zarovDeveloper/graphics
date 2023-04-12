#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMessageBox>

class myWidget : public QWidget
{
    Q_OBJECT
public:
    explicit myWidget(QWidget *parent = nullptr);

    QImage im;

    void createIm(int sizeX, int sizeY);

    void clear();

private:

    bool imCreated;

signals:

public slots:


protected:

    void paintEvent(QPaintEvent *);
};

#endif // MYWIDGET_H
