#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "RESSOURCE_HUMAINE.h"
#include<QMessageBox>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QRegExpValidator>
#include<QFileInfo>
#include<QFileDialog>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include "qcustomplot.h"
#include "stat_produit.h"
#include "produit.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QIntValidator>
#include <connection.h>
#include <iostream>
#include <QRegExp>
#include <QRegExpValidator>
#define NOM_RX "^([a-z]+[ ]?|[A-Z]+['-]?)+$"
#define TYPE_RX "^([a-z]+[ ]?|[A-Z]+['-]?)+$"
#define PRIX_RX "^([0-9]?|[.]?)+$"
#include <QPainter>
#include "piechartwidget.h"
#include <QSound>
#include <QDesktopServices>
#include <QUrl>
#include <QSoundEffect>
#include "fournisseur.h"
#include <QUrl>
#include <QSystemTrayIcon>
#include "facture.h"
#include <QSound>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include "smtp.h"
#include <QPrinter>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include"QSortFilterProxyModel"
#include "clients.h"
#include <QMessageBox>
#include <QIntValidator>
#include <connection.h>
#include<QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include<QDebug>
#include <QSystemTrayIcon>
#include <QDesktopServices>
#include <QSqlQuery>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

#define NOM_RXrh "^([a-z]+[,.]?[ ]?|[a-z]+['-])+$"
    QRegExp rxNOM(NOM_RXrh);
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
                                /*QPixmap pix7("C:/Users/rami/Downloads/produit.png");
                                ui->pic->setPixmap(pix7);*/
                                QPixmap pix8("C:/Users/rami/Downloads/ressources humaine.png");
                                    ui->ressources_->setPixmap(pix8);
                                    QPixmap pix9("C:/Users/rami/Downloads/logo.png");
                                    ui->logo->setPixmap(pix9);

   //sabrine                        QPixmap pix("C:/Users/rami/Downloads/smart beauty center (1)/smart beauty center/qtphoto/photo_produit2.png");
                                    ui->image->setPixmap(pix);
                                    QPixmap pix88("C:/Users/rami/Downloads/smart beauty center (1)/smart beauty center/qtphoto/photo_produit2.png");
                                    ui->image_8->setPixmap(pix88);
                                    QPixmap pix33("C:/Users/rami/Downloads/smart beauty center (1)/smart beauty center/qtphoto/photo_produit2.png");
                                    ui->image_6->setPixmap(pix33);
                                    QPixmap pix44("C:/Users/rami/Downloads/smart beauty center (1)/smart beauty center/qtphoto/photo_produit2.png");
                                    ui->image_4->setPixmap(pix44);

                                    ui->le_ID->setValidator(new QIntValidator(100, 99999999, this));
                                    ui->le_ID_mod->setValidator(new QIntValidator(100, 99999999, this));
                                    ui->le_ID_supp->setValidator(new QIntValidator(100, 99999999, this));
                                    ui->le_Nombre->setValidator(new QIntValidator(100, 99999999, this));
                                    ui->le_Nombre_mod->setValidator(new QIntValidator(100, 99999999, this));


                                    QRegExp rxNom(NOM_RX);
                                    QRegExp rxType(TYPE_RX);
                                    QRegExp rxPrix(PRIX_RX);
                                    QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
                                    QRegExpValidator*valiType= new QRegExpValidator(rxType,this);
                                    QRegExpValidator*valiPrix= new QRegExpValidator(rxPrix,this);
                                    ui->le_Nom->setValidator(valiNom);
                                    ui->le_Type->setValidator(valiType);
                                    ui->le_Nom_mod->setValidator(valiNom);
                                    ui->le_Type_mod->setValidator(valiType);
                                    ui->le_Prix->setValidator(valiPrix);
                                    ui->le_Prix_mod->setValidator(valiPrix);
