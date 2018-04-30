#include <vector>
#include "palet.hpp"

Palet::Palet(float x, float y, float largeur, float hauteur)
{
    m_position[0] = x;
    m_position[1] = y;

    m_largeur = largeur;
    m_hauteur = hauteur;

    m_points[0][0] = m_position[0]-m_largeur/2.0f;
    m_points[0][1] = m_position[1]-m_hauteur/2.0f;
    m_points[1][0] = m_position[0]-m_largeur/2.0f;
    m_points[1][1] = m_position[1]+m_hauteur/2.0f;
    m_points[2][0] = m_position[0]+m_largeur/2.0f;
    m_points[2][1] = m_position[1]+m_hauteur/2.0f;
    m_points[3][0] = m_position[0]+m_largeur/2.0f;
    m_points[3][1] = m_position[1]-m_hauteur/2.0f;

    m_vitesse = 2.0f;
}

void Palet::decaler(const float x, const float y)
{
    m_points[0][0] += x*m_vitesse;
    m_points[1][0] += x*m_vitesse;
    m_points[2][0] += x*m_vitesse;
    m_points[3][0] += x*m_vitesse;

    m_points[0][1] += y*m_vitesse;
    m_points[1][1] += y*m_vitesse;
    m_points[2][1] += y*m_vitesse;
    m_points[3][1] += y*m_vitesse;
}

bool Palet::collision(Balle *balle)
{
    float x = balle->getCentreX();
    float y = balle->getCentreY();
    float rayon = balle->getRayon();

    if (y-rayon < m_points[1][1] && x > m_points[0][0] && x < m_points[2][0])
        return true;
    else
        return false;
}

void Palet::traiterCollision(Balle *balle)
{
    balle->setDirection(balle->getDirectionX(), -balle->getDirectionY());
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
