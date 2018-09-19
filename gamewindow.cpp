#include "gamewindow.h"
#include "ui_gamewindow.h"

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
    this->show();       //показывает окно
}
