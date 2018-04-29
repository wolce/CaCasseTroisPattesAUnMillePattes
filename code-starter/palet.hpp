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
private:
};

#endif // PALET_H
