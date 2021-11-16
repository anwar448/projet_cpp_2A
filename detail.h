#ifndef DETAIL_H
#define DETAIL_H

#include <QMainWindow>

namespace Ui {
class Detail;
}

class Detail : public QMainWindow
{
    Q_OBJECT

public:
    explicit Detail(QWidget *parent = nullptr);
    ~Detail();

private:
    Ui::Detail *ui;
};

#endif // DETAIL_H
