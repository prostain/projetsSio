#ifndef APROPOSDE_H
#define APROPOSDE_H

#include <QDialog>

namespace Ui {
class aProposDe;
}

class aProposDe : public QDialog
{
    Q_OBJECT

public:
    explicit aProposDe(QWidget *parent = 0);
    ~aProposDe();

private slots:
    void on_PushButtonFermer_clicked();

private:
    Ui::aProposDe *ui;
};

#endif // APROPOSDE_H
