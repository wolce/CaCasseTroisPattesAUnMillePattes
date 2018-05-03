#include "sol.hpp"

Sol::Sol(float p[][2], float coord)
{
    m_points[0][0] = p[0][0];
    m_points[0][1] = p[0][1];
    m_points[1][0] = p[1][0];
    m_points[1][1] = p[1][1];
    m_points[2][0] = p[2][0];
    m_points[2][1] = p[2][1];
    m_points[3][0] = p[3][0];
    m_points[3][1] = p[3][1];

    m_coord = coord;

    m_visible = false;
}

bool Sol::collision(Balle* &balle)
{
    float rayon = balle->getRayon();
    if (balle->getCentreY()-rayon < m_coord)
        return true;
    else
        return false;
}

void Sol::traiterCollision(Balle* &balle)
{

}

void Sol::Display()
{
    if (m_visible == true)
    {
        glBegin(GL_QUADS); // Primitive à afficher et début de la déclaration des vertices de cette primitive
            glColor3f(1.0f, 1.0f, 1.0f); // Blanc
            glVertex2f(m_points[0][0], m_points[0][1]);
            glVertex2f(m_points[1][0], m_points[1][1]);
            glVertex2f(m_points[2][0], m_points[2][1]);
            glVertex2f(m_points[3][0], m_points[3][1]);
        glEnd();
    }
}

Sol::~Sol()
{
}
