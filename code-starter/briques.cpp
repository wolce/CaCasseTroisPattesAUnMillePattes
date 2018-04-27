#include "briques.h"

Briques::Briques(float x, float y, bool Zbuffer)// x et y du coin supérieur gauche
{
    m_x=x;
    m_y=y;
    m_Zbuffer=Zbuffer;
}
void Briques::Display()//j'affiche la brique avec un rapport 1 de hauteur pour 3 de largeur
{
    glBegin(GL_QUADS);
    glVertex2f(m_x, m_y);
    glVertex2f(m_x, m_y-1);
    glVertex2f(m_x+3, m_y-1);
    glVertex2f(m_x+3, m_y);
    glEnd();
}
Briques::~Briques()
{

}
