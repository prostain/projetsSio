#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QApplication>
#include <QSqldatabase>
#include <QSqlquery>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlDriverPlugin>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ouvertur de la base de données

    // constructor : initialise the database

    dbManager::dbManager(QString "localhost", QString "etudiant.data", QString "root", QString "" ): QMainWindow(),
    d_host("localhost"), d_dbname("etudiant.data"), d_username("root"), d_pwd("")
    {
            dbConnexion();
    }
    // function : create connexion to the database
    void dbManager::dbConnexion()
    {
        d_db = QSqlDatabase::addDatabase("QSQLITE");
        d_db.setHostName(d_host);
        d_db.setDatabaseName(d_dbname);
        d_db.setUserName(d_username);
        d_db.setPassword(d_pwd);

        if ( !d_db.open() )
        {
             QMessageBox::warning(this, "Erreur Ouverture", d_db.lastError().text());
        }
        else
        {
            QMessageBox::information(this, "Bonne Ouverture", "Connexion BD Ok!");
            // ça rentre ici, pour info :sisi:
        }

        qDebug() << "coucou";
        QSqlQuery query;
        if(query.exec("SELECT * FROM etudiant"))
        {
            qDebug() << "ok";
        }
    }


    //chargement des données


    //affichage des données

MainWindow::~MainWindow()
{
    delete ui;
}
