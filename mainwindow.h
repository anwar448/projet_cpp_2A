#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "RESSOURCE_HUMAINE.h"
#include "qcustomplot.h"
#include "produit.h"
#include <QListView>
#include <QTableView>
#include <QTreeView>
#include <QItemDelegate>
#include "fournisseur.h"
#include "facture.h"
#include "smtp.h"
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include "clients.h"
#include "service.h"
#include "detail.h"
#include "QMessageBox"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Detail detail;

    bool controle_saisie();
    service collecte_data();

private slots:


    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_64_clicked();

    void on_pushButton_clicked();

    void on_pushButton_103_clicked();

    void on_pushButton_114_clicked();

    void on_pushButton_61_clicked();

    void on_pushButton_69_clicked();

    void on_pushButton_65_clicked();

    void on_tabWidget_3_tabBarClicked(int index);

    void on_tabWidget_3_currentChanged(int index);

    void on_pushButton_82_clicked();

    void on_pushButton_66_clicked();

    void on_lineEdit_100_textChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_pushButton_51_clicked();

    void on_pushButton_125_clicked();

    void on_pushButton_52_clicked();

    void on_plott_customContextMenuRequested(const QPoint &pos);

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_44_clicked();
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_afficher_clicked();

    void on_modifier_clicked();

    void on_Annuler_1_clicked();

    void on_Annuler_2_clicked();

    void on_Annuler_3_clicked();

    void on_trier_clicked();

    void on_afficher_pour_modifier_clicked();

    void on_Rechercher_clicked();

    void on_Quitter_clicked();

    void on_alerte_clicked();

    void on_mailing_clicked();
//"anwer "
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pushButton_19_clicked();

    //void on_triID_fournisseur_clicked();

    //void on_radioButton_2_clicked();

    void on_pushButton_15_clicked();

    //void on_pushButton_clicked();

    void on_pushButton_17_clicked();


    void on_tabWidget_currentChanged(int index);

    void on_pushButton_14_clicked();
//sameh 
        void on_ajouterf_clicked();
        void on_afficherf_clicked();
        void on_supprimerf_clicked();
        void on_modifierf_clicked();
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
       /* void on_actionNouveau_triggered();
        void on_actionEnregistrer_triggered();
        void on_actionQuitter_triggered();
        void on_actionOuvrir_triggered();
        void on_actionImprimer_triggered();
        void on_actionCopier_triggered();
        void on_actionColler_triggered();
        void on_actionCouper_triggered();*/

//void on_sendBtn_clicked();
void on_pushButton_16_clicked();
//saffaaaaaaaa

void on_return_client_clicked();

void on_pb_ajouter_clients_clicked();

    void on_pushButton_31_clicked();


    void on_pb_modifier_2_clicked();

    void on_pb_trier_clicked();

    void on_pb_rechercher_clicked();
    void stat();
    //void on_chercher_currentChanged(int index);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_mailing_clients_clicked();

    void on_alerte_clients_clicked();



    void on_pbAJOUTER_clicked();

    void on_pushButton_2_service_clicked();

    void on_pb_supprimer_service_clicked();

    void on_pb_modifier_service_clicked();



    void on_PbRecherche_clicked();

    void on_imprFact_2_clicked();

private:
    Ui::MainWindow *ui;
    QString val;
    RESSOURCE_HUMAINE C;
    Produit P;
    Fournisseur F;
    Facture Fa;
    Clients Cl;
    

};
#endif // MAINWINDOW_H
