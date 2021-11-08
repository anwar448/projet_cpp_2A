#ifndef SERVICE_H
#define SERVICE_H
#include <QString>
#include <QTime>
#include <QtSql>
#include <QSqlQuery>
class service
{
    //definition des attributs
    private:
    int id;
    float tarifs;
    QString type;
    QString offre;
    QString disponibilite;
    QDate horaire;
    int ID_employer;

    //definition des setter et getter
public:
    int getId();
    int getTarifs();
    QString getType();
    QString getOffre();
    QString getDisponibilite();
    QDate getHoraire();
    int getID_employer();
    void setId(int id);
    void setTarifs(int tarifs);
    void setType(QString type);
    void setOffres(QString offre);
    void setDisponibilite(QString disponibilite);
    void setHoraire(QDate horaire);
    void setID_employer(int ID_employer);



    //implementation des fonctions


public:
    service();
    service(int id,float tarifs, QString type, QString  offre,QString disponibilite, QDate horaire, int ID_employer );
     QString  collecter ();
     bool ajouter();
     bool modifier(service a);
     bool supprimer();
     bool afficher();
     service select(int id);

};


#endif // SERVICE_H
