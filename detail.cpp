#include "detail.h"
#include "ui_detail.h"

Detail::Detail(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Detail)
{
    ui->setupUi(this);
}

Detail::~Detail()
{
    delete ui;
}