//anwer
                                    ui->lineEdit->setValidator( new QIntValidator(0, 9999999, this));
                                    ui->lineEdit_2->setValidator( new QIntValidator(0, 99999999, this));
                                    ui->lineEdit_4->setValidator( new QIntValidator(0, 9999999, this));
                                    ui->lineEdit_8->setValidator( new QIntValidator(0, 9999999, this));
                                    ui->lineEdit_9->setValidator( new QIntValidator(0, 99999999, this));
                                    #define NOM_RXf "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
                                    QRegExp rxNom1(NOM_RXf);
                                    QRegExpValidator*valiNom1= new QRegExpValidator(rxNom1,this);
                                    ui->lineEdit_3->setValidator(valiNom1);
                                    ui->lineEdit_5->setValidator(valiNom1);
                                    ui->lineEdit_10->setValidator(valiNom1);
                                    ui->lineEdit_11->setValidator(valiNom1);
                                    ui->tab_fournisseur->setModel(F.afficher());
                                    QPixmap pix10("C:/Users/rami/Downloads/smart beauty center (1)/smart beauty center/qtphoto/cosmetics-arranged-dusty-dark-background_23-2148181475.jpg");
                                    ui->label_pic->setPixmap(pix10);
                                    QPixmap pix11("C:/Users/rami/Downloads/smart beauty center (1)/smart beauty center/qtphoto/51uaMYQH6NL._AC_SL1000_.jpg");
                                    ui->label_pic1->setPixmap(pix11);
                                    QPixmap pix12("C:/Users/rami/Downloads/smart beauty center (1)/smart beauty center/qtphoto/istockphoto-1090043994-170667a.jpg");
                                    ui->label_pic2->setPixmap(pix12);
//sameh
                                   /* QPixmap pix("C:/Users/rami/Downloads/smart beauty center (1)/smart beauty center/qtphoto/slider-facture.png");
                                       ui->image->setPixmap(pix);
                                       ui->image1->setPixmap(pix);
                                       ui->image2->setPixmap(pix);
                                       ui->image3->setPixmap(pix);
                                       ui->image4->setPixmap(pix);
                                       ui->image5->setPixmap(pix);
                                       ui->image6->setPixmap(pix);*/
                                   
                                       ui->tab_afficherf->setModel(Fa.afficherf());
                                   
                                       connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
                                       connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));


   /*zeinab                                    //QPixmap pix("C:/Users/BERTRAND/Desktop/projet2A/Maquette_du_projet2A/ab.png");
                                       ui->image->setPixmap(pix);
                                       ui->image1->setPixmap(pix);
                                       ui->image2->setPixmap(pix);
                                       ui->image3->setPixmap(pix); */


  //safaaaaaaaaaaaaa
                                       //QPixmap pix("C:/Users/SAFAA/Downloads/Atelier_Connexion/images.png");
                                               ui->image->setPixmap(pix);
                                         ui->pb_ajouter_clients->setDisabled(true);
                                         ui->pb_modifier->setDisabled(true);
                                           ui->le_cin->setValidator( new QIntValidator(0, 99999999, this));
                                           ui->le_cin_mod->setValidator( new QIntValidator(0, 99999999, this));
                                           ui->le_cin_supp->setValidator( new QIntValidator(0, 99999999, this));
                                           ui->le_num_tel->setValidator( new QIntValidator(0, 99999999, this));
                                            ui->le_num_tel_mod->setValidator( new QIntValidator(0, 99999999, this));




                                           ui->tab_clients->setModel(C.afficher());

                                           QRegExp rxNomc(NOM_RX);
                                               QRegExpValidator*valiNomc= new QRegExpValidator(rxNomc,this);
                                               ui->le_nom->setValidator(valiNomc);
                                               ui->le_prenom->setValidator(valiNomc);
                                             //  ui->le_genre->setValidator(valiNom);

                                               ui->le_nom_sup->setValidator(valiNomc);

                                               ui->le_nom_mod->setValidator(valiNomc);
                                               ui->le_prenom_mod->setValidator(valiNomc);
                                            //   ui->le_genre_mod->setValidator(valiNomc);



                                               stat();

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

