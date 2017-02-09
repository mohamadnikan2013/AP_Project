#-------------------------------------------------
#
# Project created by QtCreator 2017-02-01T00:28:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RiverRaidProject
TEMPLATE = app

QT += multimedia


SOURCES += main.cpp\
    AerialEnemy.cpp \
    Baloon.cpp \
    Bridge.cpp \
    Bullet.cpp \
    DepotFuel.cpp \
    Helicopter.cpp \
    Jet.cpp \
    Marinenemy.cpp \
    Object.cpp \
    Tanker.cpp \
    Wall.cpp \
    movingObject.cpp \
    Timer.cpp \
    EnemyObject.cpp \
    game.cpp \
    Player.cpp \
    score.cpp \
    physics.cpp \
    fuelindicator.cpp

HEADERS  += \
    AerialEnemy.h \
    Baloon.h \
    Bridge.h \
    Bullet.h \
    DepotFuel.h \
    Helicopter.h \
    Jet.h \
    Marinenemy.h \
    Object.h \
    Tanker.h \
    Wall.h \
    movingObject.h \
    Timer.h \
    EnemyObject.h \
    game.h \
    Player.h \
    score.h \
    physics.h \
    fuelindicator.h

DISTFILES += \
    RiverRaidProject.pro.user

RESOURCES += \
    images.qrc \
    sounds.qrc

OTHER_FILES += \
    images/leftBalloon.png \
    images/rightBalloon.png
