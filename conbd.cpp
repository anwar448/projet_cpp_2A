#include "conbd.h"

bool connectDB()
{
    QSqlDatabase con=QSqlDatabase::addDatabase("QODBC");
    con.setConnectOptions();
    con.setUserName("zeynab");
    con.setPassword("zeynab");
    con.setDatabaseName("projet2A");
    if(con.open()){
        qDebug() << "trop bien connecte a la bd";
        return true;
    }else{
        qDebug() << "Error = " << con.lastError().text();
        return false;
    }
}
