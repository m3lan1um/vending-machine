#include <iostream>
#include <QMessageBox>
#include "widget.h"
#include "ui_widget.h"

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin)
{
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl() {
    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbMilk->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbChange->setEnabled(money > 0);
}

void Widget::on_pbCoin500_clicked() {
    changeMoney(500);
}

void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);

}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);

}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);

}

void Widget::on_pbChange_clicked()
{
    QMessageBox msgBox;
    int coins[4] = {500, 100, 50, 10};
    string msg = "";
    char tmp[100] = {0};

    for(int coin: coins) {
        int n = money / coin;
        if (n > 0) {
            snprintf(tmp, sizeof(tmp), "%d * %d won\n", n, coin);
            msg.append(tmp);
            money = money % coin;
        }
    }

    ui->lcdNumber->display(money);
    setControl();

    msgBox.setText("Here's your changes!");
    msgBox.setInformativeText(msg.c_str());
    msgBox.exec();
}

