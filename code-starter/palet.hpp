#ifndef PALET_H
#define PALET_H

#include <GL/glu.h>
#include "bloc.hpp"

class Palet : public Bloc
{
public:
    Palet();
    virtual ~Palet();
    virtual void Display();
    virtual bool collision(Balle *balle);
    void decaler(const float x, const float y); // Applique une translation au palet
private:
    float m_vitesse;
};

#endif // PALET_H
