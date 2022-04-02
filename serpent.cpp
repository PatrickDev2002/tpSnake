#include "serpent.h"

Serpent::Serpent()
{
}
/*
Algorithme de la methode initSerpent()
auteur : delvoye
date : 27 fevrier
Attribut de classe :
    boa : Serpent
    plateau : PlateauJeu
    appat : Vitamine
    vitesse : entier
Variables :
    i : entier
debut
    longueur <- 0
    tete.posX <- 30, tete.posT <- 10
    direction.posX <- 1, direction.posY <- 0
    carEffacement.posX <- tete.posX + 1
    carEffacement.posY <- tete.posY
    pour i allant de 0 a 99                             //100 etant la taille maximum du serpent
    {
        corps(i).posX <- 0
        corps(y).posY <- 0
    }
fin
*/
void Serpent::initSerpent()
{
    int i;
    longueur = 0;
    tete.posX = 30, tete.posY = 10;
    direction.posX = 1, direction.posY = 0;
    carEffacement.posX = tete.posX + 1;
    carEffacement.posY = tete.posY;
    for (i=0; i<100; i++)
    {
        corps[i].posX = 0;
        corps[i].posY = 0;
    }
}
/*
Algorithme de la methode afficheSerpent()
auteur : delvoye
date : 27 fevrier
Attribut de classe :
    boa : Serpent
    plateau : PlateauJeu
    appat : Vitamine
    vitesse : entier
Variables :
    i : entier
debut
    changement de couleur
    placement curseur en tete.posX + offsetX,tete.posY + offsetY
    afficher le caractere 245 de sa valeur ascii
    placement curseur en carEffacement.posX + offsetX, carEffacement.posY + offsetY
    afficher ' '
    pour i allant de 0 a longueur -1
    {
        placement curseur en corps(i).posX + offsetX, corps(i).posY + offsetY
        afficher le caractere 254 de sa valeur ascii
    }
fin
*/
void Serpent::afficheSerpent()
{
    int i;
    color(GREEN,BLACK);
    // affichage de la tête
    gotoxy(tete.posX + offsetX,tete.posY + offsetY);
    cout <<(char)245;
    gotoxy(carEffacement.posX + offsetX, carEffacement.posY + offsetY);
    cout << ' ';
    for (i=0; i<longueur; i++)                                                  // boucle qui affiche le corps selon sa taille
    {
        gotoxy(corps[i].posX + offsetX, corps[i].posY + offsetY);
        cout << char(254);
    }
}
/*
Algorithme de la methode allongeSerpent()
auteur : delvoye
date : 27 fevrier
attribut de classe :
    longueur
debut
    longueur <- longueur +1
fin
*/
void Serpent::allongeSerpent()
{
    longueur++;
}
/*
Algorithme de la methode deplaceSerpent()
auteur : delvoye
date : 27 fevrier
Attribut de classe :
    boa : Serpent
    plateau : PlateauJeu
    appat : Vitamine
    vitesse : entier
Variables :
    i : entier
debut
    si (longueur = 0)
    {
        carEffacement.posX <- tete.posX
        carEffacement.posY <- tete.posY
    }
    sinon
    {
        carEffacement.posX <- corps(longueur-1).posX
        carEffacement.posY <- corps(longueur-1).posY
        pour i allant de longueur-1 a 0 par pas de -1
        {
            corps(i).posX <- corps(i-1).posX
            corps(i).posY <- corps(i-1).posY
        }
        corps(0).posX <- tete.posX
        corps(0).posY <- tete.posY
    }
    tete.posX = tete.posX + direction.posX;
    tete.posY = tete.posY + direction.posY;
fin
*/
void Serpent::deplaceSerpent()
{
    int i;
    if(longueur==0) // il n'y a que la tête
        {
            carEffacement.posX=tete.posX;
            carEffacement.posY=tete.posY;
        }
    else
        {
            carEffacement.posX = corps[longueur-1].posX;
            carEffacement.posY = corps[longueur-1].posY ;
            for(i=longueur-1;i>0;i--)
            {
                corps[i].posX=corps[i-1].posX;
                corps[i].posY=corps[i-1].posY;
            }
            corps[0].posX=tete.posX;
            corps[0].posY=tete.posY;
        }
    tete.posX = tete.posX + direction.posX;
    tete.posY = tete.posY + direction.posY;

}
/*
Algorithme de la methode mortSerpent()
auteur : delvoye
date : 27 fevrier
Attribut de classe :
    boa : Serpent
    plateau : PlateauJeu
    appat : Vitamine
    vitesse : entier
Variables :
    i : entier
    mort<-0 : booleen
debut
    si (longueur>0)
    {
        pour (i allant de 0 a longueur-1)
        {
            si (tete.posX = corps(i).posX ET tete.posY = corps(i).posY) mort <- 1
        }
    }
    si (tete.posX = 0 OU tete.posY = 0 OU tete.posX = 61 OU tete.posY = 21)
    {
        mort <- 1
    }
    retourner mort
fin
*/
//-----------------------------------------------------------------------------------------------------------
bool Serpent::mortSerpent()
{
    int i;
    bool mort=0;
    if(longueur>0)
    {
        for (i=0; i<longueur; i++)
        {
            if (tete.posX==corps[i].posX && tete.posY==corps[i].posY)
                mort=1;
        }
    }
    if(tete.posX==0 || tete.posY==0 || tete.posX==61 || tete.posY==21)
    {
        mort=1;
    }
    return mort;
}
