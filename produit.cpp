#include "produit.h"
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QSqlQueryModel>
#include <QObject>
#include <connection.h>
#include <QMessageBox>

Produit::Produit()
{
    ID=0;
    Nom="";
    Type="";
    Quantite=0;
    Delai="";
    Prix="";
}

Produit::Produit(int id,QString nom,QString type,int quantite,QString delai,QString prix)
{
 ID=id;
 Nom=nom;
 Type=type;
 Quantite=quantite;
 Delai=delai;
 Prix=prix;
}
    void Produit::setID(int n){ID=n;}
    void Produit::setNom(QString n){Nom=n;}
    void Produit::setType(QString n){Type=n;}
    void Produit::setQuantite(int n){Quantite=n;}
    void Produit::setDelai(QString n){Delai=n;}
    void Produit::setPrix(QString n){Prix=n;}

    int     Produit::getID(){return ID;}
    QString Produit::getNom(){return Nom;}
    QString Produit::getType(){return Type;}
    int     Produit::getQuantite(){return Quantite;}
    QString Produit::getDelai(){return Delai;}
    QString   Produit::getPrix(){return Prix;}


    bool Produit::ajouter()
    {

        Connection c;
        c.createconnect();
            /*QString ID_string= QString::number(ID);
            QString Quantite_string= QString::number(Quantite);
            QString Prix_string= QString::number(Prix);*/

            QSqlQuery query;
             query.prepare("INSERT INTO produit (ID_produit, Nom, Type, Quantite, Delai, Prix) "
                           "VALUES (:ID, :Nom, :Type, :Quantite, :Delai, :Prix)");
             query.bindValue(":ID", ID);
             query.bindValue(":Nom", Nom);
             query.bindValue(":Type", Type);
             query.bindValue(":Quantite", Quantite);
             query.bindValue(":Delai", Delai);
             query.bindValue(":Prix", Prix);

            QString ID_string= QString::number(ID);
            QString Quantite_string= QString::number(Quantite);

             if((ID_string.isEmpty())||(Nom.isEmpty())||(Type.isEmpty())||(Quantite_string.isEmpty())||(Delai.isEmpty())||(Prix.isEmpty()))
             {
                 QMessageBox messageBox;
                 messageBox.critical(0,"Error","An error has occured !");
                 messageBox.setFixedSize(500,200);
                 return false;
             }

            return query.exec();
    }


    bool Produit::supprimer(int ID)
    {
        Connection c;
        c.createconnect();
    QSqlQuery query;
     query.prepare("Delete FROM produit where ID_Produit= :ID ");

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
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("Delai"));
              model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix"));
        return model;
    }

    bool Produit::modifier(int ID)
    {
        Connection c;
        c.createconnect();

    QSqlQuery query;
     query.prepare("Update produit set Nom= :Nom, Type= :Type , Quantite= :Quantite , delai= :Delai , Prix= :Prix   where ID_Produit= :ID ");

     query.bindValue(":ID",ID);
     query.bindValue(":Nom", Nom);
     query.bindValue(":Type", Type);
     query.bindValue(":Quantite", Quantite);
     query.bindValue(":Delai", Delai);
     query.bindValue(":Prix", Prix);

     QString ID_string= QString::number(ID);
     QString Quantite_string= QString::number(Quantite);

      if((ID_string.isEmpty())||(Nom.isEmpty())||(Type.isEmpty())||(Quantite_string.isEmpty())||(Delai.isEmpty())||(Prix.isEmpty()))
      {
          QMessageBox messageBox;
          messageBox.critical(0,"Error","An error has occured !");
          messageBox.setFixedSize(500,200);
          return false;
      }

    return query.exec();
    }

    bool Produit:: recherche(int id)
    {
        QSqlQuery query;
        query.prepare("select * from Produit where ID_produit=:id");
        query.bindValue(":id",id);
        return query.exec() ;
    }

    QSqlQueryModel * Produit :: trierDelai()
    {
        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from Produit ORDER BY Delai");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Delai"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Delai"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix"));
        return model;
    }
