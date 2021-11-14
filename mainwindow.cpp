#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "conbd.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectDB();

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::controle_saisie()
{
   QString styleSheetok= "QlineEdit{\n      border: 2px solid rgb(45, 45, 45);\n      border-radius:5px;\n      padding: 10px;\n      background-color: rgb(30, 30, 30);\n\n     color:rgb(100, 100, 100);\n}\nQLineEdit:hover{\n     border: 2px solid rgb(55, 55, 55);\n}\n\nQLineEdit:focus\n{\n\nborder: 2px solid rgb(255, 0, 0);\ncolor: rgb(200, 200, 205);\n\n\n\n}";
   QString styleSheeterror= "QlineEdit{\n      border: 2px solid rgb(255, 87, 1275);\n      border-radius:5px;\n      padding: 10px;\n      background-color: rgb(30, 30, 30);\n\n     color:rgb(100, 100, 100);\n}\nQLineEdit:hover{\n     border: 2px solid rgb(55, 55, 55);\n}\n\nQLineEdit:focus\n{\n\nborder: 2px solid rgb(255, 0, 0);\ncolor: rgb(200, 200, 205);\n\n\n\n}";
   QString offre = "";
   QString type = "";
   QString disponibilite = "";

  if(this->ui->leType->text().isEmpty()){

      type= "type empty";
      this->ui->leType->setStyleSheet(styleSheeterror);
  } else{
     type= "";
     this->ui->leType->setStyleSheet(styleSheetok);
     }

  if(this->ui->lesOffres->text().isEmpty()){

    offre= "offre empty";
      this->ui->lesOffres->setStyleSheet(styleSheeterror);
} else{
      offre= "";
      this->ui->lesOffres->setStyleSheet(styleSheetok);
      }


  if(this->ui->laDisponibilite ->text().isEmpty()){

    disponibilite= "disponibilité empty";
      this->ui->laDisponibilite->setStyleSheet(styleSheeterror);
} else{
      disponibilite= "";
      this->ui->laDisponibilite->setStyleSheet(styleSheetok);
      }
  if(type !="" || offre !="" || disponibilite !=""){

      return false;

  }else return true;
}

service MainWindow::collecte_data()
{
     service serv;
     QSqlQuery que;
     serv.setId(this->ui->Id->value());
     serv.setTarifs(this->ui->tarifs->value());
     serv.setDisponibilite(this->ui->laDisponibilite->text());
     serv.setOffres(this->ui->lesOffres->text());
     serv.setHoraire(this->ui->date->date());
     serv.setType(this->ui->leType->text());
     serv.setID_employer(this->ui->Id_employer->value());

     qDebug() << "la valeur du tarif est: " <<this->ui->Id->value() ;
      return serv;


}


void MainWindow::on_pbAJOUTER_clicked()
{
 service serv;
 serv= collecte_data();
 bool test= controle_saisie();
 QMessageBox msgBox;
  if(test)
      msgBox.setText("Ajout avec succes.");
  else msgBox.setText("Echec de l'ajout");
  msgBox.exec();
}

void MainWindow::on_groupBox_3_clicked()
{

}

void MainWindow::on_pushButton_2_clicked()
{
   int id;
   service s;
   id = this->ui->spinBox_3->value();
   s=s.select(id);
   this->ui->lineEdit_11->setText(s.getType());
   this->ui->spinBox_6->setValue(s.getTarifs());
   this->ui->lineEdit_12->setText(s.getOffre());
   this->ui->lineEdit_13->setText(s.getDisponibilite());
   this->ui->DATE->setDate(s.getHoraire());
   this->ui->spinBox_7->setValue(s.getID_employer());
}

void MainWindow::on_pushButton_6_clicked()
{

}

void MainWindow::on_pb_supprimer_clicked()
{
   service S1; S1.setId(ui->id_supp->text().toInt());
   bool test=S1.supprimer(S1.getId());
   QMessageBox msgBox;
    if(test)
        msgBox.setText("Suppression avec succes.");
    else msgBox.setText("Echec de suppression");
    msgBox.exec();


}
