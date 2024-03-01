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
    ~WelcomePage();

private:
    Ui::WelcomePage *ui;
};

#endif // WELCOMEPAGE_H
