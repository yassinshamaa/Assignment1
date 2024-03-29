#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWindow;
}
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    QString username;
    int age;
    ~LoginWindow();

private slots:
    void on_pushButton_2_Register_clicked();

    void on_pushButton_Login_clicked();

private:
    Ui::LoginWindow *ui;
};
#endif // LOGINWINDOW_H
