#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QKeyEvent>                //класс событий нажатий клавиш
#include <QDebug>
#include <QRandomGenerator>
#include <QDateTime>
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

unsigned short int gameWindow::expon(int number, unsigned short int exp)	//функция возвращающая целое число(int) с названием exp и принимающая
                                    //два целых числа в переменные number(число) и exp(степень)
{
    unsigned short int result = 1;				//создал целую переменную для записи результата вычислений со значением 1
    for (; exp != 0; exp--)		//пока степень не равна 0; после кода степень уменьшается на единицу
        {
            result *= number;	//число умножается само на себя и записывается в перем. result
        }
    return result;				//возвращается результат работы функции из переменной result
}

QString gameWindow::expressionGenerator(bool *add, bool *sub, bool *mul, bool *div, bool *pow, bool *sqr, bool *sqE, bool *lnE, unsigned short int *chars)
{
    QString expression = "";


    QRandomGenerator generator(QDateTime::currentMSecsSinceEpoch());
    int actionNum=0;                                //пер. для содержание ранд. числа, по которму выбирается действие
    int a = generator.bounded(expon(10, *chars));   //генерирует ранд. число "а" с кол-вом знаков chars
    int b = generator.bounded(expon(10, *chars));   //аналогично "b"

    while(1)
        {
            actionNum = generator.bounded(8);   //генерирует номер мат. действия
            if(*add==true && actionNum==0)      //сложение
            {
                expression = QString::number(a)+"+"+QString::number(b)+"="+QString::number(a+b);
                break;
            }
            if(*sub==true && actionNum==1)      //вычитание
            {
                expression = QString::number(a)+"-"+QString::number(b)+"="+QString::number(a-b);
                break;
            }
            if(*mul==true && actionNum==2)      //умножение
            {
                expression = QString::number(a)+"*"+QString::number(b)+"="+QString::number(a*b);
                break;
            }
            if(*div==true && actionNum==3)      //деление
            {
                if (a==0) continue; //во избежание деления на ноль
                expression = QString::number(a*b)+"/"+QString::number(a)+"="+QString::number(b);
                break;
            }
            /*if(*pow==true && actionNum==4)
            {
                expression = QString::number(a)+"+"+QString::number(b)+"="+QString::number(a+b);
                break;
            }
            if(*sqr==true && actionNum==5)
            {
                expression = QString::number(a)+"+"+QString::number(b)+"="+QString::number(a+b);
                break;
            }
            if(*sqE==true && actionNum==6)
            {
                expression = QString::number(a)+"+"+QString::number(b)+"="+QString::number(a+b);
                break;
            }
            if(*lnE==true && actionNum==7)
            {
                expression = QString::number(a)+"+"+QString::number(b)+"="+QString::number(a+b);
                break;
            }*/
        }
    return expression;  //возвращает текст примера вместе с ответом, который потом отделяется
}

void gameWindow::gwWindowControl(bool *add, bool *sub, bool *mul, bool *div, bool *pow, bool *sqr, bool *sqE, bool *lnE, short int *mode, unsigned short int seconds, unsigned short int mistakes, unsigned short int *chars)                            //(bool *add, bool *sub, bool *mul, bool *div, bool *pow, bool *sqr, bool *sqE, bool *lnE, short *mode, unsigned short seconds, unsigned short mistakes, unsigned short *chars)  //принимает сигнал из sw, который вызывается при клике на кнопку и активирует этот слот
{
    while(*mode == 0 && mistakes !=0)
    {
        QString modeHelpStr = "You have " + QString::number(mistakes) + " right(s) to make a mistake.";
        ui->modeLabel->setText(modeHelpStr);    //меняет %mode% на кол-во ошибок
        ui->askLabel->setText(expressionGenerator(add, sub, mul, div, pow, sqr, sqE, lnE, chars));
        mistakes = 0;
        //здесь должна быть сверка с ответом и сам ответ, отделенный от expression
    }
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
    //здесь должна изменяться глоб. перем. для сверки ответа
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




