#include "RESSOURCE_HUMAINE.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtWidgets/QGridLayout>

RESSOURCE_HUMAINE::RESSOURCE_HUMAINE()
{
    cin ="";
    nom = "";
    prenom= "";
    AFFECTATION_SERVICE="";
    NOMBRE_HEURE_DE_TRAVAIL=0;

}

RESSOURCE_HUMAINE:: RESSOURCE_HUMAINE(QString cin ,QString nom, QString prenom,QString AFFECTATION_SERVICE,int NOMBRE_HEURE_DE_TRAVAIL)
{
    this->cin = cin;
    this->nom = nom;
    this->prenom = prenom;
    this->AFFECTATION_SERVICE= AFFECTATION_SERVICE;
    this->NOMBRE_HEURE_DE_TRAVAIL = NOMBRE_HEURE_DE_TRAVAIL;


}

QString     RESSOURCE_HUMAINE:: getcin(){return cin;}
QString RESSOURCE_HUMAINE:: getnom(){return nom ;}
QString RESSOURCE_HUMAINE:: getprenom(){return prenom;}
QString RESSOURCE_HUMAINE:: getAFFECTATION_SERVICE(){return AFFECTATION_SERVICE;}
int RESSOURCE_HUMAINE:: getNOMBRE_HEURE_DE_TRAVAIL(){return NOMBRE_HEURE_DE_TRAVAIL;}

void RESSOURCE_HUMAINE::setcin(QString cin ){this->cin=cin ;}
void RESSOURCE_HUMAINE::setnom(QString nom){this->nom=nom;}
void RESSOURCE_HUMAINE::setprenom(QString prenom){this->prenom=prenom;}
void RESSOURCE_HUMAINE::setAFFECTATION_SERVICE(QString AFFECTATION_SERVICE){this->AFFECTATION_SERVICE=AFFECTATION_SERVICE;}
void RESSOURCE_HUMAINE::setNOMBRE_HEURE_DE_TRAVAIL(int NOMBRE_HEURE_DE_TRAVAIL){this->NOMBRE_HEURE_DE_TRAVAIL=NOMBRE_HEURE_DE_TRAVAIL;}


bool RESSOURCE_HUMAINE::ajouter()
{

    QSqlQuery query;
    query.prepare("INSERT INTO RESSOURCE_HUMAINE (cin, nom, prenom,AFFECTATION_SERVICE,NOMBRE_HEURE_DE_TRAVAIL) "
                  "VALUES (:cin,:nom,:prenom,:AFFECTATION_SERVICE,:NOMBRE_HEURE_DE_TRAVAIL)");
    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":AFFECTATION_SERVICE", AFFECTATION_SERVICE);
    query.bindValue(":NOMBRE_HEURE_DE_TRAVAIL", NOMBRE_HEURE_DE_TRAVAIL);


    return query.exec();

}

bool RESSOURCE_HUMAINE ::supprimer(int id)
{

    QSqlQuery query;

    query.prepare("Delete from RESSOURCE_HUMAINE where cin=:id ");

    query.bindValue(":id",id);

    return query.exec();


}

QSqlQueryModel* RESSOURCE_HUMAINE::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT * FROM RESSOURCE_HUMAINE");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("AFFECTATION_SERVICE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_HEURE_DE_TRAVAIL"));


  return model ;
}

bool RESSOURCE_HUMAINE::modifier(QString a)
{
    QSqlQuery query;

    query.prepare("UPDATE RESSOURCE_HUMAINE SET cin=:cin,nom=:nom,prenom=:prenom,affectation_service=:affectation,nombre_heure_de_travail=:nombre where cin=:id");
    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":affectation", AFFECTATION_SERVICE);
    query.bindValue(":nombre", NOMBRE_HEURE_DE_TRAVAIL);
    query.bindValue(":id", a);

    return query.exec();
}
QSqlQueryModel *RESSOURCE_HUMAINE::rechercher(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM RESSOURCE_HUMAINE WHERE cin  LIKE'%"+rech+"%' or nom  LIKE'%"+rech+"%' or prenom  LIKE'%"+rech+"%' or AFFECTATION_SERVICE  LIKE'%"+rech+"%' or NOMBRE_HEURE_DE_TRAVAIL  LIKE'%"+rech+"%' ");
    return model;
}
QSqlQueryModel *RESSOURCE_HUMAINE::trie1()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM RESSOURCE_HUMAINE order by cin");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AFFECTATION_SERVICE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_HEURE_DE_TRAVAIL"));
    return  model;
}
QSqlQueryModel *RESSOURCE_HUMAINE::trie2()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM RESSOURCE_HUMAINE order by nom");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AFFECTATION_SERVICE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_HEURE_DE_TRAVAIL"));
    return  model;
}
QSqlQueryModel *RESSOURCE_HUMAINE::trie3()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM RESSOURCE_HUMAINE order by prenom");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AFFECTATION_SERVICE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_HEURE_DE_TRAVAIL"));
    return  model;
}
QSqlQueryModel *RESSOURCE_HUMAINE::trie4()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM RESSOURCE_HUMAINE order by AFFECTATION_SERVICE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AFFECTATION_SERVICE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_HEURE_DE_TRAVAIL"));
    return  model;
}
QSqlQueryModel *RESSOURCE_HUMAINE::trie5()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM RESSOURCE_HUMAINE order by NOMBRE_HEURE_DE_TRAVAIL");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AFFECTATION_SERVICE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_HEURE_DE_TRAVAIL"));
    return  model;
}

QSqlQueryModel *RESSOURCE_HUMAINE::trie11()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM RESSOURCE_HUMAINE order by cin DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AFFECTATION_SERVICE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_HEURE_DE_TRAVAIL"));
    return  model;
}
QSqlQueryModel *RESSOURCE_HUMAINE::trie22()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM RESSOURCE_HUMAINE order by nom DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AFFECTATION_SERVICE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_HEURE_DE_TRAVAIL"));
    return  model;
}
QSqlQueryModel *RESSOURCE_HUMAINE::trie33()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM RESSOURCE_HUMAINE order by prenom DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AFFECTATION_SERVICE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_HEURE_DE_TRAVAIL"));
    return  model;
}
QSqlQueryModel *RESSOURCE_HUMAINE::trie44()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM RESSOURCE_HUMAINE order by AFFECTATION_SERVICE DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AFFECTATION_SERVICE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_HEURE_DE_TRAVAIL"));
    return  model;
}
QSqlQueryModel *RESSOURCE_HUMAINE::trie55()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM RESSOURCE_HUMAINE order by NOMBRE_HEURE_DE_TRAVAIL DESC ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AFFECTATION_SERVICE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOMBRE_HEURE_DE_TRAVAIL"));
    return  model;
}


void  RESSOURCE_HUMAINE::statistique(QVector<double>* ticks,QVector<QString> *labels)
{
QSqlQuery q;
    int i=0;
    q.exec("select cin  from RESSOURCE_HUMAINE");
    while (q.next())
    {
        QString cin = q.value(0).toString();
        i++;
        *ticks<<i;
        *labels <<cin;
    }
}
