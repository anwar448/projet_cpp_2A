#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produit.h"

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
    void on_ajouter_clicked();

    void on_supprimer_clicked();


    void on_afficher_clicked();

    void on_modifier_clicked();

    void on_Annuler_1_clicked();

    void on_Annuler_2_clicked();

    void on_Annuler_3_clicked();

    void on_trier_clicked();

    void on_afficher_pour_modifier_clicked();

private:
    Ui::MainWindow *ui;
    Produit P;
};

#endif // MAINWINDOW_H
