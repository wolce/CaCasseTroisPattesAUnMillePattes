#include "wall.h"

wall::wall()
{
}
void wall::Construc()
{
    glBegin(GL_QUADS); // Primitive à afficher et début de la déclaration des vertices de cette primitive
    glVertex2f(-15.5, 5.5);
    glVertex2f(-15.5, -4);
    glVertex2f(-16.5, -4);
    glVertex2f(-16.5, 5.5);
    glEnd();

    glBegin(GL_QUADS); // Primitive à afficher et début de la déclaration des vertices de cette primitive
    glVertex2f(8.5, 5.5);
    glVertex2f(8.5, -4);
    glVertex2f(9.5, -4);
    glVertex2f(9.5, 5.5);
    glEnd();

    glBegin(GL_QUADS); // Primitive à afficher et début de la déclaration des vertices de cette primitive
    glVertex2f(-15.5, 4.5);
    glVertex2f(8.5, 4.5);
    glVertex2f(8.5, 5.5);
    glVertex2f(-15.5, 5.5);
    glEnd();
}
wall::~wall()
{

}
