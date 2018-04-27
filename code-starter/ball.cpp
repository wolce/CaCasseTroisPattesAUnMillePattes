#include "ball.h"

ball::ball()
{
    m_quadrique=gluNewQuadric();
}
void ball::Display(const float x,const float y) //translation de la ball : mouvement
{
    GLUquadric* quadrique=gluNewQuadric();
    glPushMatrix(); // On stocke le repère d’origine
    glTranslatef(x, y, 0.0); // On lui applique une translation
    glColor3f(0.2, 0.2, 1.0); // On définit la couleur courante comme étant bleue
    gluSphere(quadrique, 0.7, 20, 20); // On dessine une sphère
    glPopMatrix(); // On retourne au repère d’origine

}
ball::~ball()
{
    gluDeleteQuadric(m_quadrique);
}
