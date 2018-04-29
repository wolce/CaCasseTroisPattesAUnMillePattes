#include <QApplication>
#include <ctime>
#include "myglwidget.h"
#include "briques.h"
#include "mur.hpp"
#include "balle.hpp"
#include "palet.hpp"

int main(int argc, char *argv[])
{
    // Initialisation du generateur de nombres aleatoires
    srand(time(nullptr));

    // Creation de l'application QT
    QApplication app(argc, argv);
	
	// Creation du widget opengl
    MyGLWidget glWidget;
    glWidget.show();

    // Execution de l'application QT
    return app.exec();



}
