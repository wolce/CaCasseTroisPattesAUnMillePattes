#include <vector>
#include "palet.hpp"

Palet::Palet()
{
    m_points[0][0] = 40.0f;
    m_points[0][1] = 1.0f;
    m_points[1][0] = 40.0f;
    m_points[1][1] = 3.0f;
    m_points[2][0] = 60.0f;
    m_points[2][1] = 3.0f;
    m_points[3][0] = 60.0f;
    m_points[3][1] = 1.0f;

    //m_cotesSpeciaux.push_back({1,4});

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

    if (y-rayon < -4.0f && x>-3.5f && x<3.5f)
        return true;
    else
        return false;
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
