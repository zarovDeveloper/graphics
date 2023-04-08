#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) //constructor
{
    ui->setupUi(this);

    ui->widget->createIm(ui->widget->width(), ui->widget->height()); //set standard settings

    settings(); //settings
}

MainWindow::~MainWindow()
{
    delete ui;
}


//button


void MainWindow::on_pushButton_draw_clicked() //button "Рисовать"
{
    switch (ui->comboBox_option->currentIndex())
    {
    case 0: //pixel
    {
        int x = ui->spinBox_inputX_1->value();
        int y = ui->spinBox_inputY_1->value();

        int width = ui->spinBox_inputWidth->value();
        pixel pixel;

        int a, r, g, b;
        QColor color;

        color = QColorDialog::getColor();

        if (color.isValid())
        {//if choose OK in color dialog menu
            color.getRgb(&r, &g, &b, &a);
            pixel.setRGBA(r, g, b, a);

            pixel.setXY(x, y);
            pixel.draw(ui->widget->im, width);
            update();
        }

        break;
    }
    case 1: //line
    {
        //init val
        line line;

        //init coord
        int x1 = ui->spinBox_inputX_1->value();
        int y1 = ui->spinBox_inputY_1->value();
        int x2 = ui->spinBox_inputX_2->value();
        int y2 = ui->spinBox_inputY_2->value();

        int width = ui->spinBox_inputWidth->value();

        //init color
        int a, r, g, b;
        QColor color;

        color = QColorDialog::getColor();

        if (color.isValid())
        {//if choose OK in color dialog menu
            color.getRgb(&r, &g, &b, &a);
            line.setRGBA(r, g, b, a);

            //set coord in line
            line.start.setXY(x1, y1);
            line.end.setXY(x2, y2);
            line.draw(ui->widget->im, width);
            update();
        }

        break;
    }
    }
}

void MainWindow::on_pushButton_clear_clicked() //button "Отчистить"
{//clear widget
    ui->widget->clear();
    update();
}


//settings


void MainWindow::settings()
{
    //remove arrows
    ui->spinBox_inputX_1->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->spinBox_inputY_1->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->spinBox_inputX_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->spinBox_inputY_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->spinBox_inputWidth->setButtonSymbols(QAbstractSpinBox::NoButtons);

    //set range
    ui->spinBox_inputX_1->setRange(0, 1060);
    ui->spinBox_inputY_1->setRange(0, 660);
    ui->spinBox_inputX_2->setRange(0, 1060);
    ui->spinBox_inputY_2->setRange(0, 660);
    ui->spinBox_inputWidth->setRange(1, 100);

    //hide extra lines
    ui->label_inputX_2->setVisible(false);
    ui->label_inputY_2->setVisible(false);
    ui->spinBox_inputX_2->setVisible(false);
    ui->spinBox_inputY_2->setVisible(false);
}

void MainWindow::on_comboBox_option_currentIndexChanged(int index) //hide extra lines
{
    if (index == 0) //choose pixel
    {
        ui->label_inputX_1->setVisible(true);
        ui->label_inputY_1->setVisible(true);
        ui->spinBox_inputX_1->setVisible(true);
        ui->spinBox_inputY_1->setVisible(true);

        ui->label_inputX_2->setVisible(false);
        ui->label_inputY_2->setVisible(false);
        ui->spinBox_inputX_2->setVisible(false);
        ui->spinBox_inputY_2->setVisible(false);
    }
    else if (index == 1) //choose line
    {
        ui->label_inputX_1->setVisible(true);
        ui->label_inputY_1->setVisible(true);
        ui->spinBox_inputX_1->setVisible(true);
        ui->spinBox_inputY_1->setVisible(true);

        ui->label_inputX_2->setVisible(true);
        ui->label_inputY_2->setVisible(true);
        ui->spinBox_inputX_2->setVisible(true);
        ui->spinBox_inputY_2->setVisible(true);
    }

}
