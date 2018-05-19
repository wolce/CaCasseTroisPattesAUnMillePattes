#include <math.h>
#include "balle.hpp"
#include "palet.hpp"

Palet::Palet(float x, float y, float largeur, float hauteur, float xMin, float xMax)
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

    m_vitesse = 4.0f;
    m_angleMin = 25.0f;

    m_xMin = xMin;
    m_xMax = xMax;
}

void Palet::setCentreX(float positionCentreX)
{
    m_position[0] = positionCentreX;
    m_points[0][0] = m_position[0]-m_largeur/2.0f;
    m_points[1][0] = m_position[0]-m_largeur/2.0f;
    m_points[2][0] = m_position[0]+m_largeur/2.0f;
    m_points[3][0] = m_position[0]+m_largeur/2.0f;
}

void Palet::decaler(const float x, const float y)
{
    if (!((m_points[0][0] <= m_xMin && x < 0.0f) || (m_points[2][0] >= m_xMax && x > 0.0f)))
    {
        m_points[0][0] += x*m_vitesse;
        m_points[1][0] += x*m_vitesse;
        m_points[2][0] += x*m_vitesse;
        m_points[3][0] += x*m_vitesse;

        m_points[0][1] += y*m_vitesse;
        m_points[1][1] += y*m_vitesse;
        m_points[2][1] += y*m_vitesse;
        m_points[3][1] += y*m_vitesse;

        m_position[0] += x*m_vitesse;
        m_position[1] += y*m_vitesse;
    }
}

bool Palet::collision(Balle* &balle)
{
    float x = balle->getCentreX();
    float y = balle->getCentreY();
    float rayon = balle->getRayon();

    if (x+rayon>m_points[0][0] && x-rayon<m_points[2][0] && y-rayon<m_points[2][1] && y+rayon>m_points[0][1])
        return true;
    else
        return false;
}

void Palet::traiterCollision(Balle* &balle)
{
    float x = balle->getCentreX();
    float y = balle->getCentreY();
    float dirX = balle->getDirectionX();
    float dirY = balle->getDirectionY();
    float rayon = balle->getRayon();

    if (y>m_points[1][1] && !(x<m_points[1][0] || x>m_points[2][0]))
    {
        float pos = (x - m_points[0][0])/m_largeur; // Position relative de la balle sur le palet (0 au bord gauche et 1 au bord droit)

        pos = pos * (180.0f-2*m_angleMin) + m_angleMin; // On ramène à une échelle [m_angleMin ; 180-m_angleMin]
        pos = pos * M_PI/180.0f; // Passage en radian

        balle->setDirection(-cos(pos), sin(pos)); // Changement de direction de la balle
    }

    else if (!(y<m_points[0][1] || y>m_points[1][1]) && x<m_points[1][0])
    {
        if (dirX > 0)
            balle->setDirection(-dirX, dirY);

        balle->setCentreX(m_points[0][0]-rayon);
    }

    else if (!(y<m_points[0][1] || y>m_points[1][1]) && x>m_points[2][0])
    {
        if (dirX < 0)
            balle->setDirection(-dirX, dirY);

        balle->setCentreX(m_points[2][0]+rayon);
    }
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

void Palet::setLargeur(float largeur)
{
    m_largeur = largeur;

    m_points[0][0] = m_position[0]-m_largeur/2.0f;
    m_points[1][0] = m_position[0]-m_largeur/2.0f;
    m_points[2][0] = m_position[0]+m_largeur/2.0f;
    m_points[3][0] = m_position[0]+m_largeur/2.0f;
}

Palet::~Palet()
{

}
