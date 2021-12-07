#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "facture.h"
#include <QMessageBox>
#include <QIntValidator>
#include <connection.h>
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

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow()
    : QMainWindow()
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/sameh/Downloads/Facturation/Facturation/slider-facture.png");
    ui->image->setPixmap(pix);
    ui->image1->setPixmap(pix);
    ui->image2->setPixmap(pix);
    ui->image3->setPixmap(pix);
    ui->image4->setPixmap(pix);
    ui->image5->setPixmap(pix);
    ui->image6->setPixmap(pix);

    ui->tab_afficher->setModel(F.afficher());

    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

//L'appel de la méthode ajouter
void MainWindow::on_ajouter_clicked()
{
    QString numero=ui->le_NUMERO->text();
    int montant=ui->le_Montant->text().toInt();
    QString details=ui->le_Details->text();
    QDate datee=ui->le_Datee->date();

    Facture F(numero,montant,details,datee);

    bool test=F.ajouter();

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

        notifier = new QSystemTrayIcon(this);
        //notifier = new QSystemTrayIcon(this);
            notifier->setIcon(QIcon(":/add.png"));
            notifier->show();

    if(test)
    {
        msgBox.setText("Ajout avec succés.");
        ui->tab_afficher->setModel(F.afficher());
        notifier->showMessage("Notification","Nouvelle Facture ajoutée",QSystemTrayIcon::Warning,10000);
    }
    else
        msgBox.setText("Echec d'ajout");
        msgBox.exec();
}}


// l'appel de la méthode afficher
void MainWindow::on_afficher_clicked()
{
    Facture F;
    ui->tab_afficher->setModel(F.afficher());
}



//L'appel de la méthode supprimer
void MainWindow::on_supprimer_clicked()
{
QString numero=ui->le_NUMERO_supp->text();
bool test=F.supprimer(numero);
if(test)
{
    ui->tab_afficher->setModel(F.afficher());

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
void MainWindow::on_modifier_clicked()
{
    QString numero =ui->le_NUMERO_mod->text();
    int montant = ui->le_Montant_mod->text().toInt();
    QString details = ui->le_Details_mod->text();
    QDate datee = ui->le_Datee_mod->date();

    Facture F(numero,montant,details,datee);

            QSqlQuery query;

            bool test=F.modifier();
            if(test)
            {
                ui->tab_afficher->setModel(F.afficher());//refresh
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
    ui->tab_afficher->setModel(F.trifacture());
}


void MainWindow::on_rechercher_clicked()
{
    QString numero = ui->le_NUMERO_rechercher->text();
    ui->tab_afficher->setModel(F.rechercher(numero));
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





void MainWindow::on_actionNouveau_triggered()
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
