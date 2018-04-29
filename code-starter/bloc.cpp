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

void Bloc::decaler(const float x, const float y)
{
    m_points[0][0] += x;
    m_points[1][0] += x;
    m_points[2][0] += x;
    m_points[3][0] += x;

    m_points[0][1] += y;
    m_points[1][1] += y;
    m_points[2][1] += y;
    m_points[3][1] += y;
}

void Bloc::Display()
{

}
