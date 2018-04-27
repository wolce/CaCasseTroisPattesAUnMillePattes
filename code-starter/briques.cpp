#include "briques.h"

Briques::Briques()
{
}
void Briques::Display(float x, float y)// x et y du coin supérieur gauche
{
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x, y-1);
    glVertex2f(x+3, y-1);
    glVertex2f(x+3, y);
    glEnd();
}
Briques::~Briques()
{

}
