#ifndef RH_H
#define RH_H

#include <QDialog>

namespace Ui {
class rh;
}

class rh : public QDialog
{
    Q_OBJECT

public:
    explicit rh(QWidget *parent = nullptr);
    ~rh();

private:
    Ui::rh *ui;
};

#endif // RH_H
