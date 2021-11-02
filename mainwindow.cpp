#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include <QMessageBox>
#include <QIntValidator>
#include <connection.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/21651/Documents/2A22/projet C++/photo_produit2.png");
    ui->image->setPixmap(pix);

    ui->le_ID->setValidator(new QIntValidator(100, 99999, this));
    //ui->tab_afficher->setModel(P.afficher());
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_clicked()
{
    int ID=ui->le_ID->text().toInt();
    QString Nom=ui->le_Nom->text();
    QString Type=ui->le_Type->text();
    int Nombre=ui->le_Nombre->text().toInt();
    QString Delai=ui->le_Delai->text();
    QString Prix=ui->le_Prix->text();

    Produit P(ID,Nom,Type,Nombre,Delai,Prix);
    bool test=P.ajouter();
    QMessageBox msgBox;

    if(test)
        msgBox.setText("ajout avec succes.");
    else
        msgBox.setText("Echec d'ajout");
        msgBox.exec();

}

void MainWindow::on_supprimer_clicked()
{

    Produit P1, P2;
    P2.setID(ui->le_ID_supp->text().toInt()) ;
    bool test=P1.supprimer(P2.getID()) ;
    QMessageBox msgBox;

    if(test)
    {msgBox.setText("suppression avec succes.");
        ui->tab_afficher->setModel(P.afficher());
    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();

}



void MainWindow::on_afficher_clicked()
{
    Produit P;
    ui->tab_afficher->setModel(P.afficher());
}

void MainWindow::on_modifier_clicked()
{
    int ID=ui->le_ID_mod->text().toInt();
    QString Nom=ui->le_Nom_mod->text();
    QString Type=ui->le_Type_mod->text();
    int Nombre=ui->le_Nombre_mod->text().toInt();
    QString Delai=ui->le_Delai_mod->text();
    QString Prix=ui->le_Prix_mod->text();

    Produit P(ID,Nom,Type,Nombre,Delai,Prix);


    P.setID(ui->le_ID_mod->text().toInt()) ;
    bool test=P.modifier(P.getID()) ;

    QMessageBox msgBox;

    if(test)
    {msgBox.setText("modification avec succes.");
        ui->tab_afficher->setModel(P.afficher());
    }
    else
        msgBox.setText("Echec de modification");
        msgBox.exec();

}
