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

        double width = ui->spinBox_inputWidth->value();
        pixel pixel;


        if ((x + width / 2 > ui->widget->width()) or (x - width / 2 < 0) or (y + width / 2 > ui->widget->height()) or (y - width / 2 < 0)) //if print out of range
        {
            //notification generation
            QMessageBox msgBox;
            msgBox.setWindowTitle("Ошибка");
            msgBox.setText("Рисунок выйдет за границы поля.\nВы хотите продолжить?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::Yes);
            int res = msgBox.exec();
            switch (res)
            {//check push button
            case QMessageBox::Yes:
            {//push button yes
                int a, r, g, b;
                QColor color;

                color = QColorDialog::getColor();

                if (color.isValid())
                {//if choose OK in color dialog menu
                    color.getRgb(&r, &g, &b, &a);
                    pixel.setRGBA(r, g, b, a);

                    pixel.setXY(x, y);
                    pixel.draw(ui->widget->im, int(width));
                    update();
                }
                break;
            }
            case QMessageBox::No:
            {
                break;
            }
            }
        }
        else
        {
            int a, r, g, b;
            QColor color;

            color = QColorDialog::getColor();

            if (color.isValid())
            {//if choose OK in color dialog menu
                color.getRgb(&r, &g, &b, &a);
                pixel.setRGBA(r, g, b, a);

                pixel.setXY(x, y);
                pixel.draw(ui->widget->im, int(width));
                update();
            }
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

        double width = ui->spinBox_inputWidth->value();

        if ((x1 + width / 2 > ui->widget->width()) or (x1 - width / 2 < 0) or (y1 + width / 2 > ui->widget->height()) or (y1 - width / 2 < 0) or (x2 + width / 2 > ui->widget->width()) or (x2 - width / 2 < 0) or (y2 + width / 2 > ui->widget->height()) or (y2 - width / 2 < 0))
        {//if print out of range
            //notification generation
            QMessageBox msgBox;
            msgBox.setWindowTitle("Ошибка");
            msgBox.setText("Рисунок выйдет за границы поля.\nВы хотите продолжить?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::Yes);
            int res = msgBox.exec();
            switch (res)
            {//check push button
            case QMessageBox::Yes:
            {//push button yes
                int a, r, g, b;
                QColor color;

                color = QColorDialog::getColor();

                if (color.isValid())
                {//if choose OK in color dialog menu
                    color.getRgb(&r, &g, &b, &a);
                    line.setRGBA(r, g, b, a);

                    line.start.setXY(x1, y1);
                    line.end.setXY(x2, y2);
                    line.draw(ui->widget->im, int(width));
                    update();
                }
                break;
            }
            case QMessageBox::No:
            {
                break;
            }
            }
        }
        else
        {
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
                line.draw(ui->widget->im, int(width));
                update();
            }
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
