#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "RESSOURCE_HUMAINE.h"
#include<QMessageBox>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QRegExpValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

#define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-])+$"
    QRegExp rxNOM(NOM_RX);
    QRegExpValidator *valinom=new QRegExpValidator(rxNOM,this);

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit_ID_6->setValidator(new QIntValidator(0 , 99999999 , this)) ;
    ui->lineEdit_ID_9->setValidator(new QIntValidator(0 , 99999999 , this)) ;
    ui->lineEdit_Nombre_6->setValidator(new QIntValidator(0 , 99999999 , this)) ;
    ui->lineEdit_Nom_5->setValidator(valinom);
    ui->lineEdit_Type_5->setValidator(valinom);
    ui->lineEdit_Nom_6->setValidator(valinom);


    QPixmap pix("C:/Users/rami/Downloads/Maquette general/Maquette general/qtphoto/background.png");
        ui->photo->setPixmap(pix);
        QPixmap pix1("C:/Users/rami/Downloads/Maquette general/Maquette general/qtphoto/recipe.png");
            ui->facture ->setPixmap(pix1);
            QPixmap pix2("C:/Users/rami/Downloads/Maquette general/Maquette general/qtphoto/chariot.png");
                ui->fournisseurs ->setPixmap(pix2);
                QPixmap pix3("C:/Users/rami/Downloads/Maquette general/Maquette general/qtphoto/ressources humaine.png");
                    ui->ressources ->setPixmap(pix3);
                    QPixmap pix4("C:/Users/rami/Downloads/Maquette general/Maquette general/qtphoto/client.png");
                        ui->client ->setPixmap(pix4);
                        QPixmap pix5("C:/Users/rami/Downloads/Maquette general/Maquette general/qtphoto/produit.png");
                            ui->produit ->setPixmap(pix5);
                            QPixmap pix6("C:/Users/rami/Downloads/Maquette general/Maquette general/qtphoto/service.png");
                                ui->service ->setPixmap(pix6);
                                QPixmap pix7("C:/Users/rami/Downloads/produit.png");
                                ui->pic->setPixmap(pix7);
                                QPixmap pix8("C:/Users/rami/Downloads/ressources humaine.png");
                                    ui->ressources_->setPixmap(pix8);
                                    QPixmap pix9("C:/Users/rami/Downloads/logo.png");
                                    ui->logo->setPixmap(pix9);


}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_6_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_64_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{
 ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_103_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_114_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_61_clicked()
{
    QString cin =ui->lineEdit_ID_6->text();
    QString nom=ui->lineEdit_Nom_5->text();
    QString prenom=ui->lineEdit_Type_5->text();
    QString AFFECTATION_SERVICE=ui->lineEdit_Nom_6->text();
    int NOMBRE_HEURE_DE_TRAVAIL=ui->lineEdit_Type_6->text().toInt();
    RESSOURCE_HUMAINE C(cin, nom, prenom,AFFECTATION_SERVICE,NOMBRE_HEURE_DE_TRAVAIL);
if (cin.size()>7)
{
    bool test=C.ajouter();
    if(test)
    {
        ui->tableView->setModel(C.afficher());

        QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("Ajout effectué.\n click cancel to exit."),QMessageBox::Cancel);
        ui->tabWidget_3->setCurrentIndex(2);
    }
    else QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("Ajout non effectué.\n click cancel to exit."),QMessageBox::Cancel);
}
else QMessageBox::critical(nullptr, QObject::tr("ok"),QObject::tr("FAILED.\n click cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_69_clicked()
{
    int id =ui->lineEdit_ID_9->text().toInt();
    RESSOURCE_HUMAINE C;
    QSqlQuery qry;
    qry.prepare("SELECT * FROM RESSOURCE_HUMAINE where cin=:newid");
    qry.bindValue(":newid",id);
    if(qry.exec())
    {
        bool alreadyExist = false;
        alreadyExist = qry.next();
        if(alreadyExist)
        {
            bool test=C.supprimer(id);
            if(test)
            {
                ui->tableView->setModel(C.afficher());
                QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("Personnel supprime.\n click cancel to exit."),QMessageBox::Cancel);
                ui->tabWidget_3->setCurrentIndex(2);

            }
            else
               QMessageBox::critical(nullptr, QObject::tr("Not ok"),QObject::tr("Ajout non effectué.\n click cancel to exit."),QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),
            QObject::tr("ID doesn't exist.\n"
            "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
        QObject::tr("Error.\n"
        "Click Cancel to exit."), QMessageBox::Cancel);
        }

}

void MainWindow::on_pushButton_65_clicked()
{
    int val=ui->lineEdit_ID_9->text().toInt();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM RESSOURCE_HUMAINE where cin=:newid");
    qry.bindValue(":newid",val);
    if(qry.exec())
    {
        bool alreadyExist = false;
        alreadyExist = qry.next();
        if(alreadyExist)
        {
            ui->tabWidget_3->setCurrentIndex(3);


                ui->lineEdit_Nombre_6->setText(qry.value(0).toString());
                ui->lineEdit_Nom_7->setText(qry.value(1).toString());
                ui->lineEdit_Type_7->setText(qry.value(2).toString());
                ui->lineEdit_Delai_6->setText(qry.value(3).toString());
                ui->lineEdit_Prix_7->setText(qry.value(4).toString());


        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),
            QObject::tr("ID doesn't exist.\n"
            "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
        QObject::tr("Error.\n"
        "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }


void MainWindow::on_tabWidget_3_currentChanged(int index)
{
    if (index == 2){
        RESSOURCE_HUMAINE C;
        ui->tableView->setModel(C.afficher());}
}

void MainWindow::on_pushButton_82_clicked()
{

}

void MainWindow::on_pushButton_66_clicked()
{
    QSqlQuery query;
    QString cin =ui->lineEdit_Nombre_6->text();
    QString nom=ui->lineEdit_Nom_7->text();
    QString prenom=ui->lineEdit_Type_7->text();
    QString AFFECTATION_SERVICE=ui->lineEdit_Delai_6->text();
    int NOMBRE_HEURE_DE_TRAVAIL=ui->lineEdit_Prix_7->text().toInt();

    RESSOURCE_HUMAINE C(cin, nom, prenom, AFFECTATION_SERVICE, NOMBRE_HEURE_DE_TRAVAIL);
    query.prepare("SELECT * FROM RESSOURCE_HUMAINE where cin=:newid");
    query.bindValue(":newid",cin);
    if(!query.exec())
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
        QObject::tr("Failed adding.\n"
        "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        bool v=C.modifier(cin);
        QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
        QObject::tr("UPDATED.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tabWidget_3->setCurrentIndex(2);

        if (!v){
        QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
        QObject::tr("failed.\n""Click Cancel to exit."), QMessageBox::Cancel);}
    }

    ui->tableView->setModel(C.afficher());
}
