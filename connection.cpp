#include "connection.h"

Connection::Connection()
{
}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");//inserer le nom de la source de données ODBC
db.setUserName("anwar");//inserer nom de l'utilisateur
db.setPassword("anwar");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
