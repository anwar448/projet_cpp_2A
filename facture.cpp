#include "facture.h"
#include <QDebug>
#include "connection.h"

Facture::Facture()
{
    numero = "";
    montant = 0;
    details = "";
    datee = QDate();
}

Facture::Facture(QString numero,int montant,QString details,QDate datee)
{
  this->numero=numero;
  this->montant=montant;
  this->details=details;
  this->datee=datee;
}

QString Facture::get_numero(){return numero;}
int Facture::get_montant(){return montant;}
QString Facture::get_details(){return details;}
QDate Facture::get_datee(){return datee;}

bool Facture::ajouterf()
{
    QSqlQuery query;
    query.prepare("INSERT INTO FACTURE (NUMERO, MONTANT, DETAILS, DATEE)" "VALUES (:numero, :montant, :details, :datee)");
    query.bindValue(":numero", numero);
    query.bindValue(":montant", montant);
    query.bindValue(":details", details);
    query.bindValue(":datee", datee);
    return query.exec();
}

QSqlQueryModel * Facture::afficherf()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from FACTURE ;");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("NUMERO"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("MONTANT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("DETAILS"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("DATEE"));
return model;
}

bool Facture::supprimerf(QString numero)
{
    QSqlQuery query;
    query.prepare("DELETE FROM FACTURE WHERE NUMERO= :numero");
    query.bindValue(":numero",numero);
return query.exec();
}

bool Facture::modifierf()
 {      QSqlQuery query;
        query.prepare("UPDATE FACTURE SET NUMERO=:numero,MONTANT=:montant,DETAILS=:details,DATEE=:datee where NUMERO=:numero;");
        query.bindValue(":numero",numero);
        query.bindValue(":montant",montant);
        query.bindValue(":details",details);
        query.bindValue(":datee",datee);
        return    query.exec();
}


QSqlQueryModel * Facture::trifacture()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM FACTURE ORDER BY MONTANT DESC");
model->setHeaderData(0, Qt::Horizontal,QObject::tr("NUMERO"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("MONTANT"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("DETAILS"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("DATEE"));
    return model;
}


QSqlQueryModel * Facture::rechercher(QString numero)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from facture where numero like ?");
    q.addBindValue("%"+ numero +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}


























