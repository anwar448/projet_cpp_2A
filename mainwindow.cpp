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

    ui->le_ID->setValidator(new QIntValidator(100, 99999999, this));
    ui->le_Nombre->setValidator(new QIntValidator(100, 99999999, this));

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
    int Quantite=ui->le_Nombre->text().toInt();
    QString Delai=ui->le_Delai->text();
    QString Prix=ui->le_Prix->text();

    Produit P(ID,Nom,Type,Quantite,Delai,Prix);
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
    int Quantite=ui->le_Nombre_mod->text().toInt();
    QString Delai=ui->le_Delai_mod->text();
    QString Prix=ui->le_Prix_mod->text();

    Produit P(ID,Nom,Type,Quantite,Delai,Prix);


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



void MainWindow::on_Annuler_1_clicked()
{
    ui->le_ID->setText("");
    ui->le_Nom->setText("");
    ui->le_Type->setText("");
    ui->le_Nombre->setText("");
    ui->le_Delai->setText("");
    ui->le_Prix->setText("");
}


void MainWindow::on_Annuler_2_clicked()
{
    ui->le_ID_mod->setText("");
    ui->le_Nom_mod->setText("");
    ui->le_Type_mod->setText("");
    ui->le_Nombre_mod->setText("");
    ui->le_Delai_mod->setText("");
    ui->le_Prix_mod->setText("");
}

void MainWindow::on_Annuler_3_clicked()
{
    ui->le_ID_supp->setText("");
}

void MainWindow::on_trier_clicked()
{
    Produit P;
    ui->tab_afficher->setModel(P.trierDelai());
}

void MainWindow::on_afficher_pour_modifier_clicked()
{
    // ui->le_Nom_mod->setText("");
     //chouf supprimer
}
