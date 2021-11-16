#include "stat_produit.h"
#include "ui_stat_produit.h"
#include <QSqlQueryModel>
#include <QSqlQuery>

stat_Produit::stat_Produit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_Produit)
{
    ui->setupUi(this);
}

stat_Produit::~stat_Produit()
{
    delete ui;
}

int stat_Produit :: Stat_1()
{

    int count=0 ;
    QSqlQuery requete("select * from Produit where Quantite BETWEEN '0' AND '30' ") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int stat_Produit :: Stat_2()
{

    int count=0 ;
    QSqlQuery requete("select * from Produit where Quantite BETWEEN '30' AND '60'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int stat_Produit :: Stat_3()
{

    int count=0 ;
    QSqlQuery requete("select * from Produit where Quantite BETWEEN '60' AND '9999'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}
void stat_Produit :: Stat(QPaintEvent * )
{

    int b=Stat_1();
    int c=Stat_2();
    int d=Stat_3();

        float s1= b*100 ;
        float s2=c*100;
        float nb = b+c+d ;
        float q1 ;
        q1 = s1/nb ;
        float q2;
        q2=s2/nb;
        float y  ;
        y = (q1*360)/100 ;
        float m;
        m= (q2*360)/100;
        float z  ;
        z=360-(y+m) ;

    QPainter painter(this);

    QRectF size=QRectF(50,50,this->width()-500,this->width()-500);

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,16*y);
    //ui->label_b->setText("Entre 0 et 30") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,16*y,16*m);
    //ui->label_g->setText("Entre 30 et 60") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*(m+y),16*z);
    //ui->label_r->setText("Plus que 60") ;
}
