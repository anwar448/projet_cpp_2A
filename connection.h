#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>

class Connection
{
private:
    QSqlDatabase db;

public:
    Connection();
    bool createconnect();
    void fermerConnexion();
};

#endif // CONNECTION_H




