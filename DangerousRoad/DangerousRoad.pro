TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += console c++17
SOURCES += \
        dhlcar.cpp \
        greencar.cpp \
        main.cpp \
        player.cpp \
        policecar.cpp \
        redcar.cpp \
        road.cpp \
        scene.cpp \
        sceneborder.cpp \
        sceneelements.cpp \
        scenelabels.cpp \
        sprite.cpp \
        vehicle.cpp

INCLUDEPATH +="C:/Users/User/Desktop/x/lab10/SFML-2.5.1/include"


LIBS += -L"C:/Users/User/Desktop/x/lab10/SFML-2.5.1/lib"

CONFIG(debug, debug|release)
{
LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
}

HEADERS += \
    dhlcar.h \
    greencar.h \
    player.h \
    policecar.h \
    redcar.h \
    road.h \
    scene.h \
    sceneborder.h \
    sceneelements.h \
    scenelabels.h \
    sprite.h \
    vehicle.h
