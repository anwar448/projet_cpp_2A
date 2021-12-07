#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "facture.h"
#include <QMainWindow>
#include "smtp.h"
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void on_ajouter_clicked();
    void on_afficher_clicked();
    void on_supprimer_clicked();
    void on_modifier_clicked();
    void on_tri_clicked();
    void on_rechercher_clicked();
    void on_pdf_clicked();

    void sendMail(QString ,QString ,QString );

    void on_stat_clicked();

    void on_sendBtn_clicked();
    void on_imprFact_clicked();

    void on_plus_clicked();

    void on_moins_clicked();

    void on_fois_clicked();

    void on_sur_clicked();

    void on_actionNouveau_triggered();

    void on_actionEnregistrer_triggered();

    void on_actionQuitter_triggered();

    void on_actionOuvrir_triggered();

    void on_actionImprimer_triggered();

    void on_actionCopier_triggered();

    void on_actionColler_triggered();

    void on_actionCouper_triggered();

private:
    Ui::MainWindow *ui;
    Facture F;
    QString currentFile = "";
    QSystemTrayIcon *notifier;


};
#endif // MAINWINDOW_H
