#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qsqldatabase.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAbout_triggered();

    void on_actionQuiter_triggered();

    void on_tableWidgetEtudiant_doubleClicked(const QModelIndex &index);

    void on_pushButtonAbandonner_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QSqlDatabase maDatabase;

    void chargeComboOption();

    void chargerTableEtudiant();

};

#endif // MAINWINDOW_H
