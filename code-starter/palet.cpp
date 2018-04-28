#include "palet.hpp"

Palet::Palet()
{
    m_largeur = 7.0f;
    m_epaisseur = 1.0f;
    m_position[0] = 0.0f; // Position en X
    m_position[1] = -4.5f; // Position en Y
}

void Palet::Display()
{
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f); // Blanc
        glVertex2f(m_position[0]-m_largeur/2, m_position[1]+m_epaisseur/2);
        glVertex2f(m_position[0]-m_largeur/2, m_position[1]-m_epaisseur/2);
        glVertex2f(m_position[0]+m_largeur/2, m_position[1]-m_epaisseur/2);
        glVertex2f(m_position[0]+m_largeur/2, m_position[1]+m_epaisseur/2);
    glEnd();
}

Palet::~Palet()
{

}

void Palet::decaler(const float x, const float y)
{
    m_position[0] = m_position[0] + x;
    m_position[1] = m_position[1] + y;
}
