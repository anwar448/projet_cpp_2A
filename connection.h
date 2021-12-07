#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "clients.h"

class Connection
{
public:
    Connection();
    bool ouvrirConnexion();
    Clients c;
};

#endif // CONNECTION_H
