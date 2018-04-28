#include "palet.hpp"

Palet::Palet()
{

}

void Palet::Display(const float position, const float distance)
{
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); // Blanc
    glVertex2f(position, -4.0f);
    glVertex2f(position, -5.0f);
    glVertex2f(position+distance, -5.0f);
    glVertex2f(position+distance, -4.0f);
    glEnd();
}

Palet::~Palet()
{

}
