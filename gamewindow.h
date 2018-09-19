#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWizardPage>

namespace Ui {
class gameWindow;
}

class gameWindow : public QWizardPage
{
    Q_OBJECT

public:
    explicit gameWindow(QWidget *parent = nullptr);
    ~gameWindow();

private slots:
    void on_gameWindow_destroyed();
    void gwWindowControl();         //слот для аналогичного сигнала из sw
private:
    Ui::gameWindow *ui;

};

#endif // GAMEWINDOW_H
