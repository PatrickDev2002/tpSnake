#ifndef SERPENT_H
#define SERPENT_H
#include "structurepositionxy.h"

using namespace std;

class Serpent
{
public:
    PositionXY carEffacement;
    PositionXY corps[100];
    PositionXY direction;
    PositionXY tete;
    int longueur;
    void afficheSerpent();
    void allongeSerpent();
    void deplaceSerpent();
    void initSerpent();
    bool mortSerpent();
    Serpent();
};

#endif // SERPENT_H
