# configuration Qt
QT       += core gui opengl widgets
TEMPLATE  = app

# ajout des libs au linker
win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib
    } else {
        LIBS     += -lopengl32 -lglu32
    }
}
else {
	LIBS     += -lGL -lGLU
}

# nom de l'exe genere
TARGET 	  = TD1

# fichiers sources/headers
SOURCES	+= main.cpp myglwidget.cpp \
    briques.cpp \
    wall.cpp \
    balle.cpp \
    palet.cpp
HEADERS += myglwidget.h \
    briques.h \
    wall.h \
    balle.hpp \
    palet.hpp
