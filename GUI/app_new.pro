QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += core sql

# MySQL libraries for linking
LIBS += -L/usr/lib/mysql -lmysqlclient
# LIBS += "-LC:/Program Files/MySQL/MySQL Server 9.1/lib" -lmysqlclient
# INCLUDEPATH += "C:/Program Files/MySQL/MySQL Server 9.1/include"

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    data_base.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    registrationform.cpp

HEADERS += \
    data_base.h \
    loginwindow.h \
    mainwindow.h \
    registrationform.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
