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
    void gwWindowControl(bool *add, bool *sub, bool *mul, bool *div, bool *pow, bool *sqr, bool *sqE, bool *lnE, short int *mode, unsigned short int seconds, unsigned short int mistakes, unsigned short int *chars); //сигнал для перехода на вторую форму
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
    unsigned short int seconds = 5;
    unsigned short int mistakes = 1;
    unsigned short int chars = 1;
};

#endif // STARTUPWINDOW_H
