#ifndef DETAIL_H
#define DETAIL_H

#include <QMainWindow>
#include<QTableWidget>
#include "service.h"
#include "searchbox.h"
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
