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

private:
    Ui::StartupWindow *ui;
    gameWindow *gw;                 //связь через со вторым классом через этот указатель
};

#endif // STARTUPWINDOW_H
