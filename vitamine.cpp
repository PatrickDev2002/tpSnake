#include "vitamine.h"

Vitamine::Vitamine()
{
    srand(time(0));         // Initialise le generateur de nombre aleatoire a zero
}
//-----------------------------------------------------------------------------------------------------------
void Vitamine::afficheVitamine()
{
    gotoxy(offsetX + vit.posX,offsetY + vit.posY);      // affiche la position de la vitamine selon les parametres aleatoire de deplaceVitamine
    cout<< char(219);
}
//-----------------------------------------------------------------------------------------------------------
void Vitamine::deplaceVitamine()
{
    vit.posX = rand()%60 +1;                //genere une position aleatoire de la vitamine
    vit.posY = rand()%20 +1;
}
