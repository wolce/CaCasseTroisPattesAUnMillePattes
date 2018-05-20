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

INCLUDEPATH += $$(OPENCV_DIR)\..\..\include
LIBS += -L$$(OPENCV_DIR)\lib \
    -lopencv_core2413 \
    -lopencv_highgui2413 \
    -lopencv_imgproc2413 \
    -lopencv_features2d2413 \
    -lopencv_calib3d2413

# nom de l'exe genere
TARGET 	  = CasseBriques

# fichiers sources/headers
SOURCES	+= main.cpp \
    balle.cpp \
    palet.cpp \
    bloc.cpp \
    mur.cpp \
    brique.cpp \
    cassebriques.cpp \
    mainwindow.cpp \
    parametresdialog.cpp \
    camera.cpp \
    joueur.cpp
HEADERS += \
    balle.hpp \
    palet.hpp \
    bloc.hpp \
    mur.hpp \
    brique.hpp \
    cassebriques.hpp \
    mainwindow.hpp \
    parametresdialog.hpp \
    camera.hpp \
    joueur.hpp

FORMS += \
    parametresdialog.ui
