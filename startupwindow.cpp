#include "startupwindow.h"
#include "ui_startupwindow.h"

StartupWindow::StartupWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartupWindow)
{
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);                   //задает окну опции не менять размер
    ui->setupUi(this);
    gw = new gameWindow();                                              //создает объект второго класса

    connect(this,SIGNAL(gwWindowControl()),gw,SLOT(gwWindowControl())); //коннект перехода от первой формы ко второй
    connect(gw,SIGNAL(swWindowControl()),this,SLOT(swWindowControl()));
}

StartupWindow::~StartupWindow()
{
    delete ui;
}

void StartupWindow::on_goButton_clicked()   //1)при клике
{
        emit gwWindowControl();                 //3)сигнал gwWindowControl
        this->close();                          //2)окно закрывается
}

void StartupWindow::swWindowControl()
{
    this->show();
}
