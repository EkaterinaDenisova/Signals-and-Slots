#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // связываем кнопки с соответствующими слотами
    QObject::connect(ui->pushButtonGreen, &QPushButton::clicked, this, &MainWindow::setColorGreen);
    QObject::connect(ui->pushButtonRed, &QPushButton::clicked, this, &MainWindow::setColorRed);
    QObject::connect(ui->pushButtonBlue, &QPushButton::clicked, this, &MainWindow::setColorBlue);

    // связываем сигнал getColor со слотом, отвечающим за смену цвета фона
    QObject::connect(this, &MainWindow::getColor, this, &MainWindow::onClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setColorGreen()
{
    // Ключевое слово emit вызывает сигнал getColor() с новым значением в качестве аргумента
    // параметр 1 соответствует нажатию зелёной кнопки
    emit getColor(1);
}

void MainWindow::setColorRed()
{
    // параметр 2 соответствует нажатию красной кнопки
    emit getColor(2);
}

void MainWindow::setColorBlue()
{
    // параметр 3 соответствует нажатию синей кнопки
    emit getColor(3);
}

// слот, меняющий цвет фона в зависимости от переданного номера из сигнала getColor
void MainWindow::onClicked(int button_Number)
{
    switch(button_Number) {
    case 1:
        this->setStyleSheet("background-color: rgb(151, 238, 192);");
        break;
    case 2:
        this->setStyleSheet("background-color: rgb(255, 187, 188);");
        break;
    case 3:
        this->setStyleSheet("background-color: rgb(162, 206, 226);");
        break;
    }
}

