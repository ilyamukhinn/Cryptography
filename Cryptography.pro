QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    atbash.cpp \
    caesar.cpp \
    main.cpp \
    mainwindow.cpp \
    polybius_square.cpp \
    scitula.cpp \
    vernam.cpp \
    vigenere.cpp

HEADERS += \
    atbash.h \
    caesar.h \
    mainwindow.h \
    polybius_square.h \
    scitula.h \
    vernam.h \
    vigenere.h

FORMS += \
    atbash.ui \
    caesar.ui \
    mainwindow.ui \
    polybius_square.ui \
    scitula.ui \
    vernam.ui \
    vigenere.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
