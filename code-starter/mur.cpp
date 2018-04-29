#include "mur.hpp"

Mur::Mur(float p[][2], int type, float coord)
{
    m_points[0][0] = p[0][0];
    m_points[0][1] = p[0][1];
    m_points[1][0] = p[1][0];
    m_points[1][1] = p[1][1];
    m_points[2][0] = p[2][0];
    m_points[2][1] = p[2][1];
    m_points[3][0] = p[3][0];
    m_points[3][1] = p[3][1];

    m_type = type;

    m_coord = coord;
}

bool Mur::collision(Balle *balle)
{
    float rayon = balle->getRayon();
    if (m_type == 1 && balle->getCentreX()-rayon < m_coord)
        return true;
    else if (m_type == 2 && balle->getCentreX()+rayon > m_coord)
        return true;
    else if (m_type == 3 && balle->getCentreY()+rayon > m_coord)
        return true;
    else
        return false;
}

void Mur::traiterCollision(Balle *balle)
{
    if (m_type == 1 || m_type == 2)
        balle->setDirection(-balle->getDirectionX(), balle->getDirectionY());
    else if (m_type == 3)
        balle->setDirection(balle->getDirectionX(), -balle->getDirectionY());
}

void Mur::Display()
{
    glBegin(GL_QUADS); // Primitive à afficher et début de la déclaration des vertices de cette primitive
        glColor3f(1.0f, 1.0f, 1.0f); // Blanc
        glVertex2f(m_points[0][0], m_points[0][1]);
        glVertex2f(m_points[1][0], m_points[1][1]);
        glVertex2f(m_points[2][0], m_points[2][1]);
        glVertex2f(m_points[3][0], m_points[3][1]);
    glEnd();
}

Mur::~Mur()
{
}
