QT -= gui
QT += widgets

CONFIG += c++11 console
CONFIG -= app_bundle
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        choosencolorinrgb.cpp \
        displayer.cpp \
        main.cpp \
        mostoftencolor.cpp \
        pixel.cpp \
        screenconstans.cpp \
        screener.cpp \
        triplet.cpp

TRANSLATIONS += \
    pixel_pl_PL.ts
LIBS += -lX11


QMAKE_CXXFLAGS += -lX11
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    choosencolorinrgb.h \
    displayer.h \
    mostoftencolor.h \
    pixel.h \
    screenconstans.h \
    screener.h \
    triplet.h
