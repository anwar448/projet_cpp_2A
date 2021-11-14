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
