#include <vector>
#include "palet.hpp"

Palet::Palet()
{
    m_points[0][0] = -3.5f;
    m_points[0][1] = -4.0f;
    m_points[1][0] = -3.5f;
    m_points[1][1] = -5.0f;
    m_points[2][0] = 3.5f;
    m_points[2][1] = -5.0f;
    m_points[3][0] = 3.5f;
    m_points[3][1] = -4.0f;

    m_cotesSpeciaux.push_back({1,4});

}

void Palet::Display()
{
    glBegin(GL_QUADS);
        glColor3f(m_couleurs[0], m_couleurs[1], m_couleurs[2]); // Blanc
        glVertex2f(m_points[0][0], m_points[0][1]);
        glVertex2f(m_points[1][0], m_points[1][1]);
        glVertex2f(m_points[2][0], m_points[2][1]);
        glVertex2f(m_points[3][0], m_points[3][1]);
    glEnd();
}

Palet::~Palet()
{

}
