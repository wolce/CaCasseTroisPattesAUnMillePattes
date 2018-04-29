#include "mur.hpp"

Mur::Mur()
{
}

void Mur::Display()
{/*
    if (m_orientation == 0)
    {
        glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 1.0f); // Blanc
            glVertex2f(m_position, );
            glVertex2f(-15.5, -4);
            glVertex2f(-16.5, -4);
            glVertex2f(-16.5, 5.5);
        glEnd();
    }
    else if (m_orientation == 1)
    {
        glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 1.0f); // Blanc
            glVertex2f(-15.5, 5.5);
            glVertex2f(-15.5, -4);
            glVertex2f(-16.5, -4);
            glVertex2f(-16.5, 5.5);
        glEnd();
    }
*/

    glBegin(GL_QUADS); // Primitive à afficher et début de la déclaration des vertices de cette primitive
    glColor3f(1.0f, 1.0f, 1.0f); // Blanc
    glVertex2f(-15.5, 5.5);
    glVertex2f(-15.5, -4);
    glVertex2f(-16.5, -4);
    glVertex2f(-16.5, 5.5);
    glEnd();

    glBegin(GL_QUADS); // Primitive à afficher et début de la déclaration des vertices de cette primitive
    glColor3f(1.0f, 1.0f, 1.0f); // Blanc
    glVertex2f(8.5, 5.5);
    glVertex2f(8.5, -4);
    glVertex2f(9.5, -4);
    glVertex2f(9.5, 5.5);
    glEnd();

    glBegin(GL_QUADS); // Primitive à afficher et début de la déclaration des vertices de cette primitive
    glColor3f(1.0f, 1.0f, 1.0f); // Blanc
    glVertex2f(-15.5, 4.5);
    glVertex2f(8.5, 4.5);
    glVertex2f(8.5, 5.5);
    glVertex2f(-15.5, 5.5);
    glEnd();

}

Mur::~Mur()
{
}
