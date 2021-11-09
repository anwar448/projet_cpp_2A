#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQueryModel>
#include <QTableView>

class Produit
{
public:
    Produit();
    Produit(int,QString,QString,int,QString,QString);

        int getID();
        QString getNom();
        QString getType();
        int getQuantite();
        QString getDelai();
        QString getPrix();

            void setID(int n);
            void setNom(QString n);
            void setType(QString n);
            void setQuantite(int n);
            void setDelai(QString n);
            void setPrix(QString n);

                bool ajouter();
                QSqlQueryModel* afficher();
                bool supprimer(int);
                bool modifier(int);
                void searchRegexp(QTableView *table, int x);
                bool recherche(int id);
                QSqlQueryModel * trierDelai();

private slots:
void on_recherche_textChanged(const QString &arg1);


private:
    QString Nom, Type, Delai;
    int ID,Quantite;
    QString Prix;
};

#endif // PRODUIT_H
