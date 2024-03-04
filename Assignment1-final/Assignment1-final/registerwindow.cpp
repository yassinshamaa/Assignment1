#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "loginwindow.h"
#include "Users.h"
#include "welcomepage.h"


RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui-> AgeLessLabel ->setVisible(false);
    ui-> NotMatchingLabel ->setVisible(false);
    ui-> AlreadExistingLabel ->setVisible(false);
    ui-> FieldsFilledLabel ->setVisible(false);

}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButton_Register_clicked()
{
    QString pass = ui -> lineEdit_Password -> text();
    QString repass = ui -> lineEdit_PasswordRe -> text();
    QString user = ui -> lineEdit_Username -> text();
    int year = ui->lineEdit_Year->text().toInt();
    QString month = ui -> comboBox_Month->currentText();
    int age = 2024 - year;


    bool passequal = (repass == pass);
    bool checkAge = ((2024 - year) >= 12);
    bool radioClicked1 = (ui->radioButton->isChecked() || ui->radioButton_2->isChecked());
    bool radioClicked2 = (ui->radioButton_3->isChecked() || ui->radioButton_4->isChecked());
    bool noEmptyField = (!user.isEmpty() && !pass.isEmpty() && !repass.isEmpty() && !ui->lineEdit_Day->text().isEmpty() && !ui->lineEdit_Year->text().isEmpty() && radioClicked1 && radioClicked2);
    bool newaccount = true;

    ui->NotMatchingLabel->setVisible(false);
    ui->AgeLessLabel->setVisible(false);
    ui->FieldsFilledLabel->setVisible(false);
    ui->AlreadExistingLabel->setVisible(false);

    for (int i = 0; i < 100; i++) {
        if (user == usernames[i]) {
            ui->AlreadExistingLabel->setVisible(true);
            newaccount = false;
            break;
        }
    }

    if (noEmptyField && passequal && checkAge && radioClicked1 && radioClicked2 && newaccount) {



        if (newaccount) {
            for (int i = 0; i < 100; i++) {
                if (usernames[i].isEmpty()) {
                    ui->AlreadExistingLabel->setVisible(false);
                    usernames[i] = user;
                    passwords[i] = pass;
                    ages[i] = age;

                    usersCount++;
                    break;
                }

            }
            hide();
            WelcomePage* welcomePage = new WelcomePage(this);
            welcomePage -> setValues(user, age);
            welcomePage -> show();
    }




    }
    if (!checkAge){

        ui->AgeLessLabel->setVisible(true);

    }
    if(!passequal){

        ui->NotMatchingLabel->setVisible(true);

    }
    if(!noEmptyField){
        ui-> FieldsFilledLabel ->setVisible(true);

    }


}





