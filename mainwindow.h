#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "ui_QtSignalSlots.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

// сигналы
signals:
    // сигнал связанный со слотом изменения фона окна
    // button_number для определения номера нажатой кнопки
    void getColor(int button_number);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

// слоты
public slots:
    // слоты, связывающиеся с сигналами нажатия кнопок
    void setColorRed();
    void setColorGreen();
    void setColorBlue();

    // слот изменения фона окна
    void onClicked(int button_Number);


private:
    Ui::MainWindow *ui;
};






#endif // MAINWINDOW_H
