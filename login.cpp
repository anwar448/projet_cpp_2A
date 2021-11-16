#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QPixmap pix3("C:/Users/Lenovo/Desktop/photo-1560066984-138dadb4c035.jfif");
    ui->label_pic4->setPixmap(pix3);
    ui->lineEdit_username->setPlaceholderText("Nom D'utilisateur");
    ui->lineEdit_password->setPlaceholderText("Mot de Passe");

}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    /*Fournisseur F;
    //F.setLOGIN(ui->lineEdit_username->text());
    //F.setMDP(ui->lineEdit_password->text());
     bool b;
     // MainWindow w;
     b=F.se_connecter();

     if(b==1){
         if(p.getLOGIN()=="admin")
         { auto win = new Admin();
                         win->show();}
         else
         {
         auto win = new MainWindow(p.getID());
          //win->setAttribute( Qt::WA_DeleteOnClose );
          win->show();
         }
        //  deleteLater();
        // w.show();
          this->close();
     }
     else { QMessageBox::critical(nullptr,QObject::tr("Se connecter"),QObject::tr("login ou mot de passe invalides \n "
                                                                                          "Click Cancel to exit"),QMessageBox::Cancel);}*/
}
