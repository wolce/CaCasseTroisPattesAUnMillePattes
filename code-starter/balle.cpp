#include "balle.hpp"

Balle::Balle()
{
    m_rayon = 0.7f;
    m_sphere = gluNewQuadric();

    // La couleur par défaut de la balle est le bleu :
    m_couleur[0] = 0.2f;
    m_couleur[1] = 0.2f;
    m_couleur[2] = 1.0f;
}

void Balle::Display() //translation de la ball : mouvement
{
    glPushMatrix(); // On stocke le repère d’origine
    glTranslatef(m_positionCentre[0], m_positionCentre[1], 0.0f); // On lui applique une translation
    glColor3f(m_couleur[0], m_couleur[1], m_couleur[2]); // On définit la couleur courante
    gluSphere(m_sphere, m_rayon, 16, 16); // On dessine une sphère
    glPopMatrix(); // On retourne au repère d’origine
}

Balle::~Balle()
{
    gluDeleteQuadric(m_sphere);
}
