#include "startupwindow.h"
#include "ui_startupwindow.h"

StartupWindow::StartupWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartupWindow)
{
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);                   //задает окну опции не менять размер
    ui->setupUi(this);
    gw = new gameWindow();                                              //создает объект второго класса


    connect(this,SIGNAL(gwWindowControl(bool*, bool*, bool*, bool*, bool*, bool*, bool*, bool*, short int*, unsigned short int, unsigned short int, unsigned short int*)),
                gw,SLOT(gwWindowControl(bool*, bool*, bool*, bool*, bool*, bool*, bool*, bool*, short int*, unsigned short int, unsigned short int, unsigned short int*)));
    connect(gw,SIGNAL(swWindowControl()),
            this,SLOT(swWindowControl()));
}

StartupWindow::~StartupWindow()
{
    delete ui;
}

void StartupWindow::on_goButton_clicked()   //1)при клике
{
        add = ui->addBox        ->isChecked();
        sub = ui->subBox        ->isChecked();
        mul = ui->multipBox     ->isChecked();
        div = ui->divBox        ->isChecked();
        pow = ui->powBox        ->isChecked();
        sqr = ui->sqrBox        ->isChecked();
        sqE = ui->quadEqBox     ->isChecked();
        lnE = ui->lineEqBox     ->isChecked();
        if(ui->isMistakesRadio  ->isChecked())
           mode = 0;
        if(ui->isTimeRadio      ->isChecked())
           mode = 1;
        if(ui->isPracticeRadio  ->isChecked())
           mode = 2;
        seconds = ui->secondLineEdit->text().toInt();
        mistakes= ui->amountLineEdit->text().toInt();
        chars = ui->numbersAmountSpin->value();
        emit gwWindowControl(&add, &sub, &mul, &div, &pow, &sqr, &sqE, &lnE, &mode, seconds, mistakes, &chars); //3)сигнал gwWindowControl
        this->close();                          //2)окно закрывается
}

void StartupWindow::swWindowControl()
{
    this->show();
}
