#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "service.h"
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
    bool controle_saisie();
    service collecte_data();

private slots:
    void on_pbAJOUTER_clicked();

    void on_groupBox_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pb_supprimer_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
