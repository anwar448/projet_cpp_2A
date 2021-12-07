#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
#include <QMessageBox>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    /*QPixmap pix3("C:/Users/Lenovo/Desktop/photo-1560066984-138dadb4c035.jpg");
    ui->label_pic4->setPixmap(pix3);*/
    ui->lineEdit_username->setPlaceholderText("Nom de societe");
    ui->lineEdit_password->setPlaceholderText("Mot de Passe");

}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{   

       QString Nom_societe=ui->lineEdit_username->text();
       QString mdp=ui-> lineEdit_password->text();
       QSqlQuery query;
       query.prepare("select * from Fournisseur where Nom_societe=:Nom_societe and id=:mdp");
       query.addBindValue(ui->lineEdit_username->text());
       query.addBindValue(ui->lineEdit_password->text());
       query.exec();
           bool alreadyExist = false;
           alreadyExist = query.next();
           if(alreadyExist)
           {

                 ui->lineEdit_username->setText("");
                 ui->lineEdit_password->setText("");
                 close() ;
                QMessageBox msgbox ;
                msgbox.setText("Bienvenue "+Nom_societe+"") ;
                msgbox.exec() ;


           }
           else
               {
               QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                                QObject::tr("NOM D'UTILISATEUR OU MOT DE PASSE INCORRECTE.\n" "Click Cancel to exit."), QMessageBox::Cancel);
               ui->lineEdit_username->setText("");
               ui->lineEdit_password->setText("");
                }
}
