#ifndef JEUSERPENT_H
#define JEUSERPENT_H
#include "structurepositionxy.h"
#include "serpent.h"
#include "plateaujeu.h"
#include "vitamine.h"

class JeuSerpent
{
public:
    void jouerJeuSerpent();
    JeuSerpent();
private:
    int vitesse;
    Serpent boa;
    PlateauJeu plateau;
    Vitamine appat;
};

#endif // JEUSERPENT_H
