#include "bloc.hpp"

Bloc::Bloc()
{
    m_couleurs[0] = 1.0f;
    m_couleurs[1] = 1.0f;
    m_couleurs[2] = 1.0f;
}

bool Bloc::collision(Balle *balle)
{
    return false;
}

Bloc::~Bloc()
{

}

void Bloc::Display()
{

}
