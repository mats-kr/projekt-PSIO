TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += console c++17
SOURCES += \
        elementysceny.cpp \
        gracz.cpp \
        main.cpp \
        pojazd.cpp \
        pojazdspecjalny.cpp \
        score.cpp \
        sprite.cpp
        INCLUDEPATH +="C:/Users/User/Desktop/x/lab10/SFML-2.5.1/include"


        LIBS += -L"C:/Users/User/Desktop/x/lab10/SFML-2.5.1/lib"

        CONFIG(debug, debug|release)
        {
        LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
        }

HEADERS += \
    elementysceny.h \
    gracz.h \
    pojazd.h \
    pojazdspecjalny.h \
    score.h \
    sprite.h
