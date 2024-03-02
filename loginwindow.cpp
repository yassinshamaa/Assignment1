#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "registerwindow.h"
#include "welcomepage.h"
#include "Users.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui -> label_error -> setVisible(false);
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


void LoginWindow::on_pushButton_Login_clicked()
{
    bool foundlogin = false;
    for (int i = 0; i < usersCount; i++) {
        if (((ui -> lineEdit_Username -> text()) == usernames[i]) && ((ui -> lineEdit_Password -> text()) == passwords[i])) {
            foundlogin = true;
            username = usernames[i];
            age = ages[i];
        }
    }
    if (foundlogin == false) {
        ui -> label_error -> setVisible(true);
    }
    else {
        hide();
        WelcomePage* welcomePage = new WelcomePage(this);
        welcomePage -> setValues(username, age);
        welcomePage -> show();
    }
}

