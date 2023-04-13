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
                QColor color = QColorDialog::getColor(Qt::white, nullptr, "Цвет точки");

                if (color.isValid())
                {//if choose OK in color dialog menu
                    color.getRgb(&r, &g, &b, &a);
                    pixel.setRGBA(r, g, b, a);

                    pixel.setXY(x, y);

                    pixel.setWidth(int(width));
                    pixel.draw(ui->widget->im);
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
            QColor color = QColorDialog::getColor(Qt::white, nullptr, "Цвет точки");

            if (color.isValid())
            {//if choose OK in color dialog menu
                color.getRgb(&r, &g, &b, &a);
                pixel.setRGBA(r, g, b, a);

                pixel.setXY(x, y);

                pixel.setWidth(int(width));
                pixel.draw(ui->widget->im);

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
        int styleLine = ui->comboBox_styleLine->currentIndex();

        if (styleLine)
        {
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

                    //init color
                    int a, r, g, b;

                    QColor color = QColorDialog::getColor(Qt::white, nullptr, "Цвет линии");

                    if (color.isValid())
                    {//if choose OK in color dialog menu
                        color.getRgb(&r, &g, &b, &a);
                        a = 255;
                        line.pen.setRGBA(r, g, b, a);
                        line.pen.setWidth(int(width));
                        line.pen.setStyle(styleLine);

                        //set coord in line
                        line.start.setXY(x1, y1);
                        line.end.setXY(x2, y2);

                        line.draw(ui->widget->im);
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

                color = QColorDialog::getColor(Qt::white, nullptr, "Цвет линии");

                if (color.isValid())
                {//if choose OK in color dialog menu
                    color.getRgb(&r, &g, &b, &a);
                    a = 255;
                    line.pen.setRGBA(r, g, b, a);
                    line.pen.setWidth(int(width));
                    line.pen.setStyle(styleLine);

                    //set coord in line
                    line.start.setXY(x1, y1);
                    line.end.setXY(x2, y2);

                    line.draw(ui->widget->im);
                    update();
                }

            }
            break;
        }
        break;
    }
    case 2: //rect
    {
        //val
        class rect rect;

        //init coord, width and height
        int x = ui->spinBox_inputX_1->value();
        int y = ui->spinBox_inputY_1->value();
        int x1 = ui->spinBox_inputX_2->value();
        int y1 = ui->spinBox_inputY_2->value();

        double widthPen = ui->spinBox_inputWidth->value(); //init width pen
        int styleLine = ui->comboBox_styleLine->currentIndex();
        int styleBrush = ui->comboBox_styleBrush->currentIndex();

        if ((styleLine) or (styleBrush))
        {
            if ((x + x1 > ui->widget->width()) or (y + y1 > ui->widget->height()) or (x + x1 / 2 > ui->widget->width()) or (x - x1 / 2 < 0) or (y + x1 / 2 > ui->widget->height()) or (y - x1 / 2 < 0))
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
                    //init color
                    bool error = 0;

                    if (styleLine)
                    {
                        int a = 255, r, g, b;
                        QColor color = QColorDialog::getColor(Qt::white, nullptr, "Цвет линии");
                        if (color.isValid())
                        {
                            color.getRgb(&r, &g, &b, &a);
                            rect.pen.setRGBA(r, g, b, a);
                            rect.pen.setWidth(int(widthPen));
                            rect.pen.setStyle(styleLine);
                        }
                        else
                            error = 1;
                    }

                    if (styleBrush)
                    {
                        int a = 255, r, g, b;
                        QColor color = QColorDialog::getColor(Qt::white, nullptr, "Цвет заливки");
                        if (color.isValid())
                        {
                            color.getRgb(&r, &g, &b, &a);
                            rect.brush.setRGBA(r, g, b, a);
                            rect.brush.setStyle(styleBrush);
                        }
                        else
                            error = 1;
                    }


                    if (!error)
                    {
                        rect.start.setXY(x, y); //set left top coord in rect
                        rect.end.setXY(x1, y1); //set right buttom coord in rect

                        rect.draw(ui->widget->im);
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
                bool error = 0;

                if (styleLine)
                {
                    int a = 255, r, g, b;
                    QColor color = QColorDialog::getColor(Qt::white, nullptr, "Цвет линии");
                    if (color.isValid())
                    {
                        color.getRgb(&r, &g, &b, &a);
                        rect.pen.setRGBA(r, g, b, a);
                        rect.pen.setWidth(int(widthPen));
                        rect.pen.setStyle(styleLine);
                    }
                    else
                        error = 1;
                }

                if (styleBrush)
                {
                    int a = 255, r, g, b;
                    QColor color = QColorDialog::getColor(Qt::white, nullptr, "Цвет заливки");
                    if (color.isValid())
                    {
                        color.getRgb(&r, &g, &b, &a);
                        rect.brush.setRGBA(r, g, b, a);
                        rect.brush.setStyle(styleBrush);
                    }
                    else
                        error = 1;
                }


                if (!error)
                {
                    rect.start.setXY(x, y); //set left top coord in rect
                    rect.end.setXY(x1, y1); //set right buttom coord in rect

                    rect.draw(ui->widget->im);
                    update();
                }
            }
        }
        break;
    }
    case 3: //ellipse
    {
        //val
        ellipse ellipse;
        //init coord, width and height
        int x = ui->spinBox_inputX_1->value();
        int y = ui->spinBox_inputY_1->value();
        int rad = ui->spinBox_inputX_2->value();
        int rad1 = ui->spinBox_inputY_2->value();

        double widthPen = ui->spinBox_inputWidth->value(); //init width pen
        int styleLine = ui->comboBox_styleLine->currentIndex();
        int styleBrush = ui->comboBox_styleBrush->currentIndex();

        if ((styleLine) or (styleBrush))
        {
            if ((x + rad > ui->widget->width()) or (y + rad1 > ui->widget->height()) or (x + rad / 2 > ui->widget->width()) or (x - rad / 2 < 0) or (y + rad / 2 > ui->widget->height()) or (y - rad / 2 < 0))
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
                    //init color
                    bool error = 0;

                    if (styleLine)
                    {
                        int a = 255, r, g, b;
                        QColor color = QColorDialog::getColor(Qt::white, nullptr, "Цвет линии");
                        if (color.isValid())
                        {
                            color.getRgb(&r, &g, &b, &a);
                            ellipse.pen.setRGBA(r, g, b, a);
                            ellipse.pen.setWidth(int(widthPen));
                            ellipse.pen.setStyle(styleLine);
                        }
                        else
                            error = 1;
                    }

                    if (styleBrush)
                    {
                        int a = 255, r, g, b;
                        QColor color = QColorDialog::getColor(Qt::white, nullptr, "Цвет заливки");
                        if (color.isValid())
                        {
                            color.getRgb(&r, &g, &b, &a);
                            ellipse.brush.setRGBA(r, g, b, a);
                            ellipse.brush.setStyle(styleBrush);
                        }
                        else
                            error = 1;
                    }


                    if (!error)
                    {
                        ellipse.setXY(x, y); //set coord in rect
                        ellipse.setRadAndRad1(rad, rad1); //set width and height rect

                        ellipse.draw(ui->widget->im);
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
                bool error = 0;

                if (styleLine)
                {
                    int a = 255, r, g, b;
                    QColor color = QColorDialog::getColor(Qt::white, nullptr, "Цвет линии");
                    if (color.isValid())
                    {
                        color.getRgb(&r, &g, &b, &a);
                        ellipse.pen.setRGBA(r, g, b, a);
                        ellipse.pen.setWidth(int(widthPen));
                        ellipse.pen.setStyle(styleLine);
                    }
                    else
                        error = 1;
                }

                if (styleBrush)
                {
                    int a = 255, r, g, b;
                    QColor color = QColorDialog::getColor(Qt::white, nullptr, "Цвет заливки");
                    if (color.isValid())
                    {
                        color.getRgb(&r, &g, &b, &a);
                        ellipse.brush.setRGBA(r, g, b, a);
                        ellipse.brush.setStyle(styleBrush);
                    }
                    else
                        error = 1;
                }


                if (!error)
                {
                    ellipse.setXY(x, y); //set coord in rect
                    ellipse.setRadAndRad1(rad, rad1); //set width and height rect

                    ellipse.draw(ui->widget->im);
                    update();
                }
            }
        }
        break;
    }
    case 4: //arc
    {
        //val
        arc arc;
        //init coord, width and height
        int x = ui->spinBox_inputX_1->value();
        int y = ui->spinBox_inputY_1->value();
        int width = ui->spinBox_inputX_2->value();
        int height = ui->spinBox_inputY_2->value();
        int startAngle = ui->spinBox_inputStartAngle->value();
        int drawAngle = ui->spinBox_inputDrawAngle->value();

        double widthPen = ui->spinBox_inputWidth->value(); //init width pen
        int styleLine = ui->comboBox_styleLine->currentIndex();

        if (styleLine)
        {
            if ((x + width > ui->widget->width()) or (y + height > ui->widget->height()) or (x + width / 2 > ui->widget->width()) or (x - width / 2 < 0) or (y + width / 2 > ui->widget->height()) or (y - width / 2 < 0))
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

                    //init color
                    int a, r, g, b;

                    QColor color = QColorDialog::getColor(Qt::white, nullptr, "Цвет линии");

                    if (color.isValid())
                    {//if choose OK in color dialog menu
                        color.getRgb(&r, &g, &b, &a);
                        a = 255;
                        arc.pen.setRGBA(r, g, b, a);
                        arc.pen.setWidth(int(widthPen));
                        arc.pen.setStyle(styleLine);

                        arc.start.setXY(x, y); //set coord in rect
                        arc.setWidthAndHeight(width, height); //set width and height rect
                        arc.setStartAngle(startAngle);
                        arc.setDrawAngle(drawAngle);

                        arc.draw(ui->widget->im);
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

                color = QColorDialog::getColor(Qt::white, nullptr, "Цвет линии");

                if (color.isValid())
                {//if choose OK in color dialog menu
                    color.getRgb(&r, &g, &b, &a);
                    a = 255;
                    arc.pen.setRGBA(r, g, b, a);
                    arc.pen.setWidth(int(widthPen));;
                    arc.pen.setStyle(styleLine);

                    arc.start.setXY(x, y); //set coord in rect
                    arc.setWidthAndHeight(width, height); //set width and height rect
                    arc.setStartAngle(startAngle);
                    arc.setDrawAngle(drawAngle);

                    arc.draw(ui->widget->im);
                    update();
                }

            }
            break;
        }
        break;
    }
    case 5: //circle
    {
        //val
        circle circle;
        //init coord, width and height
        int x = ui->spinBox_inputX_1->value();
        int y = ui->spinBox_inputY_1->value();
        int rad = ui->spinBox_inputX_2->value();

        double widthPen = ui->spinBox_inputWidth->value(); //init width pen
        int styleLine = ui->comboBox_styleLine->currentIndex();
        int styleBrush = ui->comboBox_styleBrush->currentIndex();

        if ((styleLine) or (styleBrush))
        {
            if ((x + rad > ui->widget->width()) or (y + rad > ui->widget->height()) or (x + rad / 2 > ui->widget->width()) or (x - rad / 2 < 0) or (y + rad / 2 > ui->widget->height()) or (y - rad / 2 < 0))
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
                    //init color
                    bool error = 0;

                    if (styleLine)
                    {
                        int a = 255, r, g, b;
                        QColor color = QColorDialog::getColor(Qt::white, nullptr, "Цвет линии");
                        if (color.isValid())
                        {
                            color.getRgb(&r, &g, &b, &a);
                            circle.pen.setRGBA(r, g, b, a);
                            circle.pen.setWidth(int(widthPen));
                            circle.pen.setStyle(styleLine);
                        }
                        else
                            error = 1;
                    }

                    if (styleBrush)
                    {
                        int a = 255, r, g, b;
                        QColor color = QColorDialog::getColor(Qt::white, nullptr, "Цвет заливки");
                        if (color.isValid())
                        {
                            color.getRgb(&r, &g, &b, &a);
                            circle.brush.setRGBA(r, g, b, a);
                            circle.brush.setStyle(styleBrush);
                        }
                        else
                            error = 1;
                    }


                    if (!error)
                    {
                        circle.setXY(x, y); //set coord in rect
                        circle.setRadius(rad); //set width and height rect

                        circle.draw(ui->widget->im);
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
                bool error = 0;

                if (styleLine)
                {
                    int a = 255, r, g, b;
                    QColor color = QColorDialog::getColor(Qt::white, nullptr, "Цвет линии");
                    if (color.isValid())
                    {
                        color.getRgb(&r, &g, &b, &a);
                        circle.pen.setRGBA(r, g, b, a);
                        circle.pen.setWidth(int(widthPen));
                        circle.pen.setStyle(styleLine);
                    }
                    else
                        error = 1;
                }

                if (styleBrush)
                {
                    int a = 255, r, g, b;
                    QColor color = QColorDialog::getColor(Qt::white, nullptr, "Цвет заливки");
                    if (color.isValid())
                    {
                        color.getRgb(&r, &g, &b, &a);
                        circle.brush.setRGBA(r, g, b, a);
                        circle.brush.setStyle(styleBrush);
                    }
                    else
                        error = 1;
                }


                if (!error)
                {
                    circle.setXY(x, y); //set coord in rect
                    circle.setRadius(rad); //set width and height rect

                    circle.draw(ui->widget->im);
                    update();
                }
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
    ui->spinBox_inputStartAngle->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->spinBox_inputDrawAngle->setButtonSymbols(QAbstractSpinBox::NoButtons);

    //set range
    ui->spinBox_inputX_1->setRange(0, 1060);
    ui->spinBox_inputY_1->setRange(0, 660);
    ui->spinBox_inputX_2->setRange(0, 1060);
    ui->spinBox_inputY_2->setRange(0, 660);
    ui->spinBox_inputWidth->setRange(1, 100);
    ui->spinBox_inputStartAngle->setRange(0, 360);
    ui->spinBox_inputDrawAngle->setRange(-360, 360);

    //hide extra lines
    ui->label_inputX_2->setVisible(false);
    ui->label_inputY_2->setVisible(false);
    ui->label_inputStartAngle->setVisible(false);
    ui->label_inputDrawAngle->setVisible(false);
    ui->spinBox_inputX_2->setVisible(false);
    ui->spinBox_inputY_2->setVisible(false);
    ui->spinBox_inputDrawAngle->setVisible(false);
    ui->spinBox_inputStartAngle->setVisible(false);
    ui->comboBox_styleLine->setVisible(false);
    ui->label_styleLine->setVisible(false);
    ui->label_styleBrush->setVisible(false);
    ui->comboBox_styleBrush->setVisible(false);
}

void MainWindow::on_comboBox_option_currentIndexChanged(int index) //hide extra lines
{
    if (index == 0) //choose pixel
    {
        ui->label_inputX_1->setText("Введите X:");
        ui->label_inputY_1->setText("Введите Y:");

        ui->label_inputX_1->setVisible(true);
        ui->label_inputY_1->setVisible(true);
        ui->spinBox_inputX_1->setVisible(true);
        ui->spinBox_inputY_1->setVisible(true);

        ui->label_inputX_2->setVisible(false);
        ui->label_inputY_2->setVisible(false);
        ui->spinBox_inputX_2->setVisible(false);
        ui->spinBox_inputY_2->setVisible(false);

        ui->comboBox_styleLine->setVisible(false);
        ui->label_styleLine->setVisible(false);

        ui->label_styleBrush->setVisible(false);
        ui->comboBox_styleBrush->setVisible(false);

        ui->label_inputDrawAngle->setVisible(false);
        ui->label_inputStartAngle->setVisible(false);

        ui->spinBox_inputDrawAngle->setVisible(false);
        ui->spinBox_inputStartAngle->setVisible(false);
    }
    else if (index == 1) //choose line
    {
        ui->label_inputX_1->setText("Введите X1:");
        ui->label_inputY_1->setText("Введите Y1:");
        ui->label_inputX_2->setText("Введите X2:");
        ui->label_inputY_2->setText("Введите Y2:");

        ui->label_inputX_1->setVisible(true);
        ui->label_inputY_1->setVisible(true);
        ui->spinBox_inputX_1->setVisible(true);
        ui->spinBox_inputY_1->setVisible(true);

        ui->label_inputX_2->setVisible(true);
        ui->label_inputY_2->setVisible(true);
        ui->spinBox_inputX_2->setVisible(true);
        ui->spinBox_inputY_2->setVisible(true);

        ui->comboBox_styleLine->setVisible(true);
        ui->label_styleLine->setVisible(true);

        ui->label_styleBrush->setVisible(false);
        ui->comboBox_styleBrush->setVisible(false);

        ui->label_inputDrawAngle->setVisible(false);
        ui->label_inputStartAngle->setVisible(false);

        ui->spinBox_inputDrawAngle->setVisible(false);
        ui->spinBox_inputStartAngle->setVisible(false);
    }
    else if (index == 2) //choose rectange
    {
        ui->label_inputX_1->setText("Введите X1:");
        ui->label_inputY_1->setText("Введите Y1:");
        ui->label_inputX_2->setText("Введите X2:");
        ui->label_inputY_2->setText("Введите Y2:");

        ui->label_inputX_2->setVisible(true);
        ui->label_inputY_2->setVisible(true);
        ui->spinBox_inputX_2->setVisible(true);
        ui->spinBox_inputY_2->setVisible(true);

        ui->comboBox_styleLine->setVisible(true);
        ui->label_styleLine->setVisible(true);

        ui->label_styleBrush->setVisible(true);
        ui->comboBox_styleBrush->setVisible(true);

        ui->label_inputDrawAngle->setVisible(false);
        ui->label_inputStartAngle->setVisible(false);

        ui->spinBox_inputDrawAngle->setVisible(false);
        ui->spinBox_inputStartAngle->setVisible(false);
    }
    else if (index == 3) //choose ellipse
    {
        ui->label_inputX_1->setText("Введите X:");
        ui->label_inputY_1->setText("Введите Y:");
        ui->label_inputX_2->setText("Радиус 1:");
        ui->label_inputY_2->setText("Радиус 2:");

        ui->label_inputX_2->setVisible(true);
        ui->label_inputY_2->setVisible(true);
        ui->spinBox_inputX_2->setVisible(true);
        ui->spinBox_inputY_2->setVisible(true);

        ui->comboBox_styleLine->setVisible(true);
        ui->label_styleLine->setVisible(true);

        ui->label_styleBrush->setVisible(true);
        ui->comboBox_styleBrush->setVisible(true);

        ui->label_inputDrawAngle->setVisible(false);
        ui->label_inputStartAngle->setVisible(false);

        ui->spinBox_inputDrawAngle->setVisible(false);
        ui->spinBox_inputStartAngle->setVisible(false);
    }
    else if (index == 4) //choose arc
    {
        ui->label_inputX_1->setText("Введите X:");
        ui->label_inputY_1->setText("Введите Y:");
        ui->label_inputX_2->setText("Ширина:");
        ui->label_inputY_2->setText("Высота:");

        ui->label_inputX_2->setVisible(true);
        ui->label_inputY_2->setVisible(true);
        ui->spinBox_inputX_2->setVisible(true);
        ui->spinBox_inputY_2->setVisible(true);

        ui->comboBox_styleLine->setVisible(true);
        ui->label_styleLine->setVisible(true);

        ui->label_styleBrush->setVisible(false);
        ui->comboBox_styleBrush->setVisible(false);

        ui->label_inputDrawAngle->setVisible(true);
        ui->label_inputStartAngle->setVisible(true);

        ui->spinBox_inputDrawAngle->setVisible(true);
        ui->spinBox_inputStartAngle->setVisible(true);
    }
    else if (index == 5) //choose circle
    {
        ui->label_inputX_1->setText("Введите X:");
        ui->label_inputY_1->setText("Введите Y:");
        ui->label_inputX_2->setText("Радиус:");

        ui->label_inputX_2->setVisible(true);
        ui->label_inputY_2->setVisible(false);
        ui->spinBox_inputX_2->setVisible(true);
        ui->spinBox_inputY_2->setVisible(false);

        ui->comboBox_styleLine->setVisible(true);
        ui->label_styleLine->setVisible(true);

        ui->label_styleBrush->setVisible(true);
        ui->comboBox_styleBrush->setVisible(true);

        ui->label_inputDrawAngle->setVisible(false);
        ui->label_inputStartAngle->setVisible(false);

        ui->spinBox_inputDrawAngle->setVisible(false);
        ui->spinBox_inputStartAngle->setVisible(false);
    }
}
