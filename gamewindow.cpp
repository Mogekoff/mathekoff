#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QKeyEvent>                //класс событий нажатий клавиш
#include <QDebug>
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

void gameWindow::gwWindowControl(bool *add, bool *sub, bool *mul, bool *div, bool *pow, bool *sqr, bool *sqE, bool *lnE, short int *mode, unsigned short int seconds, unsigned short int mistakes, unsigned short int *chars)                            //(bool *add, bool *sub, bool *mul, bool *div, bool *pow, bool *sqr, bool *sqE, bool *lnE, short *mode, unsigned short seconds, unsigned short mistakes, unsigned short *chars)  //принимает сигнал из sw, который вызывается при клике на кнопку и активирует этот слот
{
    qDebug()<<*add;
    qDebug()<<*sub;
    qDebug()<<*mode;
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
        emit swWindowControl();             //сигнал: возвращает в меню
    }
    if (event->key()==Qt::Key_Backspace)    //удал. последний символ ответа
    {
        QString str=ui->answerLabel->text();    //созд. строку с текстом из ответа
        str.chop(1);                            //удал. посл. символ в строке
        ui->answerLabel->setText(str);          //заменяет старый текст на новый
    }
}
