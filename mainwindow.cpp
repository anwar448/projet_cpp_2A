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

ui->verticalLayout->addWidget(C.stat());
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

void MainWindow::on_tabWidget_3_tabBarClicked(int index)
{
    if (index==6)
        ui->verticalLayout->update();
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