void MainWindow::on_return_client_clicked()
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
if ((cin.size()>7)&(nom.size()>2)&(prenom.size()>2)&(AFFECTATION_SERVICE.size()>2)&(NOMBRE_HEURE_DE_TRAVAIL>0))
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

    else {RESSOURCE_HUMAINE f;
            // background //
                      QLinearGradient gradient(0, 0, 0, 400);
                      gradient.setColorAt(0, QColor(0, 210, 250));
                      gradient.setColorAt(0.38, QColor(250, 50, 250));
                      gradient.setColorAt(1, QColor(70, 70, 70));
                      ui->plott->setBackground(QBrush(gradient));

                      QCPBars *amande = new QCPBars(ui->plott->xAxis, ui->plott->yAxis);
                      amande->setAntialiased(false);
                      amande->setStackingGap(1);
                       //couleurs
                      amande->setName("Repartition selon cin");
                      amande->setPen(QPen(QColor(0, 80, 90).lighter(130)));
                      amande->setBrush(QColor(140, 140, 150));

                       //axe des abscisses
                      QVector<double> ticks;
                      QVector<QString> labels;
                      f.statistique(&ticks,&labels);

                      QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
                      textTicker->addTicks(ticks, labels);
                      ui->plott->xAxis->setTicker(textTicker);
                      ui->plott->xAxis->setTickLabelRotation(60);
                      ui->plott->xAxis->setSubTicks(false);
                      ui->plott->xAxis->setTickLength(0, 4);
                      ui->plott->xAxis->setRange(0, 8);
                      ui->plott->xAxis->setBasePen(QPen(Qt::black));
                      ui->plott->xAxis->setTickPen(QPen(Qt::white));
                      ui->plott->xAxis->grid()->setVisible(true);
                      ui->plott->xAxis->grid()->setPen(QPen(QColor(250, 250, 250), 0, Qt::DotLine));
                      ui->plott->xAxis->setTickLabelColor(Qt::white);
                      ui->plott->xAxis->setLabelColor(Qt::white);

                      // axe des ordonnées
                      ui->plott->yAxis->setRange(0,1000);
                      ui->plott->yAxis->setPadding(5);
                      ui->plott->yAxis->setLabel("Statistiques");
                      ui->plott->yAxis->setBasePen(QPen(Qt::white));
                      ui->plott->yAxis->setTickPen(QPen(Qt::white));
                      ui->plott->yAxis->setSubTickPen(QPen(Qt::white));
                      ui->plott->yAxis->grid()->setSubGridVisible(true);
                      ui->plott->yAxis->setTickLabelColor(Qt::white);
                      ui->plott->yAxis->setLabelColor(Qt::white);
                      ui->plott->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
                      ui->plott->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

                      // ajout des données  (statistiques du fournisseur)//

                      QVector<double> PlaceData;
                      QSqlQuery q1("select NOMBRE_HEURE_DE_TRAVAIL  from RESSOURCE_HUMAINE");
                      while (q1.next()) {
                                    int  nbr_fautee = q1.value(0).toInt();
                                    PlaceData<< nbr_fautee;
                                      }
                      amande->setData(ticks, PlaceData);

                      ui->plott->legend->setVisible(true);
                      ui->plott->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
                      ui->plott->legend->setBrush(QColor(255, 255, 255, 100));
                      ui->plott->legend->setBorderPen(Qt::NoPen);
                      QFont legendFont = font();
                      legendFont.setPointSize(5);
                      ui->plott->legend->setFont(legendFont);
                      ui->plott->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
                      ui->plott->update();

    }
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
        if ((cin.size()>7)&(nom.size()>2)&(prenom.size()>2)&(AFFECTATION_SERVICE.size()>2)&(NOMBRE_HEURE_DE_TRAVAIL>0))
        {
        bool v=C.modifier(cin);
        QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
        QObject::tr("UPDATED.\n""Click Cancel to exit."), QMessageBox::Cancel);
        ui->tabWidget_3->setCurrentIndex(2);

        if (!v){
        QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
        QObject::tr("failed.\n""Click Cancel to exit."), QMessageBox::Cancel);}
    }
    }
    ui->tableView->setModel(C.afficher());
}

void MainWindow::on_lineEdit_100_textChanged(const QString &arg1)
{
    ui->tableView->setModel(C.rechercher(arg1));
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    switch (index)
        {
          case 0:  ui->tableView->setModel(C.trie1());break;
          case 1:  ui->tableView->setModel(C.trie2());break;
          case 2:  ui->tableView->setModel(C.trie3());break;
          case 3:  ui->tableView->setModel(C.trie4());break;
          case 4:  ui->tableView->setModel(C.trie5());break;
        }
}


