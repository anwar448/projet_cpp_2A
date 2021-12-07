#include "clients.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include "connection.h"
#include <QString>
#include <QSqlQueryModel>
#include <QSystemTrayIcon>
#include <QMessageBox>


Clients::Clients()
{
ID_C=0;
nom="";
prenom="";
genre="";
adresse_maison="";
num_tel=0;
email="";
date_visite="";
nbr_visite=0;

}

Clients::Clients(int ID_C,QString nom,QString prenom,QString genre,QString adresse_maison,int num_tel,QString email,QString date_visite,int nbr_visite)
{this->ID_C=ID_C;this->nom=nom;this->prenom=prenom;this->genre=genre;this->adresse_maison=adresse_maison;this->num_tel=num_tel;this->email=email;this->date_visite=date_visite;this->nbr_visite=nbr_visite;}

int Clients::getID_C(){return ID_C;}
QString Clients::getnom(){return nom;}
QString Clients::getprenom(){return prenom;}
QString Clients::getgenre(){return genre;}
QString Clients::getadresse_maison(){return adresse_maison;}
int Clients::getnum_tel(){return num_tel;}
QString Clients::getemail(){return email;}
QString Clients::getdate_visite(){return date_visite;}
int Clients::getnbr_visite(){return nbr_visite;}


void Clients::setID_C(int ID_C){this->ID_C=ID_C;}
void Clients::setnom(QString nom){this->nom=nom;}
void Clients::setprenom(QString prenom){this->prenom=prenom;}
void Clients::setgenre(QString genre){this->genre=genre;}
void Clients::setadresse_maison(QString adresse_maison){this->adresse_maison=adresse_maison;}
void Clients::setnum_tel(int num_tel){this->num_tel=num_tel;}
void  Clients::setemail(QString email){this->email=email;}
void Clients::setdate_visite(QString date_visite){this->date_visite=date_visite;}
void Clients::setnbr_visite(int nbr_visite){this->nbr_visite=nbr_visite;}


bool Clients::ajouter_clients()
{
    Connection c;
    c.ouvrirConnexion();

    QString cin_string= QString::number(ID_C);

    QSqlQuery query;
          query.prepare("INSERT INTO CLIENTS (ID_C, NOM, PRENOM, GENRE, ADRESSE_MAISON , NUM_TEL, EMAIL, DATE_VISITE, NBR_VISITE ) VALUES (:ID_C, :NOM, :PRENOM, :GENRE, :ADRESSE_MAISON , :NUM_TEL, :EMAIL, :DATE_VISITE, :NBR_VISITE )");
         query.bindValue(0,ID_C);
          query.bindValue(1, nom);
          query.bindValue(2, prenom);
           query.bindValue(3, genre);
            query.bindValue(4, adresse_maison);
             query.bindValue(5, num_tel);
              query.bindValue(6, email);
               query.bindValue(7, date_visite);
                query.bindValue(8, nbr_visite);


          return query.exec();
}



QSqlQueryModel* Clients::afficher()
{
    Connection c;
    c.ouvrirConnexion();
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM clients");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_C"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("genre"));

          model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse_maison"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("num_tel"));

          model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("date_visite"));
          model->setHeaderData(8, Qt::Horizontal, QObject::tr("nbr_visite"));


    return model;
}


bool Clients::supprimer(int ID_C)
{
    Connection c;
    c.ouvrirConnexion();

    QSqlQuery query;


    query.prepare("DELETE FROM CLIENTS WHERE ID_C=:ID_C ");
    query.bindValue(":ID_C",ID_C);

    return query.exec();
}

bool Clients::modifier(int ID_C)
{
    Connection c;
    c.ouvrirConnexion();
    QSqlQuery query;
     query.prepare("Update clients set nom= :nom, prenom= :prenom , genre= :genre , adresse_maison= :adresse_maison , num_tel= :num_tel , email= :email , date_visite= :date_visite , nbr_visite= :nbr_visite   where ID_C= :ID_C ");

     query.bindValue(":ID_C",ID_C);
     query.bindValue(":nom", nom);
     query.bindValue(":prenom", prenom);
     query.bindValue(":genre", genre);
     query.bindValue(":adresse_maison", adresse_maison);
     query.bindValue(":num_tel", num_tel );
      query.bindValue(":email", email);
       query.bindValue(":date_visite", date_visite);
        query.bindValue(":nbr_visite", nbr_visite);
    return query.exec();




}
QSqlQueryModel * Clients :: trierNom()
    {
        QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from Clients ORDER BY Nom");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_C"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("genre"));

        model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse_maison"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("num_tel"));

        model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("date_visite"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("nbr_visite"));


        return model;
    }
QSqlQueryModel * Clients:: rechercheNom(QString x)
    {
        QSqlQuery query;
        query.prepare("select * from Clients where Nom=:Nom");
        query.bindValue(":Nom",x);
        query.exec();
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery(query);
     return model;
    }
/*
void Clients::statistique(QVector<double>* ticks,QVector<QString> *labels)
{
QSqlQuery q;
    int i=0;
    q.exec("select Id_C  from clients");
    while (q.next())
    {
        QString identifiant = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<identifiant;
    }
}

*/

void Clients :: alerte_clients_fidele()
{
    QSqlQuery qry;
    if (qry.exec("select * from Clients WHERE nbr_visite >= 10"))
    {
        int n=0;
        while(qry.next())
        {n=qry.value(8).toInt();
            qDebug () <<n;
            n= qry.value(2).toInt();
            if(n>10)
            {
                QSystemTrayIcon *alerteIcon = new QSystemTrayIcon();
                alerteIcon->setIcon(QIcon(":/new/prefixe/dawnload.png"));
                alerteIcon->show();
                alerteIcon->showMessage("Gestion des clients","clients fidele",QSystemTrayIcon::Information,15000);



            }


      }

  }
}















