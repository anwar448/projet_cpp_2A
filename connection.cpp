#include "connection.h"
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet2A");//inserer le nom de la source de données ODBC
db.setUserName("rami");//inserer nom de l'utilisateur
db.setPassword("rami");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