void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    switch (index)
        {
          case 0:  ui->tableView->setModel(C.trie11());break;
          case 1:  ui->tableView->setModel(C.trie22());break;
          case 2:  ui->tableView->setModel(C.trie33());break;
          case 3:  ui->tableView->setModel(C.trie44());break;
          case 4:  ui->tableView->setModel(C.trie55());break;
        }
}



void MainWindow::on_pushButton_125_clicked()
{
}

void MainWindow::on_pushButton_51_clicked()
{


            QString filename= QFileDialog::getOpenFileName(this,tr("choose"),"",tr("Images (*.png *.jpg *.jpeg"));
            if (QString::compare(filename,QString())!=0)
            {
              QImage label_image;
              bool valid =label_image.load(filename);
              if (valid)
              {   label_image= label_image.scaledToWidth(ui->image->width(),Qt::SmoothTransformation);
                  ui->image->setPixmap(QPixmap::fromImage(label_image));
              }
              else {// error
              }
            }
}

void MainWindow::on_pushButton_52_clicked()
{
    QString strStream;
               QTextStream out(&strStream);

               const int rowCount = ui->tableView->model()->rowCount();
               const int columnCount = ui->tableView->model()->columnCount();

               out <<  "<html>\n"
                   "<head>\n"
                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                   <<  QString("<title>%1</title>\n").arg("strTitle")
                   <<  "</head>\n"
                   "<body bgcolor=#ffffff link=#5000A0>\n"

                   //     "<align='right'> " << datefich << "</align>"
                   "<center> <H1>Liste RH </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

               // headers
               out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
               for (int column = 0; column < columnCount; column++)
                   if (!ui->tableView->isColumnHidden(column))
                       out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
               out << "</tr></thead>\n";

               // data table
               for (int row = 0; row < rowCount; row++)
               {
                   out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
                   for (int column = 0; column < columnCount; column++)
                   {
                       if (!ui->tableView->isColumnHidden(column))
                       {
                           QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                           out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                       }
                   }
                   out << "</tr>\n";
               }
               out <<  "</table> </center>\n"
                   "</body>\n"
                   "</html>\n";

               QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
               if (QFileInfo(fileName).suffix().isEmpty())
               {
                   fileName.append(".pdf");
               }

               QPrinter printer (QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                QTextDocument doc;
                doc.setHtml(strStream);
                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                doc.print(&printer);
}


//"produit"

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
    int val=ui->le_ID_supp->text().toInt();
    QSqlQuery qry;
      qry.prepare("SELECT * FROM Produit where ID_PRODUIT= :newid");
      qry.bindValue(":newid",val);

      if(!qry.exec())
      {
          QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                  QObject::tr("Echec de suppression.\n"
                  "Click Cancel to exit."), QMessageBox::Cancel);
      }
      else
      {
      bool alreadyExist = false;
       alreadyExist = qry.next();

       if(alreadyExist)
       {

           P2.setID(ui->le_ID_supp->text().toInt()) ;
           bool test=P1.supprimer(P2.getID()) ;
           QMessageBox msgBox;

           if(!test)
           {
               msgBox.setText("Echec de suppression");
               //ui->tab_afficher->setModel(P.afficher());
           }
           else
               msgBox.setText("suppression avec succes.");
               msgBox.exec();
       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                               QObject::tr("ID doesn't exist.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
       }
        }

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

void MainWindow::on_afficher_pour_modifier_clicked()
{
    int val=ui->le_ID_mod->text().toInt();
        QSqlQuery qry;
        qry.prepare("SELECT * FROM Produit where ID_produit=:newid");
        qry.bindValue(":newid",val);

        if(qry.exec())
        {
            bool alreadyExist = false;
            alreadyExist = qry.next();
            if(alreadyExist)
            {
                ui->tabWidget_2->setCurrentIndex(3);


                    ui->le_ID_mod->setText(qry.value(0).toString());
                    ui->le_Nom_mod->setText(qry.value(1).toString());
                    ui->le_Type_mod->setText(qry.value(2).toString());
                    ui->le_Nombre_mod->setText(qry.value(3).toString());
                    ui->le_Delai_mod->setText(qry.value(4).toString());
                    ui->le_Prix_mod->setText(qry.value(5).toString());

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

void MainWindow::on_Rechercher_clicked()
{
    Produit P;

    QString crit=ui->comboBox_rechercher->currentText();
    if(crit=="ID")
    {
        QString id=ui->le_Rchercher->text() ;
        ui->tab_rechercher->setModel(P.rechercheID(id));
    }
    else if(crit=="Nom")
    {
        QString Nom=ui->le_Rchercher->text() ;
        ui->tab_rechercher->setModel(P.rechercheNom(Nom));
    }
    else if(crit=="Quantité")
    {
        QString Quant=ui->le_Rchercher->text() ;
        ui->tab_rechercher->setModel(P.rechercheQuantite(Quant));
    }
    else
    {
        QString Prix=ui->le_Rchercher->text() ;
        ui->tab_rechercher->setModel(P.recherchePrix(Prix));
    }

    //QString cin=ui->lineEdit->text();
    //ui->tabvoyageur->setModel(tmpvoy.chercher(cin));
}

void MainWindow::on_trier_clicked()
{
    Produit P;
    QString crit=ui->comboBox_trier->currentText();
    if(crit=="Delai")
    {
        ui->tab_trier->setModel(P.trierDelai());
    }
    else if(crit=="Quantité")
    {
        ui->tab_trier->setModel(P.trierQuant());
    }
    else
    {
        ui->tab_trier->setModel(P.trierNom());
    }
}


void MainWindow::on_Quitter_clicked()
{//QSound::play("C:/Users/21651/Documents/2A22/projet C++/QT/projet_produit/button-49.wav");
    MainWindow::close();
}

void MainWindow::on_alerte_clicked()
{
    QSqlQuery qry;
 if (qry.exec("select * from Produit WHERE Quantite <= 5 "))
 {
    int n=0;

     while (qry.next())
     {
         qDebug () <<n;
         n= qry.value(2).toInt();
        if(n<5)
           {  Produit P;
                 P.alerte_fin_stock();

           }
     }
 }
}

void MainWindow::on_mailing_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
    QDesktopServices::openUrl(link);
}



//anwer
void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->lineEdit->text().toInt();
    int num_tel=ui->lineEdit_2->text().toInt();
    QString nom_societe=ui->lineEdit_3->text();
    QString type_produit=ui->lineEdit_5->text();
    QString adresse_mail=ui->lineEdit_6->text();
    QString adresse_local=ui->lineEdit_7->text();
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
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        ui->lineEdit_5->setText("");
        ui->lineEdit_6->setText("");
        ui->lineEdit_7->setText("");

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
   Fournisseur F1; F1.setid(ui->lineEdit_4->text().toInt());
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
    int id=ui->lineEdit_8->text().toInt();
        int Num_tel=ui->lineEdit_9->text().toInt();
        QString nom_societe=ui->lineEdit_10->text();
        QString type_produit=ui->lineEdit_11->text();
        QString adresse_mail=ui->lineEdit_12->text();
        QString adresse_local=ui->lineEdit_13->text();

        Fournisseur F(id,Num_tel,nom_societe,type_produit,adresse_mail,adresse_local);


        F.setid(ui->lineEdit_8->text().toInt()) ;
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

void MainWindow::on_pushButton_19_clicked()
{
    if (ui->radioButton->isChecked())
        {
            QString id= ui->lineEdit_16->text() ;
            ui->tableView_four->setModel(F.chercherid(id));

        }

        /*if (ui->radioButton_2->isChecked())
        {
            QString num_tel= ui->lineEdit_16->text() ;
            ui->tableView_four->setModel(F.chercherNum_tel(num_tel));

        }*/

        if (ui->radioButton_3->isChecked())
        {
            QString type_produit= ui->lineEdit_16->text() ;
            ui->tableView_four->setModel(F.chercherType_produit(type_produit));

        }
        if (!(ui->radioButton_3->isChecked())&&!(ui->radioButton->isChecked()))
               {
            QMessageBox::critical(nullptr, QObject::tr("cherche échoué"),
                                   QObject::tr("\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
        }

}
void MainWindow::on_pushButton_15_clicked()
{
    Fournisseur F;
        QString crit=ui->comboBox_trie->currentText();
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
void MainWindow::on_pushButton_17_clicked()
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

void MainWindow::on_pushButton_14_clicked()
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

void MainWindow::on_pushButton_16_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
        QDesktopServices::openUrl(link);
}
//sameh
void MainWindow::on_ajouterf_clicked()
{
    QString numero=ui->le_NUMEROF->text();
    int montant=ui->le_Montantf->text().toInt();
    QString details=ui->le_Detailsf->text();
    QDate datee=ui->le_Dateef->date();

    Facture Fa(numero,montant,details,datee);
    bool test=Fa.ajouterf();
    QMessageBox msgBox;

    if(numero.size()==0)
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Le numero ne doit pas etre vide !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if (montant==0)
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Le montant ne doit pas etre vide !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else if (details.size()==0)
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("Les details  ne doivent pas etre vides !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else {

       /* notifier = new QSystemTrayIcon(this);
        //notifier = new QSystemTrayIcon(this);
            notifier->setIcon(QIcon(":/add.png"));
            notifier->show();*/

    if(test)
    {
        msgBox.setText("Ajout avec succés.");
        ui->tab_afficherf->setModel(Fa.afficherf());
       /* notifier->showMessage("Notification","Nouvelle Facture ajoutée",QSystemTrayIcon::Warning,10000);*/
    }
    else
        msgBox.setText("Echec d'ajout");
        msgBox.exec();
}}


// l'appel de la méthode afficher
void MainWindow::on_afficherf_clicked()
{
    Facture Fa;
    ui->tab_afficherf->setModel(Fa.afficherf());
}



//L'appel de la méthode supprimer
void MainWindow::on_supprimerf_clicked()
{
QString numero=ui->le_NUMERO_supp->text();
bool test=Fa.supprimerf(numero);
if(test)
{
    ui->tab_afficherf->setModel(Fa.afficherf());

    QMessageBox::information(nullptr, QObject::tr("Supprimer facture"),
                QObject::tr("Facture supprimée.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer facture"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}



//L'appel de méthode modifier
void MainWindow::on_modifierf_clicked()
{
    QString numero =ui->le_NUMERO_mod->text();
    int montant = ui->le_Montant_mod->text().toInt();
    QString details = ui->le_Details_mod->text();
    QDate datee = ui->le_Datee_mod->date();

    Facture Fa(numero,montant,details,datee);

            QSqlQuery query;

            bool test=Fa.modifierf();
            if(test)
            {
                ui->tab_afficher->setModel(Fa.afficherf());//refresh
                //ui->le_NUMERO_mod->setModel(F.afficher());
                QMessageBox::information(nullptr, QObject::tr("Modifier facture"),
                            QObject::tr("facture Modifier.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Supprimer facture"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }
            ui->le_Montant_mod->clear();
            ui->le_Details_mod->clear();
            ui->le_Datee_mod->clear();
}



void MainWindow::on_tri_clicked()
{
    ui->tab_afficherf->setModel(Fa.trifacture());
}


void MainWindow::on_rechercher_clicked()
{
    QString numero = ui->le_NUMERO_rechercherf->text();
    ui->tab_afficherf->setModel(Fa.rechercher(numero));
}


void MainWindow::on_pdf_clicked()
{
    //QDateTime datecreation = date.currentDateTime();
    //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
            QPdfWriter pdf("C:/Users/sameh/OneDrive/Documents/Facturation/Pdf.pdf");// l'emplacement de fichier ou va etre enregistrer
            QPainter painter(&pdf);
            int i = 4000;
               painter.setPen(Qt::blue);//la
               painter.setFont(QFont("Arial", 30)); //la police
               painter.drawText(1100,1200,"Liste Des fACTURES");
               painter.setPen(Qt::black); // définit la couleur utilisée pour tracer les lignes
               painter.setFont(QFont("Arial", 50));
              // painter.drawText(1100,2000,afficheDC);
               painter.drawRect(100,100,7300,2600);//dessiner un rectangle
               //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
               painter.drawRect(0,3000,9600,500);
               painter.setFont(QFont("Arial", 9));
               painter.drawText(200,3300,"NUMERO");//dessiner un text
               painter.drawText(1700,3300,"MONTANT");
               painter.drawText(3200,3300,"DATEE");
               painter.drawText(4900,3300,"DETAILS");

               QSqlQuery query;
               query.prepare("select * from FACTURE");
               query.exec();
               while (query.next())
               {
                   painter.drawText(200,i,query.value(0).toString());
                   painter.drawText(1700,i,query.value(1).toString());
                   painter.drawText(3200,i,query.value(2).toString());
                   painter.drawText(4900,i,query.value(3).toString());

                   i = i + 700;
               }
               int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                   if (reponse == QMessageBox::Yes)
                   {
                       QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/sameh/OneDrive/Documents/Facturation/Pdf.pdf"));
                       painter.end();
                   }
                   if (reponse == QMessageBox::No)
                   {
                        painter.end();
                   }
}

void MainWindow::sendMail(QString to,QString subject,QString message)
{
    Smtp* smtp = new Smtp("aura.forgetPass@gmail.com","Service100a", "smtp.gmail.com", 465);
        smtp->sendMail("aura.forgetPass@gmail.com", to , subject,message);
        QMessageBox::information(nullptr, QObject::tr("Email Envoye"),
                    QObject::tr("Votre email est envoye avec succée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from facture where montant < 1000 ");
        float montant=model->rowCount();
        model->setQuery("select * from facture where montant between 1000 and 5000 ");
        float montantt=model->rowCount();
        model->setQuery("select * from facture where montant>5000 ");
        float montanttt=model->rowCount();
        float total=montant+montantt+montanttt;
        QString a=QString("moins de 1000 "+QString::number((montant*100)/total,'f',2)+"%" );
        QString b=QString("entre 1000 et 5000 "+QString::number((montantt*100)/total,'f',2)+"%" );
        QString c=QString("+5000 "+QString::number((montanttt*100)/total,'f',2)+"%" );
        QPieSeries *series = new QPieSeries();
        series->append(a,montant);
        series->append(b,montantt);
        series->append(c,montanttt);
        if (montant!=0)
        {
            QPieSlice *slice = series->slices().at(0);
            slice->setLabelVisible();
            slice->setPen(QPen());
        }
        if ( montantt!=0)
        {
            // Add label, explode and define brush for 2nd slice
            QPieSlice *slice1 = series->slices().at(1);
            //slice1->setExploded();
            slice1->setLabelVisible();
        }
        if(montanttt!=0)
        {
            // Add labels to rest of slices
            QPieSlice *slice2 = series->slices().at(2);
            //slice1->setExploded();
             slice2->setLabelVisible();
        }
        // Create the chart widget
        QChart *chart = new QChart();
        // Add data to chart with title and hide legend
        chart->addSeries(series);
        chart->setTitle("Pourcentage Par montant:totale de "+ QString::number(total));
        chart->legend()->hide();
        // Used to display the chart
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(1000,500);
        chartView->show();
}


void MainWindow::on_sendBtn_clicked()
{
    sendMail(ui->toEmail->text(),ui->subject->text(),ui->msg->toPlainText());
}


void MainWindow::on_imprFact_clicked()
{
    QPrinter p;
    QPrintDialog pd(&p, 0);
    if (pd.exec() == QDialog::Accepted)
    {
        QPainter painter;
    painter.begin(&p);
    painter.drawImage(25, 25, QImage(":/images/logo"));
    QFont f;
    f.setPointSize(10);
    f.setBold(true);
    painter.setFont(f);

    //painter.drawText(1100,1200,"Facture du mois de Novembre");
    painter.drawText(300,75, "Facture du mois de Novembre");
    painter.drawText(100,150,"Numero de la facture :");//dessiner un text
    painter.drawText(100,300,"Montant de la facture :");
    painter.drawText(100,450,"Date de facturation :");
    painter.drawText(100,600,"Les details de la facture :");
    painter.end();
}
}

    /*{
        QString text="          ****** Les Facture  ******      \n \n " ;
        QSqlQuery query ;
        QString i,x,z,a;
        QString p="%p%";

         query.exec("select * from Facture");
         while (query.next())
         {
            i=query.value(0).toString();
            x=query.value(3).toString();
            z=query.value(2).toString();
            a=query.value(4).toString();

   if((a!=p) && (a!="0%"))
   {
       text += "\n Numéro facture : "+i+"\n\n - Montant: "+ x+"\n - Date : "+ z+"\n - Détails:"+a+"\n " ;
   }

        }

                return text ;
}*/





// les boutons de la calculatrice
void MainWindow::on_plus_clicked()
{
    ui->resultats->setText(QString::number(ui->n1->value() + ui->n2->value()));
}

void MainWindow::on_moins_clicked()
{
    ui->resultats->setText(QString::number(ui->n1->value() - ui->n2->value()));
}

void MainWindow::on_fois_clicked()
{
    ui->resultats->setText(QString::number(ui->n1->value() * ui->n2->value()));
}

void MainWindow::on_sur_clicked()
{
    ui->resultats->setText(QString::number(ui->n1->value() / ui->n2->value()));
}





/*void MainWindow::on_actionNouveau_triggered()
{
    currentFile.clear();
    ui->textEdit99->setText(QString());
}

void MainWindow::on_actionEnregistrer_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer sous..");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "probléme", "Pas d'enregistrement de fichier" + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit99->toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_actionQuitter_triggered()
{
    close();
}

void MainWindow::on_actionOuvrir_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Ouvrir le fichier");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Probléme", "fichier non ouvrir " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit99->setText(text);
    file.close();
}

void MainWindow::on_actionImprimer_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Nom de l'imprimente");
    QPrintDialog pDialog(&printer, this);
    if(pDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this, "Probleme", "Pas de connexion avec l'imprimente");
        return;
    }
    ui->textEdit99->print(&printer);
}

void MainWindow::on_actionCopier_triggered()
{
    ui->textEdit99->copy();
}

void MainWindow::on_actionColler_triggered()
{
    ui->textEdit99->paste();
}

void MainWindow::on_actionCouper_triggered()
{
    ui->textEdit99->cut();
}
*/
//saaaaaaaaaaaaafffaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
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

void MainWindow::on_pb_modifier_2_clicked()
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
       Cl.alerte_clients_fidele();

}

//**************************zeinabbbbbbb***********************************

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
  if(test){
    serv.ajouter();
      msgBox.setText("Ajout avec succes.");
  }
  else msgBox.setText("Echec de l'ajout");
  msgBox.exec();
}



void MainWindow::on_pushButton_2_service_clicked()
{
   int id;
   service s;
   id = this->ui->spinBox_3->value();
   s=s.select(id);
   this->ui->le_type_service->setText(s.getType());
   this->ui->spinBox_6->setValue(s.getTarifs());
   this->ui->le_offres_service->setText(s.getOffre());
   this->ui->le_dispo_service->setText(s.getDisponibilite());
   this->ui->DATE->setDate(s.getHoraire());
   this->ui->spinBox_7->setValue(s.getID_employer());
}

void MainWindow::on_pb_supprimer_service_clicked()
{
   service S1; S1.setId(ui->id_supp->text().toInt());
   bool test=S1.supprimer(S1.getId());
   QMessageBox msgBox;
    if(test)
        msgBox.setText("Suppression avec succes.");
    else msgBox.setText("Echec de suppression");
    msgBox.exec();


}

void MainWindow::on_pb_modifier_service_clicked()
{
  service S;
  S.setId(this->ui->spinBox_3->value());
  S.setType(this->ui->lineEdit_11->text());
  S.setTarifs(this->ui->spinBox_6->value());
  S.setDisponibilite(this->ui->lineEdit_13->text());
  S.setOffres(this->ui->lineEdit_12->text());
  S.setHoraire(this->ui->DATE->date());
  S.setID_employer(this->ui->spinBox_7->value());

  bool test= controle_saisie();
  QMessageBox msgBox;
   if(true){
     S.modifier(S);
       msgBox.setText("Modifier avec succes.");
   }
   else msgBox.setText("Echec de la modification");
   msgBox.exec();

}



void MainWindow::on_PbRecherche_clicked()
{
    this->detail.show();
    this->hide();
    this->detail.pa=this;
    service s;
    QVector<service> t = s.ListService();
    this->detail.buildtable(t);
    this->detail.response=t;

}

void MainWindow::on_imprFact_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}
