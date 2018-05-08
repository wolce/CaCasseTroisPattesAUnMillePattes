#include <cstdlib>
#include <math.h>

#include "balle.hpp"
#include "palet.hpp"

Balle::Balle(float x, float y, float dirX, float dirY)
{
    m_rayon = 2.0f;
    m_sphere = gluNewQuadric();

    // La couleur par défaut de la balle est le bleu :
    m_couleur[0] = 0.2f;
    m_couleur[1] = 0.2f;
    m_couleur[2] = 1.0f;

    m_positionCentre[0] = x;
    m_positionCentre[1] = y;

    m_direction[0] = dirX;
    m_direction[1] = dirY;

    m_vitesse = 0.2f;
}

Balle::Balle(Palet *palet)
{
    m_rayon = 2.0f;
    m_sphere = gluNewQuadric();

    // La couleur par défaut de la balle est le bleu :
    m_couleur[0] = 0.2f;
    m_couleur[1] = 0.2f;
    m_couleur[2] = 1.0f;

    m_positionCentre[0] = palet->getCentreX();
    m_positionCentre[1] = palet->getCentreY() + palet->getHauteur()/2.0f + m_rayon;

    float dir = rand()/(float)RAND_MAX;
    float angleMin = palet->getAngleMin();
    dir = dir * (180.0f - 2*angleMin) + angleMin;
    dir *= M_PI/180.0;

    m_direction[0] = cos(dir);
    m_direction[1] = sin(dir);

    m_vitesse = 0.2f;
    m_estSurPalet = true;
}

void Balle::Display()
{
    glPushMatrix(); // On stocke le repère d’origine
    glTranslatef(m_positionCentre[0], m_positionCentre[1], 0.0f); // On lui applique une translation
    glColor3f(m_couleur[0], m_couleur[1], m_couleur[2]); // On définit la couleur courante
    gluSphere(m_sphere, m_rayon, 16, 16); // On dessine une sphère
    glPopMatrix(); // On retourne au repère d’origine
}

void Balle::deplacer()
{
    m_positionCentre[0] += m_direction[0]*m_vitesse;
    m_positionCentre[1] += m_direction[1]*m_vitesse;
}

Balle::~Balle()
{
    gluDeleteQuadric(m_sphere);
}
