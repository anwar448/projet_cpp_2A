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
  QSqlQuery query;
  QString   request = "insert into SERVICES values(:id, :offre, :type, :tarifs, :disponibilite, :horaire, :ID_employer);";
  query.prepare(request);
  query.bindValue(":id", this->id);
  query.bindValue(":tarifs", this->getTarifs());
  query.bindValue(":type", this->type);
  query.bindValue(":offre", this->offre);
  query.bindValue(":disponibilite", this->disponibilite);
  query.bindValue(":horaire", this->horaire);
  query.bindValue(":ID_employer", this->ID_employer);
  if(query.exec())return true;
  else{

      qDebug()<<"erreur du a:" << query.lastError().text() << this->getTarifs();
      return false;
  }


}

bool service::supprimer()
{
    QSqlQuery query;
    QString request = "delete from SERVICE  where id = :id;";

    query.prepare(request);
    query.bindValue(" :id", this->getId());

    if(query.exec())return true;
    else{

        qDebug()<<"erreur de suppression:" << query.lastError().text();
        return false;
    }
}

service service::select(int id)
{
    service s;
    QSqlQuery query;
    s.setId(-1);
    QString request="select * from services where id = ";
    request = request+ QString::number(id) +" ;";
    qDebug()<<request;
    if(query.exec(request)){
            qDebug() <<"je passe ici:"<<query.value(0).toInt();

        s.setId(query.value(0).toInt());
        s.setType(query.value(1).toString());
        s.setOffres(query.value(2).toString());
        s.setTarifs(query.value(3).toInt());
        s.setHoraire(query.value(4).toDate());
        s.setDisponibilite(query.value(5).toString());
        s.setID_employer(query.value(5).toInt());
        qDebug()<<"la valeur final de s est:"<<s.getId();
    }else{
        qDebug()<<"erreur de suppression:" << query.lastError().text();

    }
    return s;
}

bool service::modifier(service a)
{
    QSqlQuery query;
    QString   request = "update SERVICE set tarifs= :tarifs, type= :type, offre= :offre, disponibilite= :disponibilite, ID_employer= :ID_employer, horaire= :horaire where id= :id;";

    this->setTarifs(a.getTarifs());
    this->setType(a.getType());
    this->setOffres(a.getOffre());
    this->setDisponibilite(a.getDisponibilite());
    this->setHoraire(a.getHoraire());
    this->setID_employer(a.getID_employer());

    query.prepare(request);
    query.bindValue(":id", this->id);
    query.bindValue(":tarifs", this->tarifs);
    query.bindValue(":type", this->type);
    query.bindValue(":offre", this->offre);
    query.bindValue(":disponibilite", this->disponibilite);
    query.bindValue(":horaire", this->horaire);
    query.bindValue(":ID_employer", this->ID_employer);

    if(query.exec())return true;
    else{

        qDebug()<<"erreur du a:" << query.lastError().text();
        return false;
    }



}
