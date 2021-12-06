#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fournisseur.h"
#include "arduino.h"

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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pushButton_2_clicked();

    //void on_triID_fournisseur_clicked();

    //void on_radioButton_2_clicked();

    void on_pushButton_3_clicked();

    //void on_pushButton_clicked();

    void on_pushButton_4_clicked();


    void on_tabWidget_currentChanged(int index);

    void on_pushButton_5_clicked();


//void on_sendBtn_clicked();
void on_pushButton_clicked();

//void on_pushButton_6_clicked();
// Arduinoooooo
void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
// ce slot est lancé à chaque réception d'un message de Arduino

void on_pushButton_6_clicked();   // bouton ON

void on_pushButton_7_clicked(); // bouton OFF



private:
    Ui::MainWindow *ui;
    Fournisseur F;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};

#endif // MAINWINDOW_H
