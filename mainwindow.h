#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "clients.h"
#include <connection.h>
//#include <QWidget>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_ajouter_clients_clicked();

    void on_pushButton_31_clicked();


    void on_pb_modifier_clicked();

    void on_pb_trier_clicked();

    void on_pb_rechercher_clicked();
    void stat();
    //void on_chercher_currentChanged(int index);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_mailing_clients_clicked();

    void on_alerte_clients_clicked();

private:
    Ui::MainWindow *ui;
    Clients C;


/*protected:
    void paintEvent(QPaintEvent *);*/
};

#endif // MAINWINDOW_H
