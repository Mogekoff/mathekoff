#ifndef STARTUPWINDOW_H
#define STARTUPWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"     //для видимости второго класса

namespace Ui {
class StartupWindow;
}

class StartupWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartupWindow(QWidget *parent = nullptr);
    ~StartupWindow();
signals:
    void gwWindowControl();         //сигнал для перехода на вторую форму
private slots:
    void on_goButton_clicked();
    void swWindowControl();
private:
    Ui::StartupWindow *ui;
    gameWindow *gw;                 //связь со вторым классом через этот указатель
    bool add = false;
    bool sub = false;
    bool mul = false;
    bool div = false;
    bool pow = false;
    bool sqr = false;
    bool sqE = false;
    bool lnE = false;
    short int mode = 0;
    unsigned int seconds = 5;
    unsigned int mistakes = 1;
    unsigned int chars = 1;
};

#endif // STARTUPWINDOW_H
