#include "balle.hpp"

Balle::Balle()
{
    m_rayon = 0.7;
    m_sphere = gluNewQuadric();

    // La couleur par défaut de la balle est le bleu :
    m_couleur[0] = 0.2;
    m_couleur[1] = 0.2;
    m_couleur[2] = 1.0;
}

void Balle::Display(const float x, const float y) //translation de la ball : mouvement
{
    glPushMatrix(); // On stocke le repère d’origine
    glTranslatef(x, y, 0.0); // On lui applique une translation
    glColor3f(0.2, 0.2, 1.0); // On définit la couleur courante
    gluSphere(m_sphere, m_rayon, 16, 16); // On dessine une sphère
    glPopMatrix(); // On retourne au repère d’origine
}

Balle::~Balle()
{
    gluDeleteQuadric(m_sphere);
}
