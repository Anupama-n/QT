QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp \
    lib/LZ77.cpp \
    lib/huffman.cpp \
    lib/misc.cpp \
    main.cpp \
    mainwindow.cpp \
    secdialog.cpp \

HEADERS += \
    dialog.h \
    include/LZ77.hpp \
    include/huffman.h \
    include/misc.hpp \
    mainwindow.h \
    secdialog.h \

FORMS += \
    dialog.ui \
    mainwindow.ui \
    secdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    assets/euler.png
