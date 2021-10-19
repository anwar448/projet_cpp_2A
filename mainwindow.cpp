#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QPixmap pix("C:/Users/rami/Downloads/background.png");
        ui->photo->setPixmap(pix);
        QPixmap pix1("C:/Users/rami/Downloads/recipe.png");
            ui->facture ->setPixmap(pix1);
            QPixmap pix2("C:/Users/rami/Downloads/chariot.png");
                ui->fournisseurs ->setPixmap(pix2);
                QPixmap pix3("C:/Users/rami/Downloads/ressources humaine.png");
                    ui->ressources ->setPixmap(pix3);
                    QPixmap pix4("C:/Users/rami/Downloads/client.png");
                        ui->client ->setPixmap(pix4);
                        QPixmap pix5("C:/Users/rami/Downloads/produit.png");
                            ui->produit ->setPixmap(pix5);
                            QPixmap pix6("C:/Users/rami/Downloads/service.png");
                                ui->service ->setPixmap(pix6);
                                QPixmap pix7("C:/Users/rami/Downloads/produit.png");
                                ui->pic->setPixmap(pix);
                                QPixmap pix8("C:/Users/rami/Downloads/ressources humaine.png");
                                    ui->ressources_3 ->setPixmap(pix8);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_6_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
