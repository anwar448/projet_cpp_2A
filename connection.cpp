#include "connection.h"

Connection::Connection(){}

bool Connection::createconnect()
{bool test=false;
db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test");//inserer le nom de la source de données ODBC
db.setUserName("sameh");//inserer nom de l'utilisateur
db.setPassword("sameh99");//inserer mot de passe de cet utilisateur


if (db.open()) test=true;
    return  test;
}
void Connection::fermerConnexion()
{
    db.close();
}







