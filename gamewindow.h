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
signals:
    void swWindowControl();
private slots:
    void gwWindowControl(bool *add, bool *sub, bool *mul, bool *div, bool *pow, bool *sqr, bool *sqE, bool *lnE, short int *mode, unsigned short int seconds, unsigned short int mistakes, unsigned short int *chars);       //bool *add, bool *sub, bool *mul, bool *div, bool *pow, bool *sqr, bool *sqE, bool *lnE, short int *mode, unsigned short int seconds, unsigned short int mistakes, unsigned short int *chars);         //слот для аналогичного сигнала из sw

private:
    Ui::gameWindow *ui;
    void closeEvent(QCloseEvent *event);
    void keyPressEvent (QKeyEvent * event);
};

#endif // GAMEWINDOW_H
