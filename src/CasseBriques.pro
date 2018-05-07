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
TARGET 	  = CasseBriques

# fichiers sources/headers
SOURCES	+= main.cpp myglwidget.cpp \
    balle.cpp \
    palet.cpp \
    bloc.cpp \
    mur.cpp \
    brique.cpp \
    sol.cpp
HEADERS += \
    balle.hpp \
    palet.hpp \
    bloc.hpp \
    mur.hpp \
    myglwidget.hpp \
    brique.hpp \
    sol.hpp
