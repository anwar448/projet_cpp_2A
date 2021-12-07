#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include"clients.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
      Clients C;
     bool test=c.ouvrirConnexion();
    MainWindow w;



    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
   C.alerte_clients_fidele();
    return a.exec();
}
