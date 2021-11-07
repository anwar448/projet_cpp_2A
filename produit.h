#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQueryModel>

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
                bool recherche(int id);
                QSqlQueryModel * trierDelai();


private:
    QString Nom, Type, Delai;
    int ID,Quantite;
    QString Prix;
};

#endif // PRODUIT_H
