#ifndef DETAIL_H
#define DETAIL_H

#include <QMainWindow>
#include<QTableWidget>
#include "service.h"
#include "searchbox.h"
#include "arduino.h"
namespace Ui {
class Detail;
}

class GSuggestCompletion;
class Detail : public QMainWindow
{
    Q_OBJECT

public:
    explicit Detail(QWidget *parent = nullptr);
    ~Detail();
    QVector<service> response;
    QMainWindow *pa;
    SearchBox search;
    void buildtable(QVector<service> t);
    QString buildRequest();
    QVector<service> panier;
    QByteArray data_recive_form_arduino;
    Arduino arduino;

public slots:
    void check_available();
private slots:
    void on_PbReturn_clicked();

    void on_pushButton_2_clicked();

    void on_PbSearch_clicked();

    void on_radionom_clicked();

    void on_mailling_clicked();


    


    void on_comboBox_2_currentIndexChanged(int index);

    private:
    Ui::Detail *ui;
};

#endif // DETAIL_H
