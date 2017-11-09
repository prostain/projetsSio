#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aproposde.h"

#include <QSqlQuery>
#include<QMessageBox>
#include <QSqlError>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //initialisation de la base de données
       this->maDatabase=QSqlDatabase::addDatabase("QSQLITE");
        this->maDatabase.setDatabaseName("/home/prostain/slam3/etudiant/etudiant.data");

        // ----------------------------------
    this->chargeComboOption();
    this->chargerTableEtudiant();
}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    // instanciation de la fenetre
    aProposDe fenetreAide;
    // ouverture de la fenetre
    fenetreAide.exec();
}

void MainWindow::on_actionQuiter_triggered()
{
    this->close();
}


void MainWindow::chargerTableEtudiant()
{

    //remise à zéro de la table
    //fixer le nombre de colonnes du tableau
    ui->tableWidgetEtudiant->setColumnCount(4);

    //afficher un entête en haut de chaque colonne
    ui->tableWidgetEtudiant->setHorizontalHeaderItem(0, new QTableWidgetItem("id"));
    ui->tableWidgetEtudiant->setHorizontalHeaderItem(1, new QTableWidgetItem("nom"));
    ui->tableWidgetEtudiant->setHorizontalHeaderItem(2, new QTableWidgetItem("prenom"));
    ui->tableWidgetEtudiant->setHorizontalHeaderItem(3, new QTableWidgetItem("option"));
    //afficher les entêtes de colonne
    ui->tableWidgetEtudiant->horizontalHeader()->show();

    //cacher la colonne 0, id
    ui->tableWidgetEtudiant->hideColumn(0);

    //cacher les entêtes des lignes
    ui->tableWidgetEtudiant->verticalHeader()->hide();

    this->maDatabase.open();


    //préparation et exécution de la requête
    QSqlQuery maRequete;
    maRequete.prepare("SELECT * FROM etudiant ORDER BY nom, prenom");
    //si la requete s'exécute bien
    if (maRequete.exec())
    {
        //parcours des enregistrements, un par un, tant qu'il y en a
        while(maRequete.next())
        {

            //ajouter une ligne au tableau
            ui->tableWidgetEtudiant->setRowCount(ui->tableWidgetEtudiant->rowCount()+1);

            //écrire la valeur récupérée au bon endroit dans le tableau
            ui->tableWidgetEtudiant->setItem(ui->tableWidgetEtudiant->rowCount()-1,0,new QTableWidgetItem(maRequete.value("id").toString()));
            ui->tableWidgetEtudiant->setItem(ui->tableWidgetEtudiant->rowCount()-1,1,new QTableWidgetItem(maRequete.value("nom").toString()));
            ui->tableWidgetEtudiant->setItem(ui->tableWidgetEtudiant->rowCount()-1,2,new QTableWidgetItem(maRequete.value("prenom").toString()));
            ui->tableWidgetEtudiant->setItem(ui->tableWidgetEtudiant->rowCount()-1,3,new QTableWidgetItem(maRequete.value("option").toString()));
        }
    }
    //on passe à la ligne suivante

    //fermeture de la base de données
    this->maDatabase.close();


}

void MainWindow::chargeComboOption()
{
    //remise à zéro de la combo
    ui->comboBoxOption->clear();

    //préparation et exécution de la requête
    this->maDatabase.open();

    QSqlQuery query;

    query.prepare("SELECT option FROM etudiant ORDER BY option");

    //si la requête s'exécute bien
    if(query.exec())
    {
    //parcours des enregistrements, un par un, tant qu'il y en a
        while(query.next())
    //ajouter l'option renvoyée par la requete au combo
            ui->comboBoxOption->addItem(query.value(0).toString());
    }
    else
qDebug()<<"erreur requete: "<<query.lastError().text();


    //fermer la base de données
    this->maDatabase.close();

}

void MainWindow::on_tableWidgetEtudiant_doubleClicked(const QModelIndex &index)
{
    ui->lineEditNom->setText(ui->tableWidgetEtudiant->item(index.row(),1)->text());
    ui->lineEditPrenom->setText(ui->tableWidgetEtudiant->item(index.row(),2)->text());
    ui->comboBoxOption->lineEdit()->setText(ui->tableWidgetEtudiant->item(index.row(),3)->text());

}

void MainWindow::on_pushButtonAbandonner_clicked(bool checked)
{
    //désactivation des boutons Supprimer et Abandonner
    ui->pushButtonAbandonner->setEnabled(false);
    ui->pushButtonSupprimer->setEnabled(false);

    //remise à zéro des champs du formulaire
    ui->lineEditNom->clear();
    ui->lineEditPrenom->clear();
    ui->comboBoxOption->clear();
    ui->tableWidgetEtudiant->clear();

     //réinitialisation de la ligne en cours de modification
}
