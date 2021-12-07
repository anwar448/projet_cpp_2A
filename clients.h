#ifndef CLIENTS_H
#define CLIENTS_H

#include <QString>
#include <QSqlQueryModel>
class Clients
{
public:
    Clients();
    Clients(int,QString,QString,QString,QString,int,QString,QString,int);
    int getID_C();
    QString getnom();
    QString getprenom();
    QString getgenre();
    QString getadresse_maison();
    int getnum_tel();
    QString  getemail();
    QString getdate_visite();
    int getnbr_visite();


    void setID_C(int);
    void setnom(QString);
    void setprenom(QString);
    void setgenre(QString);
    void setadresse_maison(QString);
    void setnum_tel(int);
    void  setemail(QString);
    void setdate_visite(QString);
    void setnbr_visite(int);
    bool ajouter_clients();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
   QSqlQueryModel *  trierNom();
   QSqlQueryModel * rechercheNom(QString x);
   /*void statistique(QVector<double>* ticks,QVector<QString> *labels);*/
   void alerte_clients_fidele();








 private:
    int ID_C,num_tel,nbr_visite;
    QString nom, prenom, genre ,adresse_maison ,email ,date_visite;

};

#endif // CLIENTS_H
