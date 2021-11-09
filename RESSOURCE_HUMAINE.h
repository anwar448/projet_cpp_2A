#ifndef RESSOURCE_HUMAINE_H
#define RESSOURCE_HUMAINE_H

#include <QString>
#include <QSqlQueryModel>
class RESSOURCE_HUMAINE
{
public:
    RESSOURCE_HUMAINE();
    RESSOURCE_HUMAINE(QString,QString,QString,QString,int);
    QString getcin();
    QString getnom();
    QString getprenom();
    QString getAFFECTATION_SERVICE();
    int getNOMBRE_HEURE_DE_TRAVAIL();

    void setcin(QString);
    void setnom(QString);
    void setprenom(QString);
    void setAFFECTATION_SERVICE(QString);
    void setNOMBRE_HEURE_DE_TRAVAIL(int);


    bool ajouter();
    QSqlQueryModel*  afficher();
    bool supprimer(int);
    bool modifier(QString);



private :

    int NOMBRE_HEURE_DE_TRAVAIL;
    QString cin, nom, prenom,AFFECTATION_SERVICE;
};


#endif // RESSOURCE_HUMAINE_H
