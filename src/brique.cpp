#include "balle.hpp"
#include "brique.hpp"

Brique::Brique(float x, float y, float largeur)// x et y du coin supérieur gauche
{
    m_position[0] = x;
    m_position[1] = y;
    m_largeur = largeur;
    m_hauteur = largeur/3.0f;
}

bool Brique::collision(Balle* &balle)
{
    float x = balle->getCentreX();
    float y = balle->getCentreY();
    float rayon = balle->getRayon();

    if (x+rayon>m_position[0] && x-rayon<m_position[0]+m_largeur && y-rayon<m_position[1] && y+rayon>m_position[1]-m_hauteur)
        return true;
    else
        return false;
}

void Brique::traiterCollision(Balle* &balle)
{
    float x = balle->getCentreX();
    float y = balle->getCentreY();
    float dirX = balle->getDirectionX();
    float dirY = balle->getDirectionY();

    // Si le centre de la balle est en-dessous du côté du dessous ou au-dessus du côté du dessus, mais pas à gauche du côté gauche ou à droite du côté droit
    if ((y<m_position[1]-m_hauteur || y>m_position[1]) && !(x<m_position[0] || x>m_position[0]+m_largeur))
        balle->setDirection(dirX, -dirY);

    // Si le centre de la balle est à gauche du côté gauche ou à droite du côté droit, mais pas en-dessous du côté du dessous ou au-dessus du côté du dessus
    else if ((x<m_position[0] || x>m_position[0]+m_largeur) && !(y<m_position[1]-m_hauteur || y>m_position[1]))
        balle->setDirection(-dirX, dirY);

    // Sinon il s'agit d'un coin
    else
    {
        if (x<m_position[0] && y>m_position[1]) // Coin haut gauche
        {
            if (dirX>0.0f && dirY>=0.0f) // Angle d'arrivée : ]-90;180]
                balle->setDirection(-dirX, dirY);
            else if (dirX<=0.0f && dirY<0.0f) // Angle d'arrivée : ]0;90]
                balle->setDirection(dirX, -dirY);
            else // Angle d'arrivée : ]90;180[
                balle->setDirection(-dirX, -dirY);
        }

        else if (x>m_position[0]+m_largeur && y>m_position[1]) // Coin haut droit
        {
            if (dirX>=0.0f && dirY<0.0f) // Angle d'arrivée : [90;180[
                balle->setDirection(dirX, -dirY);
            else if (dirX<0.0f && dirY>=0.0f) // Angle d'arrivée : [0;-90[
                balle->setDirection(-dirX, dirY);
            else // Angle d'arrivée : ]90;180[
                balle->setDirection(-dirX, -dirY);
        }

        else if (x>m_position[0]+m_largeur && y<m_position[1]-m_hauteur) // Coin bas droit
        {
            if (dirX<0.0f && dirY<=0.0f) // Angle d'arrivée : [0;90[
                balle->setDirection(-dirX, dirY);
            else if (dirX>=0.0f && dirY>0.0f) // Angle d'arrivée : [-90;-180[
                balle->setDirection(dirX, -dirY);
            else // Angle d'arrivée : ]90;180[
                balle->setDirection(-dirX, -dirY);
        }

        else if (x<m_position[0] && y<m_position[1]-m_hauteur) // Coin bas gauche
        {
            if (dirX<=0.0f && dirY>0.0f) // Angle d'arrivée : ]0;-90]
                balle->setDirection(dirX, -dirY);
            else if (dirX>0.0f && dirY<=0.0f) // Angle d'arrivée : ]90;180]
                balle->setDirection(-dirX, dirY);
            else // Angle d'arrivée : ]-90;-180[
                balle->setDirection(-dirX, -dirY);
        }
    }
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
