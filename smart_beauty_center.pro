QT       += core gui sql charts printsupport
QT       += core gui sql
QT       += widgets
QT       += multimedia
QT       += core gui  serialport charts
QT += core gui network
QT += core gui charts
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    RESSOURCE_HUMAINE.cpp \
    clients.cpp \
    connection.cpp \
    detail.cpp \
    facture.cpp \
    fournisseur.cpp \
    googlesuggest.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    piechartwidget.cpp \
    produit.cpp \
    qcustomplot.cpp \
    searchbox.cpp \
    service.cpp \
    smtp.cpp \
    stat_produit.cpp

HEADERS += \
    RESSOURCE_HUMAINE.h \
    clients.h \
    connection.h \
    detail.h \
    facture.h \
    fournisseur.h \
    googlesuggest.h \
    login.h \
    mainwindow.h \
    piechartwidget.h \
    produit.h \
    qcustomplot.h \
    searchbox.h \
    service.h \
    smtp.h \
    stat_produit.h

FORMS += \
    detail.ui \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Ressources.qrc
