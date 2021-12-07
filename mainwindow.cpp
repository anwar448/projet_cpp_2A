#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clients.h"
#include <QMessageBox>
#include <QIntValidator>
#include <connection.h>
#include<QRegExpValidator>
#define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
#include <QDesktopServices>
#include <QUrl>
#include<QDebug>
#include <QSystemTrayIcon>
#include <QDesktopServices>
#include <QSqlQuery>



/*#include <QPainter>*/
/*#include "qcustomplot.h"*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    QPixmap pix("C:/Users/SAFAA/Downloads/Atelier_Connexion/images.png");
        ui->image->setPixmap(pix);
  ui->pb_ajouter_clients->setDisabled(true);
  ui->pb_modifier->setDisabled(true);
    ui->le_cin->setValidator( new QIntValidator(0, 99999999, this));
    ui->le_cin_mod->setValidator( new QIntValidator(0, 99999999, this));
    ui->le_cin_supp->setValidator( new QIntValidator(0, 99999999, this));
    ui->le_num_tel->setValidator( new QIntValidator(0, 99999999, this));
     ui->le_num_tel_mod->setValidator( new QIntValidator(0, 99999999, this));




    ui->tab_clients->setModel(C.afficher());

    QRegExp rxNom(NOM_RX);
        QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
        ui->le_nom->setValidator(valiNom);
        ui->le_prenom->setValidator(valiNom);
      //  ui->le_genre->setValidator(valiNom);

        ui->le_nom_sup->setValidator(valiNom);

        ui->le_nom_mod->setValidator(valiNom);
        ui->le_prenom_mod->setValidator(valiNom);
     //   ui->le_genre_mod->setValidator(valiNom);



        stat();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clients_clicked()
{
    int ID_C=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString genre=ui->comboBox->currentText();
    QString adresse_maison=ui->le_adresse_maison->text();
    int num_tel=ui->le_num_tel->text().toInt();
    QString email=ui->le_email->text();
    QString date_visite=ui->le_date_visite->text();
    int nbr_visite=ui->le_nbr_visite->text().toInt();


    Clients C(ID_C,nom,prenom,genre,adresse_maison,num_tel,email,date_visite,nbr_visite);
    if ((ID_C>9999999)&(num_tel>9999999)&(nom.size()>2)&(prenom.size()>3))
    {
    bool test=C.ajouter_clients();
        QMessageBox msgbox;
        if(test)
        {msgbox.setText("Ajout avec succes.");
            ui->tab_clients->setModel(C.afficher());
               stat();
        }
        else
            msgbox.setText("Echec d'ajout");
        msgbox.exec();
    }
        else QMessageBox::critical(nullptr, QObject::tr("ok"),QObject::tr("FAILED.\n click cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_pushButton_31_clicked()
{
    int ID_C=ui->le_cin_supp->text().toInt();
        bool test=C.supprimer(ID_C);
            QMessageBox msgbox;
            if(test)
            {msgbox.setText("suppression avec succes.");
                ui->tab_clients->setModel(C.afficher());
                   stat();
            }
            else
                msgbox.setText("echec de suppression");
            msgbox.exec();


}

void MainWindow::on_pb_modifier_clicked()
{
    int ID_C=ui->le_cin_mod->text().toInt();
     QString nom=ui->le_nom_mod->text();
     QString prenom=ui->le_prenom_mod->text();
     QString genre=ui->comboBox_2->currentText();
     QString adresse_maison=ui->le_adresse_maison_mod->text();
     int num_tel=ui->le_num_tel_mod->text().toInt();
     QString email=ui->le_email_mod->text();
     QString date_visite=ui->le_date_visite_mod->text();
     int nbr_visite=ui->le_nbr_visite_mod->text().toInt();

     Clients C(ID_C,nom,prenom,genre,adresse_maison,num_tel,email,date_visite,nbr_visite);



     C.setID_C(ui->le_cin_mod->text().toInt()) ;
     bool test=C.modifier(C.getID_C()) ;

     QMessageBox msgBox;

     if(test)
     {msgBox.setText("modification avec succes.");
         ui->tab_clients->setModel(C.afficher());
            stat();
     }
     else
         msgBox.setText("Echec de modification");
         msgBox.exec();
}


void MainWindow::on_pb_trier_clicked()
{
    Clients C;
   ui->tab_trier->setModel(C.trierNom());
}

void MainWindow::on_pb_rechercher_clicked()
{
     Clients C;
     QString nom=ui->le_nom_rechercher->text();
     ui->tab_rechercher->setModel(C.rechercheNom(nom));
}


void MainWindow::stat(){
QSqlQuery q,q1;
q.prepare("select count(id_c),genre from clients group by genre;");
q1.prepare("select count(id_c) from clients;");
q.exec();
q1.exec();
q1.next();
int total=q1.value(0).toInt();
while(q.next()){
    if(q.value(1).toString().compare("homme")==0)ui->progressBar->setValue(q.value(0).toInt()*100/total);
    if(q.value(1).toString().compare("femme")==0)ui->progressBar_2->setValue(q.value(0).toInt()*100/total);
}
}
void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1!="homme" && arg1!="femme"){
        ui->pb_ajouter_clients->setDisabled(true);
    }else     ui->pb_ajouter_clients->setDisabled(false);
}

void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{ if(arg1!="homme" && arg1!="femme"){
        ui->pb_modifier->setDisabled(true);
    }else     ui->pb_modifier->setDisabled(false);

}

void MainWindow::on_mailing_clients_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
        QDesktopServices::openUrl(link);
}



void MainWindow::on_alerte_clients_clicked()
{
       C.alerte_clients_fidele();

}
