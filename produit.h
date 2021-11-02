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
        int getNombre();
        QString getDelai();
        QString getPrix();

            void setID(int n);
            void setNom(QString n);
            void setType(QString n);
            void setNombre(int n);
            void setDelai(QString n);
            void setPrix(QString n);

                bool ajouter();
                QSqlQueryModel* afficher();
                bool supprimer(int);
                bool modifier(int);

private:
    QString Nom, Type, Delai;
    int ID,Nombre;
    QString Prix;
};

#endif // PRODUIT_H
