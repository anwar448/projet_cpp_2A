#ifndef FACTURE_H
#define FACTURE_H

#include <QString>
#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDate>

class Facture
{
public:
    Facture();
    Facture(QString,int,QString,QDate);
    QString get_numero();
    int get_montant();
    QString get_details();
    QDate get_datee();

    bool ajouterf();
    QSqlQueryModel * afficherf();
    bool modifierf();
    bool supprimerf(QString);
    QSqlQueryModel * trifacture();
    QSqlQueryModel * rechercher(QString);
private:
    QString numero,details;
    int montant;
    QDate datee;
};

#endif // EMPLOYE_H


