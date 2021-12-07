#include "fournisseur.h"
#include "connection.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>

Fournisseur::Fournisseur()
{
  id=0;num_tel=0;nom_societe=" ";type_produit=" ";adresse_mail=" ";adresse_local=" ";
}

Fournisseur::Fournisseur(int id,int num_tel,QString nom_societe,QString type_produit,QString adresse_mail,QString adresse_local)
{this->id=id;this->num_tel=num_tel; this->nom_societe=nom_societe; this->type_produit=type_produit;this->adresse_mail=adresse_mail;this->adresse_local=adresse_local;}
int Fournisseur::getid(){return id;}
int Fournisseur::getnum_tel(){return num_tel;}
QString Fournisseur::getnom_societe(){return nom_societe;}
QString Fournisseur::gettype_produit(){return type_produit;}
QString Fournisseur::getadresse_mail(){return adresse_mail;}
QString Fournisseur::getadresse_local(){return adresse_local;}
void Fournisseur::setid(int id){this->id=id;}
void Fournisseur::setnum_tel(int num_tel){this->num_tel=num_tel;}
void Fournisseur::setnom_societe(QString nom_societe){this->nom_societe=nom_societe;}
void Fournisseur::settype_produit(QString type_produit){this->type_produit=type_produit;}
void Fournisseur::setadresse_mail(QString adresse_mail){this->adresse_mail=adresse_mail;}
void Fournisseur::setadresse_local(QString adresse_local){this->adresse_local=adresse_local;}
bool Fournisseur::ajouter()
{

    QString id_string= QString::number(id);
                QString num_tel_string= QString::number(num_tel);
    QSqlQuery query;
          query.prepare("INSERT INTO fournisseur (id, num_tel,nom_societe,type_produit,adresse_mail,adresse_local ) "
                        "VALUES (:id, :num_tel, :nom_societe, :type_produit, :adresse_mail, :adresse_local)");
          query.bindValue(0, id_string);
          query.bindValue(1, num_tel_string);
          query.bindValue(2, nom_societe);
          query.bindValue(3, type_produit);
          query.bindValue(4, adresse_mail);
          query.bindValue(5, adresse_local);


    return query.exec();
}
bool Fournisseur::supprimer(int id)
{
    QSqlQuery query;
          query.prepare("Delete from fournisseur where id=:id" );
          query.bindValue(0, id);
    return query.exec();
}
QSqlQueryModel* Fournisseur::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM fournisseur");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Num_tel"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom_societe"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type_produit"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse_mail"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Adresse_local"));
    return model;
}
bool Fournisseur::modifier(int id)
    {
        Connection c;
        c.createconnect();

    QSqlQuery query;
     query.prepare("Update fournisseur set Num_tel= :Num_tel, Type_Produit= :Type_produit , Adresse_mail= :Adresse_mail , Adresse_local= :Adresse_local , Nom_societe= :Nom_societe   where ID= :ID ");

     query.bindValue(":ID",id);
     query.bindValue(":Num_tel", num_tel);
     query.bindValue(":Type_produit", type_produit);
     query.bindValue(":Adresse_mail", adresse_mail);
     query.bindValue(":Adresse_local", adresse_local);
     query.bindValue(":Nom_societe", nom_societe);

    return query.exec();
    }
QSqlQueryModel * Fournisseur::chercherid(QString id)
{
QSqlQueryModel * model = new QSqlQueryModel();
QSqlQuery query;
query.prepare("select * from fournisseur WHERE id = :id");
query.bindValue(":id",id);
query.exec();
model ->setQuery(query);
model ->setHeaderData(0,Qt::Horizontal,"ID");
model ->setHeaderData(1,Qt::Horizontal,"Num_tel");
model ->setHeaderData(2,Qt::Horizontal,"Type_produit");

return model;
}
QSqlQueryModel * Fournisseur::chercherType_produit(QString Type_produit)
{
QSqlQueryModel * model = new QSqlQueryModel();
QSqlQuery query;
query.prepare("select * from fournisseur WHERE Type_produit = :Type_produit");
query.bindValue(":Type_produit",Type_produit);
query.exec();
model ->setQuery(query);
model ->setHeaderData(0,Qt::Horizontal,"ID");
model ->setHeaderData(1,Qt::Horizontal,"Num_tel");
model ->setHeaderData(2,Qt::Horizontal,"Type_produit");

return model;
}
QSqlQueryModel *Fournisseur:: trieid()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from fournisseur order by ID" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_societe"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Num_tel"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type_produit"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse_mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Adresse_local"));

 return model;

}
QSqlQueryModel *Fournisseur:: trieType_produit()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from fournisseur order by Type_produit" );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_societe"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Num_tel"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Type_produit"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse_mail"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Adresse_local"));


 return model;

}
void Fournisseur::statistique(QVector<double>* ticks,QVector<QString> *labels)
{
    QSqlQuery q;
    int i=0;
    q.exec("select id from FOURNISSEUR");
    while (q.next())
    {
        QString identifiant = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<identifiant;
    }

}
