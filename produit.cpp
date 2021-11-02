#include "produit.h"
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QSqlQueryModel>
#include <QObject>
#include <connection.h>

Produit::Produit()
{
    ID=0;
    Nom="";
    Type="";
    Nombre=0;
    Delai="";
    Prix="";
}

Produit::Produit(int id,QString nom,QString type,int nombre,QString delai,QString prix)
{
 ID=id;
 Nom=nom;
 Type=type;
 Nombre=nombre;
 Delai=delai;
 Prix=prix;
}
    void Produit::setID(int n){ID=n;}
    void Produit::setNom(QString n){Nom=n;}
    void Produit::setType(QString n){Type=n;}
    void Produit::setNombre(int n){Nombre=n;}
    void Produit::setDelai(QString n){Delai=n;}
    void Produit::setPrix(QString n){Prix=n;}

    int     Produit::getID(){return ID;}
    QString Produit::getNom(){return Nom;}
    QString Produit::getType(){return Type;}
    int     Produit::getNombre(){return Nombre;}
    QString Produit::getDelai(){return Delai;}
    QString   Produit::getPrix(){return Prix;}


    bool Produit::ajouter()
    {

        Connection c;
        c.createconnect();
            /*QString ID_string= QString::number(ID);
            QString Nombre_string= QString::number(Nombre);
            QString Prix_string= QString::number(Prix);*/

            QSqlQuery query;
             query.prepare("INSERT INTO produit (ID, Nom, Type_Produit, Nombre, delai, Prix) "
                           "VALUES (:ID, :Nom, :Type, :Nombre, :Delai, :Prix)");
             query.bindValue(":ID", ID);
             query.bindValue(":Nom", Nom);
             query.bindValue(":Type", Type);
             query.bindValue(":Nombre", Nombre);
             query.bindValue(":Delai", Delai);
             query.bindValue(":Prix", Prix);

            return query.exec();
    }


    bool Produit::supprimer(int ID)
    {
        Connection c;
        c.createconnect();
    QSqlQuery query;
     query.prepare("Delete FROM produit where ID= :ID ");

     query.bindValue(":ID",ID);
    return query.exec();
    }

    QSqlQueryModel* Produit::afficher()
    {
        Connection c;
        c.createconnect();
        QSqlQueryModel* model=new QSqlQueryModel();

              model->setQuery("SELECT * FROM produit");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identification"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nombre"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("Delai"));
              model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix"));
        return model;
    }

    bool Produit::modifier(int ID)
    {
        Connection c;
        c.createconnect();

    QSqlQuery query;
     query.prepare("Update produit set Nom= :Nom, Type_Produit= :Type , Nombre= :Nombre , delai= :Delai , Prix= :Prix   where ID= :ID ");

     query.bindValue(":ID",ID);
     query.bindValue(":Nom", Nom);
     query.bindValue(":Type", Type);
     query.bindValue(":Nombre", Nombre);
     query.bindValue(":Delai", Delai);
     query.bindValue(":Prix", Prix);
    return query.exec();
    }
