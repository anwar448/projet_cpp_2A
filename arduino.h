/*#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QSerialPort> //rassemblent des fcts permettant l'écha,ge des données dans une lieison série
#include <QtSerialPort/QSerialPortInfo> //fournit des informations sur les orts disponobles



class arduino
{
public:
    arduino();
    int connect_arduino(); //permet de connecter le pc à arduino
    int close_arduino(); //permet de fermer la connexion
    int write_to_arduino(QByteArray); //encoyer des données à Arduino
    QByteArray read_from_arduino(); //recevoir des données de la carte arduino
    QSerialPort* getserial(); //accesseur
    QString getarduino_port_name();

private:
    QSerialPort* seial; //rassemble des informationset des fonctions sur ce su'est une voie série pour Arduino

    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data; //contenant les données lues par arduino
};

#endif // ARDUINO_H*/

#ifndef ARDUINO_H
#define ARDUINO_H
#include "QtSerialPort/QSerialPort"
#include "QtSerialPort/qserialportinfo.h"
#include<QDebug>
#include<QSqlQueryModel>

class arduino
{
public:

    arduino();
    int connect_arduino();
    int close_arduino();
    int write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort* getserial(){return serial;};
    QString getarduino_port_name(){return arduino_port_name;};


private:
    QSerialPort *serial;
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;

};

#endif // ARDUINO_H
