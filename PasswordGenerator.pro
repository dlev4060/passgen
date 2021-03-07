QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialogisempty.cpp \
    main.cpp \
    passwordgenerator.cpp \
    savedpassword.cpp \
    savefile.cpp \
    savefileui.cpp

HEADERS += \
    dialogisempty.h \
    passwordgenerator.h \
    generator.h \
    savedpassword.h \
    savefile.h \
    savefileui.h

FORMS += \
    dialogisempty.ui \
    passwordgenerator.ui \
    savedpassword.ui \
    savefileui.ui

TRANSLATIONS += \
    PasswordGenerator_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    res.qrc
