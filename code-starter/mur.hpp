#ifndef MUR_H
#define MUR_H

#include <GL/glu.h>
#include "bloc.hpp"

class Mur : public Bloc
{
public:
    Mur();
    virtual ~Mur();
    virtual void Display();
private:
};

#endif // MUR_H
