#include "galet.h"

galet::galet()
{

}
void galet::Display(float position,float distance)
{
    glBegin(GL_QUADS); // Primitive à afficher et début de la déclaration des vertices de cette primitive
    glVertex2f(position, -4);
    glVertex2f(position, -5);
    glVertex2f(position+distance, -5);
    glVertex2f(position+distance, -4);
    glEnd();


}
galet::~galet()
{

}
