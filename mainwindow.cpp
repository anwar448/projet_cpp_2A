#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QRegExpValidator>
#include <QSqlQuery>
#include <QSystemTrayIcon>
#include <QDebug>
#include "qcustomplot.h"
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_four->setValidator( new QIntValidator(0, 9999999, this));
    ui->lineEdit_four_2->setValidator( new QIntValidator(0, 99999999, this));
    ui->lineEdit_four_4->setValidator( new QIntValidator(0, 9999999, this));
    ui->lineEdit_four_8->setValidator( new QIntValidator(0, 9999999, this));
    ui->lineEdit_four_9->setValidator( new QIntValidator(0, 99999999, this));
    #define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
    QRegExp rxNom(NOM_RX);
    QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
    ui->lineEdit_four_3->setValidator(valiNom);
    ui->lineEdit_four_5->setValidator(valiNom);
    ui->lineEdit_four_10->setValidator(valiNom);
    ui->lineEdit_four_11->setValidator(valiNom);
    ui->tab_fournisseur->setModel(F.afficher());
    QPixmap pix("C:/Users/Lenovo/Desktop/cosmetics-arranged-dusty-dark-background_23-2148181475.jpg");
    ui->label_pic->setPixmap(pix);
    QPixmap pix1("C:/Users/Lenovo/Desktop/51uaMYQH6NL._AC_SL1000_.jpg");
    ui->label_pic1->setPixmap(pix1);
    QPixmap pix2("C:/Users/Lenovo/Desktop/istockphoto-1090043994-170667a.jpg");
    ui->label_pic2->setPixmap(pix2);
    //QPixmap pix3("C:/Users/Lenovo/Desktop/photo-1560066984-138dadb4c035.jpg");
    //ui->label_pic4->setPixmap(pix3);
    //QPixmap pix4("C:/Users/Lenovo/Desktop/makeup-brushes-wallpaper-how-often-do-you-clean-your-makeup-brushes-lust4labels-blog-1.jpg");
    //ui->label_reclamation->setPixmap(pix4);
    //QPixmap pix3("C:/Users/Lenovo/Desktop/istockphoto-1090043994-170667a.jpg");
    //ui->label_pic3->setPixmap(pix3);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->lineEdit_four->text().toInt();
    int num_tel=ui->lineEdit_four_2->text().toInt();
    QString nom_societe=ui->lineEdit_four_3->text();
    QString type_produit=ui->lineEdit_four_5->text();
    QString adresse_mail=ui->lineEdit_four_6->text();
    QString adresse_local=ui->lineEdit_four_7->text();
    Fournisseur F(id,num_tel,nom_societe,type_produit,adresse_mail,adresse_local);
    bool test=F.ajouter();
    QMessageBox msgbox;
    if(id!=0 && num_tel!=0 && nom_societe.size()>0 && type_produit.size()>0 && adresse_mail.size()>0 && adresse_local.size()>0)
    {
    if(adresse_mail.contains("@gmail.com")||adresse_mail.contains("@yahoo.fr")||adresse_mail.contains("@hotmail.com")||adresse_mail.contains("@hotmail.fr"))
    {
    if(test)
    {msgbox.setText("Ajout avec succes.");
        ui->tab_fournisseur->setModel(F.afficher());
        ui->lineEdit_four->setText("");
        ui->lineEdit_four_2->setText("");
        ui->lineEdit_four_3->setText("");
        ui->lineEdit_four_5->setText("");
        ui->lineEdit_four_6->setText("");
        ui->lineEdit_four_7->setText("");

    }
    else
        msgbox.setText("Echec d'ajout");
    msgbox.exec();
    }
    else  QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                    QObject::tr("EMAIL INVALIDE.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else  QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                             QObject::tr("CHAMP VIDE .\n" "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{
   Fournisseur F1; F1.setid(ui->lineEdit_four_4->text().toInt());
   bool test=F1.supprimer(F1.getid());
   QMessageBox msgbox;
   if(test)
   {msgbox.setText("Suppression avec succes.");
       ui->tab_fournisseur->setModel(F.afficher());
   }
   else
       msgbox.setText("Echec de suppression");
   msgbox.exec();
}

void MainWindow::on_pb_modifier_clicked()
{
    int id=ui->lineEdit_four_8->text().toInt();
        int Num_tel=ui->lineEdit_four_9->text().toInt();
        QString nom_societe=ui->lineEdit_four_10->text();
        QString type_produit=ui->lineEdit_four_11->text();
        QString adresse_mail=ui->lineEdit_four_12->text();
        QString adresse_local=ui->lineEdit_four_13->text();

        Fournisseur F(id,Num_tel,nom_societe,type_produit,adresse_mail,adresse_local);


        F.setid(ui->lineEdit_four_8->text().toInt()) ;
        bool test=F.modifier(F.getid()) ;

        QMessageBox msgBox;
        if(test)
        {msgBox.setText("modification avec succes.");
            ui->tab_fournisseur->setModel(F.afficher());
        }
        else
        msgBox.setText("Echec de modification");
            msgBox.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    if (ui->radioButton_four->isChecked())
        {
            QString id= ui->lineEdit_four_16->text() ;
            ui->tableView_four->setModel(F.chercherid(id));

        }

        /*if (ui->radioButton_2->isChecked())
        {
            QString num_tel= ui->lineEdit_16->text() ;
            ui->tableView_four->setModel(F.chercherNum_tel(num_tel));

        }*/

        if (ui->radioButton_four_3->isChecked())
        {
            QString type_produit= ui->lineEdit_four_16->text() ;
            ui->tableView_four->setModel(F.chercherType_produit(type_produit));

        }
        if (!(ui->radioButton_four_3->isChecked())&&!(ui->radioButton_four->isChecked()))
               {
            QMessageBox::critical(nullptr, QObject::tr("cherche échoué"),
                                   QObject::tr("\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
        }

}
void MainWindow::on_pushButton_3_clicked()
{
    Fournisseur F;
        QString crit=ui->comboBox_trie_four->currentText();
        if(crit=="Type_produit")
        {
            ui->tableView_tri->setModel(F.trieType_produit());
        }
        else
        {
            ui->tableView_tri->setModel(F.trieid());
        }

}

/*void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit_User->text();
    int password = ui->lineEdit_Pass->text().toInt();

    if ((username == "Admin" )||( username == "admin"))
    {
        if (password == 1234)
        { QMessageBox::information(this, "Login","Bienvenue");
            //music1->stop();
    auto win=new MainWindow();
    win->show();
    //music1->stop();
   // integration e;
   // e.show();
    MainWindow l;
    l.show();
    //music1->stop();

    this->close();}
        //music1->stop();}}
    else {
        QMessageBox::warning(this, "Login","Desole Vous n'etes pas un Admin");
}
}}*/
void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView_modif->setModel(F.afficher());
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    Fournisseur f;
        // background //
                  QLinearGradient gradient(0, 0, 0, 400);
                  gradient.setColorAt(0, QColor(220, 200, 200));
                  gradient.setColorAt(0.38, QColor(200, 200, 220));
                  gradient.setColorAt(0.38, QColor(000, 200, 200));
                  ui->plot->setBackground(QBrush(gradient));

                  QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
                  amande->setAntialiased(false);
                  amande->setStackingGap(1);
                   //couleurs
                  amande->setName("Repartition selon fournisseur");
                  amande->setPen(QPen(QColor(0, 100, 100).lighter(130)));
                  amande->setBrush(QColor(0, 146, 200));

                   //axe des abscisses
                  QVector<double> ticks;
                  QVector<QString> labels;
                  f.statistique(&ticks,&labels);

                  QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
                  textTicker->addTicks(ticks, labels);
                  ui->plot->xAxis->setTicker(textTicker);
                  ui->plot->xAxis->setTickLabelRotation(60);
                  ui->plot->xAxis->setSubTicks(false);
                  ui->plot->xAxis->setTickLength(0, 4);
                  ui->plot->xAxis->setRange(0, 8);
                  ui->plot->xAxis->setBasePen(QPen(Qt::black));
                  ui->plot->xAxis->setTickPen(QPen(Qt::black));
                  ui->plot->xAxis->grid()->setVisible(true);
                  ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
                  ui->plot->xAxis->setTickLabelColor(Qt::black);
                  ui->plot->xAxis->setLabelColor(Qt::black);

                  // axe des ordonnées
                  ui->plot->yAxis->setRange(0,10);
                  ui->plot->yAxis->setPadding(5);
                  ui->plot->yAxis->setLabel("Statistiques");
                  ui->plot->yAxis->setBasePen(QPen(Qt::black));
                  ui->plot->yAxis->setTickPen(QPen(Qt::black));
                  ui->plot->yAxis->setSubTickPen(QPen(Qt::black));
                  ui->plot->yAxis->grid()->setSubGridVisible(true);
                  ui->plot->yAxis->setTickLabelColor(Qt::black);
                  ui->plot->yAxis->setLabelColor(Qt::black);
                  ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
                  ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

                  // ajout des données  (statistiques du fournisseur)//

                  QVector<double> PlaceData;
                  QSqlQuery q1("select id  from FOURNISSEUR");
                  while (q1.next()) {
                                int  nbr_fautee = q1.value(0).toInt();
                                PlaceData<< nbr_fautee;
                                  }
                  amande->setData(ticks, PlaceData);

                  ui->plot->legend->setVisible(true);
                  ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
                  ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
                  ui->plot->legend->setBorderPen(Qt::NoPen);
                  QFont legendFont = font();
                  legendFont.setPointSize(5);
                  ui->plot->legend->setFont(legendFont);
                  ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void MainWindow::on_pushButton_5_clicked()
{

    QTableView *table;
               table = ui->tab_fournisseur;

               QString filters("CSV files (.csv);;All files (.*)");
               QString defaultFilter("CSV files (*.csv)");
               QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                  filters, &defaultFilter);
               QFile file(fileName);

               QAbstractItemModel *model =  table->model();
               if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                   QTextStream data(&file);
                   QStringList strList;
                   for (int i = 0; i < model->columnCount(); i++) {
                       if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                           strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                       else
                           strList.append("");
                   }
                   data << strList.join(";") << "\n";
                   for (int i = 0; i < model->rowCount(); i++) {
                       strList.clear();
                       for (int j = 0; j < model->columnCount(); j++) {

                           if (model->data(model->index(i, j)).toString().length() > 0)
                               strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") + "\n";
                   }
                   file.close();
                   QMessageBox::information(nullptr, QObject::tr("Import excel"),
                                             QObject::tr("Import avec succes .\n"
                                                         "Click OK to exit."), QMessageBox::Ok);
               }
}

/*void MainWindow::on_sendBtn_clicked()
{
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
    connect(ui->deconnexion, SIGNAL(clicked()), this, SLOT(browse()));
    QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Reclamation sent!\n\n" ) );



}*/

void MainWindow::on_pushButton_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
        QDesktopServices::openUrl(link);
}
//arduinoooooo
void MainWindow::update_label()
{
    data=A.read_from_arduino();
    if(data=="1")

        ui->label_15->setText("Produit acceptée"); // si les données reçues de arduino via la liaison série sont égales à 1


    else if (data=="0")

        ui->label_15->setText("Produit refusé");   // si les données reçues de arduino via la liaison série sont égales à 0

}
void MainWindow::on_pushButton_7_clicked()   // implémentation du slot bouton accepter
{
     A.write_to_arduino("1"); //envoyer 1 à arduino
}

void MainWindow::on_pushButton_6_clicked()  // implémentation du slot bouton refuser
{

     A.write_to_arduino("0");  //envoyer 0 à arduino
}
