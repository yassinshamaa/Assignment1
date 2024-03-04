#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QDialog>

namespace Ui {
class WelcomePage;
}

class WelcomePage : public QDialog
{
    Q_OBJECT

public:
    explicit WelcomePage(QWidget *parent = nullptr);
    void setValues(QString username, int age);
    ~WelcomePage();

private slots:
    void on_label_Picture_linkActivated(const QString &link);

    void on_pushButton_Logout_clicked();

private:
    Ui::WelcomePage *ui;
};

#endif // WELCOMEPAGE_H
