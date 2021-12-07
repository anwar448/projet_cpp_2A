#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include "connection.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
   Connection c;
   MainWindow *MainWindow;

   bool test= c.createconnect();

              if(test)
              {
                  MainWindow = new class MainWindow();
                                  MainWindow->show();
                  /*QMessageBox::information(nullptr, QObject::tr("database is open"),
                              QObject::tr("connection successful.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);*/
              }
          else
                  QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    return a.exec();
}
