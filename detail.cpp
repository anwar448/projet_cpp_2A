#include "detail.h"
#include "ui_detail.h"
#include "googlesuggest.h"
#include <QtPrintSupport/QtPrintSupport>
#include <QtPrintSupport/QPrintDialog>
#include <QMessageBox>





Detail::Detail(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Detail)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/BERTRAND/Desktop/projet2A/Maquette_du_projet2A/abc.png");
    ui->image4->setPixmap(pix);
    QPixmap pixs("C:/Users/BERTRAND/Desktop/projet2A/Maquette_du_projet2A/f.png");
    ui->image5->setPixmap(pixs);

    this->ui->lineEdit->setFocus();
    this->search.setParent(this);
    this->search.setGeometry(80,130,250,30);
    GSuggestCompletion *g = new GSuggestCompletion;
    g->d=this;
    this->search.det= g;
    int return_arduino = this->arduino.connect_arduino();
    switch (return_arduino) {
    case(0):qDebug()<< "arduino est active et est connecte a :" <<this->arduino.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino est active mais pas connecte a :" <<this->arduino.getarduino_port_name();
        break;
    case(-1):qDebug() << "arduino n'est pas active";
    }

    connect(this->arduino.getserial(),SIGNAL(readyRead()), this, SLOT(check_available()));
    qDebug()<<this->arduino.getserial();

}

Detail::~Detail()
{
    delete ui;
}

void Detail::buildtable(QVector<service> t)
{
    QVector<service>::Iterator it;
    this->ui->tableWidget->clearContents();
    this->ui->tableWidget->setRowCount(t.count());
    this->ui->tableWidget->setColumnCount(7);
    int index(0);
    for (it=t.begin();it!=t.end();it++) {
          this->ui->tableWidget->setItem(index,0, new QTableWidgetItem(QString::number(it->getId())));
          this->ui->tableWidget->setItem(index,1, new QTableWidgetItem(it->getType()));
          this->ui->tableWidget->setItem(index,2, new QTableWidgetItem(it->getOffre()));
          this->ui->tableWidget->setItem(index,3, new QTableWidgetItem(QString::number(it->getTarifs())));
          this->ui->tableWidget->setItem(index,4, new QTableWidgetItem(it->getHoraire().toString()));
          this->ui->tableWidget->setItem(index,5, new QTableWidgetItem(it->getDisponibilite()));
          this->ui->tableWidget->setItem(index,6, new QTableWidgetItem(QString::number(it->getID_employer())));
          index++;

    }
}

QString Detail::buildRequest()
{
    QString order ="";
    QDate dateInit = QDate(2000,01,01);
    QString request= "select* from SERVICES where ";
    if(this->ui->radionom->isChecked()){
        request += " offres ='"+this->ui->lineEdit->text()+"'";
        order = " offres";
    }else{
        request += " type ='"+this->ui->lineEdit->text()+"'";
         order = " type";
    }

    if(this->ui->dateSup->date() !=dateInit){
        request +=" and horaire > '"+ this->ui->dateSup->date().toString("dd/MM/yyyy") +"' ";
    }else if(this->ui->dateInf->date() !=dateInit){
         request +=" and horaire < '"+ this->ui->dateInf->date().toString()+"' ";
    } else if(this->ui->dateEgale->date() !=dateInit){
    request +=" and horaire < '"+ this->ui->dateEgale->date().toString()+"' ";
    }
    if(this-ui->radioAlphaCroissant->isChecked()){
        request +=" order by "+ order +" asc;";
    }else {
         request +=" order by "+ order +" desc;";
    }

    qDebug()<<request<<dateInit;

    return request;
}

void Detail::on_PbReturn_clicked()
{
    this->pa->show();
    this->close();
}

void Detail::on_pushButton_2_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desired printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)return;
    ui->tableWidget->render(&printer);

}

void Detail::on_PbSearch_clicked()
{
    QString request = this->buildRequest();
    service s;
    QVector<service> t= s.ListService(request);
    this->buildtable(t);
    this->response=t;

}

void Detail::on_radionom_clicked()
{
    if(this->ui->radionom->isChecked()){
        this->ui->radiotype->setChecked(false);
    }
}

void Detail::on_mailling_clicked()
{

    QString link="https://www.facebook.com/Smart-Beauty-107622421749427";
    QDesktopServices::openUrl(link);
}







void Detail::on_comboBox_2_currentIndexChanged(int index)
{
    QVector<service>::Iterator it;

    if(this->ui->comboBox_2->currentIndex()==1){
        this->ui->tableWidget->clear();
        std::sort(this->response.begin(), this->response.end(),service::alphaDescCompareNom);
        this->buildtable(this->response);
        for (it=this->response.begin();it<this->response.end();++it) {
            qDebug()<<it->getType()<<" ;";
        }

    }else if(this->ui->comboBox_2->currentIndex()==2){
        this->ui->tableWidget->clear();
        std::sort(this->response.begin(), this->response.end(),service::alphaAscCompareNom);
        this->buildtable(this->response);
        for (it=this->response.begin();it<this->response.end();++it) {
            qDebug()<<it->getType()<<" ;";
        }
    }else if(this->ui->comboBox_2->currentIndex()==3){
        this->ui->tableWidget->clear();
        std::sort(this->response.begin(), this->response.end(),service::alphaAscCompareTarifs);
        this->buildtable(this->response);
    }else if(this->ui->comboBox_2->currentIndex()==4){

        this->ui->tableWidget->clear();
        std::sort(this->response.begin(), this->response.end(),service::alphaDesCompareTarifs);
        this->buildtable(this->response);
    }

    qDebug()<<"idriss tu es fatiguer "<<this->ui->comboBox_2->currentIndex()<<" : "<<index;
}

void Detail::check_available()
{
    this->data_recive_form_arduino = arduino.read_from_arduino();
    QVector<service>::Iterator jt;
    QVector<service>::Iterator it;
    bool resultat =false;
    bool trouve = false;
    QByteArray res;

    int total =0;
    qDebug()<<"la valeur lu est: "<<this->data_recive_form_arduino;
    QString response = this->data_recive_form_arduino;
    QString resp;
    if(response == '1'){
        resp= "lissage";
    };

    for (it =this->response.begin(); it != this->response.end() ; ++it) {
       if(it->getOffre() == resp){
           this->panier.push_back(*it);
           for (jt=panier.begin(); jt != panier.end(); ++jt) {
               total+=jt->getTarifs();
           }
           resultat = true;
           trouve = true;
           break;
       }
    }
    if(resultat==true){
        qDebug()<<"on retour la l'etat de la facture ";
        this->arduino.write_to_arduino(res.setNum(total));

    }else{
        qDebug()<<"je dois ecris f";
        this->arduino.write_to_arduino("f");

    }
}

