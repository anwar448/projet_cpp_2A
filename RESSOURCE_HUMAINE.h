#ifndef RESSOURCE_HUMAINE_H
#define RESSOURCE_HUMAINE_H

#include <QString>
#include <QSqlQueryModel>
#include <QtCharts>
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
    float getprix();

    void setcin(QString);
    void setnom(QString);
    void setprenom(QString);
    void setAFFECTATION_SERVICE(QString);
    void setNOMBRE_HEURE_DE_TRAVAIL(int);
    void setprix(float);

    QSqlQueryModel * fiche_de_paie();

    bool ajouter();
    QSqlQueryModel*  afficher();
    bool supprimer(int);
    bool modifier(QString);
    QSqlQueryModel *rechercher(QString );
    QSqlQueryModel *trie1();
    QSqlQueryModel *trie2();
    QSqlQueryModel *trie3();
    QSqlQueryModel *trie4();
    QSqlQueryModel *trie5();

    QSqlQueryModel *trie11();
    QSqlQueryModel *trie22();
    QSqlQueryModel *trie33();
    QSqlQueryModel *trie44();
    QSqlQueryModel *trie55();

    QChartView * stat();






private :

    int NOMBRE_HEURE_DE_TRAVAIL;
    float prix;
    QString cin, nom, prenom,AFFECTATION_SERVICE;

};


#endif // RESSOURCE_HUMAINE_H
