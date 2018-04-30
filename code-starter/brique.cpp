#include "brique.hpp"

Brique::Brique(float x, float y, float largeur)// x et y du coin supérieur gauche
{
    m_position[0] = x;
    m_position[1] = y;
    m_largeur = largeur;
    m_hauteur = largeur/3.0f;
}

bool Brique::collision(Balle *balle)
{
    float x = balle->getCentreX();
    float y = balle->getCentreY();
    float rayon = balle->getRayon();

    if (x+rayon>m_position[0] && x-rayon<m_position[0]+m_largeur && y-rayon<m_position[1] && y+rayon>m_position[1]-m_hauteur)
        return true;
    else
        return false;
}

void Brique::traiterCollision(Balle *balle)
{
    float x = balle->getCentreX();
    float y = balle->getCentreY();
    float rayon = balle->getRayon();

    if (x+rayon>m_position[0] && x-rayon<m_position[0]+m_largeur)
        balle->setDirection(balle->getDirectionX(), -balle->getDirectionY());
    else if (y-rayon<m_position[1] && y+rayon>m_position[1]-m_hauteur)
        balle->setDirection(-balle->getDirectionX(), balle->getDirectionY());
    else
        balle->setDirection(-balle->getDirectionX(), -balle->getDirectionY());
}

void Brique::Display()//j'affiche la brique avec un rapport 1 de hauteur pour 3 de largeur
{
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(m_position[0], m_position[1]);
        glVertex2f(m_position[0], m_position[1]-m_hauteur);
        glVertex2f(m_position[0]+m_largeur, m_position[1]-m_hauteur);
        glVertex2f(m_position[0]+m_largeur, m_position[1]);
    glEnd();
}

Brique::~Brique()
{

}
