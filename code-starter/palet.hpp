#ifndef PALET_H
#define PALET_H

#include <GL/glu.h>


class Palet
{
public:
    Palet();
    virtual ~Palet();
    void Display(const float position, const float distance);
private:
    float m_position;
    float m_distance;
    float m_couleur[3];
};

#endif // PALET_H
