#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QKeyEvent>                //класс событий нажатий клавиш
gameWindow::gameWindow(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::gameWindow)
{
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    ui->setupUi(this);
}
gameWindow::~gameWindow()
{
    delete ui;
}

void gameWindow::gwWindowControl()  //принимает сигнал из sw, который вызывается при клике на кнопку и активирует этот слот
{
    /*...инициализация нулями и тд...*/
    this->show();                   //показывает окно
}

void gameWindow::closeEvent( QCloseEvent* event )   //функция, вызываемая при закрытии окна
{
    this->close();              //окно закрывается
    emit swWindowControl();     //сигнал к открытию первой формы - меню
    event->accept();            //???
}

void gameWindow::keyPressEvent (QKeyEvent * event)      //функция проверки нажатия клавиши, объект event содержит значения клавиш
{
    if (event->key()==Qt::Key_Enter || event->key()==Qt::Key_Return)    //key() возвращает нажатую клавишу; она сравнивается с забитой Qt::Key_Enter...
    {
    }
    if (event->key()==Qt::Key_Escape)
    {
        emit swWindowControl();
    }
    if (event->key()==Qt::Key_Backspace)
    {
        QString str=ui->answerLabel->text();
        str.chop(1);
        ui->answerLabel->setText(str);
    }
}
