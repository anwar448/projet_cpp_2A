#include "service.h"

int service::getId()
{
    return this ->id;
}

int service::getTarifs()
{
    return this->tarifs;
}

QString service::getType()
{
    return this->type;
}

QString service::getOffre()
{
    return this->offre;
}

QString service::getDisponibilite()
{
    return this->disponibilite;
}

QDate  service::getHoraire()
{
    return this->horaire;
}

int service::getID_employer(){

    return this->ID_employer;

}
void service::setId(int id)
{
    this->id=id;
}

void service::setTarifs(int tarifs)
{
    this->tarifs=tarifs;
}

void service::setType(QString type)
{
    this->type=type;
}

void service::setOffres(QString offre)
{
    this->offre=offre;
}

void service::setDisponibilite(QString disponibilite)
{
    this->disponibilite=disponibilite;
}

void service::setHoraire(QDate horaire)
{
   this->horaire=horaire;
}

void service::setID_employer(int ID_employer)
{

    this->ID_employer=ID_employer;
}

service::service()
{

}

service::service(int id, float tarifs, QString type, QString offre, QString disponibilite, QDate horaire, int ID_employer)
{
  this->id=id;
  this->tarifs=tarifs;
  this->type=type;
  this->offre=offre;
  this->disponibilite=disponibilite;
  this->horaire=horaire;
  this->ID_employer=ID_employer;
}

bool service::ajouter()
{
  QSqlQuery queryAjouter;
  QString   request = "insert into SERVICES values(:id, :offre, :type, :tarifs, :disponibilite, :horaire, :ID_employer);";
  queryAjouter.prepare(request);
  queryAjouter.bindValue(":id", this->id);
  queryAjouter.bindValue(":tarifs", this->getTarifs());
  queryAjouter.bindValue(":type", this->type);
  queryAjouter.bindValue(":offre", this->offre);
  queryAjouter.bindValue(":disponibilite", this->disponibilite);
  queryAjouter.bindValue(":horaire", this->horaire);
  queryAjouter.bindValue(":ID_employer", this->ID_employer);
  if(queryAjouter.exec())return true;
  else{

      qDebug()<<"erreur du a:" << queryAjouter.lastError().text() << this->getTarifs();
      return false;
  }


}

bool service::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("delete from SERVICES  where id = :id;");
    query.bindValue(0, id);

    if(query.exec())return true;
    else{

        qDebug()<<"erreur de suppression:" << query.lastError().text();
        return false;
    }
}

service service::select(int id)
{
    service s;
    QSqlQuery q;
    s.setId(-1);
    QString request="select * from services where id = ";
    request = request+ QString::number(id) +" ;";
    qDebug()<<request;

    if(q.exec(request)){
        q.next();
            qDebug() <<"je passe ici:"<<q.value(0).toInt();

        s.setId(q.value(0).toInt());
        s.setOffres(q.value(1).toString());
        s.setType(q.value(2).toString());
        s.setTarifs(q.value(3).toInt());
        s.setDisponibilite(q.value(4).toString());
        s.setHoraire(q.value(5).toDate());
         s.setID_employer(q.value(6).toInt());
        qDebug()<<"la valeur final de s est:"<<s.getID_employer();
    }else{
        qDebug()<<"erreur de suppression:" << q.lastError().text();

    }
    return s;
}

QVector<service> service::ListService(QString request)
{
    QVector<service> tableau;
    service service;
    QSqlQuery querySearch;
    if(request=="") request = "select* from SERVICES";
    querySearch.prepare(request);
    if(querySearch.exec()){
        int i(0);
        while (querySearch.next()) {
i++;
            service.setId(querySearch.value(0).toInt());
            service.setOffres(querySearch.value(1).toString());
            service.setType(querySearch.value(2).toString());
            service.setTarifs(querySearch.value(3).toInt());
            service.setDisponibilite(querySearch.value(4).toString());
            service.setHoraire(querySearch.value(5).toDate());
            service.setID_employer(querySearch.value(6).toInt());
            tableau.push_back(service);

        }
        qDebug()<<"il y a "<<i<<"elements";
        return tableau;
    }else{
        qDebug()<<"erreur de suppression:" << querySearch.lastError().text();

    }
}

QVector<service> service::MakeSearch(QString key)
{

    QVector<service> tableau;
    service service;
    QString request = "";
    QSqlQuery querySearchKey;
    if(request=="") request = "select* from SERVICES where type LIKE '%"+key+"%';";
    querySearchKey.prepare(request);
    if(querySearchKey.exec()){
        int i(0);
        while (querySearchKey.next()) {
i++;
            service.setId(querySearchKey.value(0).toInt());
            service.setOffres(querySearchKey.value(1).toString());
            service.setType(querySearchKey.value(2).toString());
            service.setTarifs(querySearchKey.value(3).toInt());
            service.setDisponibilite(querySearchKey.value(4).toString());
            service.setHoraire(querySearchKey.value(5).toDate());
            service.setID_employer(querySearchKey.value(6).toInt());
            tableau.push_back(service);

        }
        qDebug()<<"il y a "<<i<<"elements";
        return tableau;
    }else{
        qDebug()<<"erreur de suppression:" << querySearchKey.lastError().text();
        return tableau;
    }
}

bool service::alphaDescCompareNom(service &a, service &b)
{
    int x=QString::compare(a.getType(), b.getType(), Qt::CaseSensitive);
    if(x<0) return true;
    return false;
}

bool service::alphaAscCompareNom(service &a, service &b)
{
    int x=QString::compare(a.getType(), b.getType());
    //int x=QString::compare("az", "aidriss");
    if(x>0) return true;
    return false;
}

bool service::alphaDesCompareTarifs(service &a, service &b)
{
    if(a.getTarifs()>b.getTarifs()) return true;
    return false ;
}

bool service::alphaAscCompareTarifs(service &a, service &b)
{
    if(a.getTarifs()<=b.getTarifs()) return true;
    return false;
}

bool service::modifier(service a)
{
    QSqlQuery queryUpdate;
    QString   request = "update SERVICES set tarifs= :tarifs, type= :type, offres= :offre, disponibilite= :disponibilite, ID_emp= :ID_employer, horaire= :horaire where id= :id;";

    this->setTarifs(a.getTarifs());
    this->setType(a.getType());
    this->setOffres(a.getOffre());
    this->setDisponibilite(a.getDisponibilite());
    this->setHoraire(a.getHoraire());
    this->setID_employer(a.getID_employer());

    qDebug()<<a.getId()<<"; "<<a.getType()<<"; "<<a.getOffre()<<" ;"<<a.getTarifs();

    queryUpdate.prepare(request);
    queryUpdate.bindValue(":id", this->id);
    queryUpdate.bindValue(":tarifs", this->getTarifs());
    queryUpdate.bindValue(":type", this->type);
    queryUpdate.bindValue(":offre", this->offre);
    queryUpdate.bindValue(":disponibilite", this->disponibilite);
    queryUpdate.bindValue(":horaire", this->horaire);
    queryUpdate.bindValue(":ID_employer", this->ID_employer);

    if(queryUpdate.exec())return true;
    else{

        qDebug()<<"erreur du a:" << queryUpdate.lastError().text();
        return false;
    }



}
