#include "rh.h"
#include "ui_rh.h"

rh::rh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rh)
{
    ui->setupUi(this);
}

rh::~rh()
{
    delete ui;
}
