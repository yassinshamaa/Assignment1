#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "registerwindow.h"
#include "welcomepage.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_2_Register_clicked()
{
    hide();
    RegisterWindow* R = new RegisterWindow(this);
    R->show();
}

