#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "RESSOURCE_HUMAINE.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
    QString val;
    RESSOURCE_HUMAINE C;
};
#endif // MAINWINDOW_H
