#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QString>
#include <QSqlQueryModel>
#include "ui_mainwindow.h"
class Fournisseur
{
public:
    Fournisseur();
    Fournisseur(int,int,QString,QString,QString,QString);
    int getid();
    int getnum_tel();
    QString getnom_societe();
    QString gettype_produit();
    QString getadresse_mail();
    QString getadresse_local();
    void setid(int);
    void setnum_tel(int);
    void setnom_societe(QString);
    void settype_produit(QString);
    void setadresse_mail(QString);
    void setadresse_local(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier (int);
    QSqlQueryModel * chercherid(QString id);
    QSqlQueryModel * chercherType_produit(QString type_produit);
    QSqlQueryModel * trieid();
    QSqlQueryModel * trieType_produit();
    void statistique(QVector<double>* ticks,QVector<QString> *labels);

private:
    int id,num_tel;
    QString nom_societe,type_produit,adresse_mail,adresse_local;

};

#endif // FOURNISSEUR_H
