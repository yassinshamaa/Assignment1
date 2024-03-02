#include "welcomepage.h"
#include "ui_welcomepage.h"
#include "QPixmap"
#include "loginwindow.h"

WelcomePage::WelcomePage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WelcomePage)
{
    ui->setupUi(this);
    QPixmap pix (":/resources/pics/LoginPic.jpg");
    int w = ui -> label_Picture -> width();
    int h = ui -> label_Picture -> height();
    ui -> label_Picture -> setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

WelcomePage::~WelcomePage()
{
    delete ui;
}

void WelcomePage::setValues(QString username, int age) {
    ui -> UserNameLabel -> setText(username + " " + QString :: number(age));
}

void WelcomePage::on_label_Picture_linkActivated(const QString &link)
{

}


void WelcomePage::on_pushButton_Logout_clicked()
{
    hide();
    LoginWindow* loginWindow = new LoginWindow(this);
    loginWindow -> show();
}

