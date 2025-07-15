QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Bank/Bank/Account.cpp \
    ../Bank/Bank/Admin.cpp \
    ../Bank/Bank/CardToCard.cpp \
    ../Bank/Bank/Costumer.cpp \
    ../Bank/Bank/GharzolHasanehAccount.cpp \
    ../Bank/Bank/JariAccount.cpp \
    ../Bank/Bank/LinkedList.cpp \
    ../Bank/Bank/LongTermAccount.cpp \
    ../Bank/Bank/Node.cpp \
    ../Bank/Bank/User.cpp \
    ../Bank/Bank/globals.cpp \
    accounteditwindow.cpp \
    accountoptionswindow.cpp \
    adminloginwindow.cpp \
    adminmainwindow.cpp \
    adminoptionswindow.cpp \
    customereditwindow.cpp \
    customerloginwindow.cpp \
    customermainwindow.cpp \
    customeroptionswindow.cpp \
    editadminwindow.cpp \
    editcardswindow.cpp \
    editcustomerwindow.cpp \
    loginselectorwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    newadminwindow.cpp \
    newcustomerwindow.cpp \
    showadminwindow.cpp \
    transferwindow.cpp \
    viewcardswindow.cpp \
    viewcustomerwindow.cpp

HEADERS += \
    ../Bank/Bank/Account.h \
    ../Bank/Bank/Admin.h \
    ../Bank/Bank/CardToCard.h \
    ../Bank/Bank/Costumer.h \
    ../Bank/Bank/GharzolHasanehAccount.h \
    ../Bank/Bank/JariAccount.h \
    ../Bank/Bank/LinkedList.h \
    ../Bank/Bank/LongTermAccount.h \
    ../Bank/Bank/Node.h \
    ../Bank/Bank/User.h \
    ../Bank/Bank/globals.h \
    accounteditwindow.h \
    accountoptionswindow.h \
    adminloginwindow.h \
    adminmainwindow.h \
    adminoptionswindow.h \
    customereditwindow.h \
    customerloginwindow.h \
    customermainwindow.h \
    customeroptionswindow.h \
    editadminwindow.h \
    editcardswindow.h \
    editcustomerwindow.h \
    loginselectorwindow.h \
    mainwindow.h \
    newadminwindow.h \
    newcustomerwindow.h \
    showadminwindow.h \
    transferwindow.h \
    viewcardswindow.h \
    viewcustomerwindow.h

FORMS += \
    accounteditwindow.ui \
    accountoptionswindow.ui \
    adminloginwindow.ui \
    adminmainwindow.ui \
    adminoptionswindow.ui \
    customereditwindow.ui \
    customerloginwindow.ui \
    customermainwindow.ui \
    customeroptionswindow.ui \
    editadminwindow.ui \
    editcardswindow.ui \
    editcustomerwindow.ui \
    loginselectorwindow.ui \
    mainwindow.ui \
    newadminwindow.ui \
    newcustomerwindow.ui \
    showadminwindow.ui \
    transferwindow.ui \
    viewcardswindow.ui \
    viewcustomerwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
