#include "plateaujeu.h"

PlateauJeu::PlateauJeu()
{
    affichePlateau();
}
//-----------------------------------------------------------------------------------------------------------
/*
Algorithme de la methode affichePlateau()
auteur : delvoye patrick
date : 09 Fevrier
variables de classe :
    offsetX, offsetY
variables :
    i, : entier
debut
    effacement d'ecran
    changement de couleur
    afficher : "Jeu du Serpent - TP 09 Snake "
    pour i allant de 24 à 51
        changement de couleur
        afficher le caractere 254 de sa valeur ascii                    // Boucle soulignant le titre
    pour i allant de 0 à 61
        changement de couleur
        placer curseur en offsetX d'abscisse offsetX et d'ordonnée offsetY
        afficher le caractere 201 de sa valeur ascii                                            // 201 correspond au coin superieur gauche
        placer curseur en offsetX + i , offsetY + 22
        afficher le caractere 205                                                               // 205 correspond a la ligne du haut
        placer curseur en offsetX + i , offsetY + 22 + 22                                       // Boucle pour faire le contour du plateau de jeu
        afficher le caractere 205
        placer curseur en offsetX + 61 , offsetY
        afficher le caractere 187                                                               // 187 correspond au coin superieur droit
        placer curseur en offsetX , offsetY + 22
        afficher le caractere 200                                                               // 200 correspond au coin inferieur gauche
        placer curseur en offsetX + 61 , offsetY + 22
        afficher le caractere 188                                                               // 188 correspond au coin inferieur droit
    pour i allant de 1 à 21
        changement de couleur
        placer curseur en offsetX , offsetY + i
        afficher le caractere 186                                                   // 186 correspond a la ligne du bas
        placer curseur en offsetX + 61 , offsetY + i
        afficher le caractere 186
fin
*/
void PlateauJeu::affichePlateau()
{
    system("cls");
    int i;
    gotoxy(23,1);
    color(YELLOW,BLACK);
    cout <<" Jeu du Serpent - TP 09 Snake ";
    for (i=24; i<52; i++)
    {
    color(RED,BLACK);
    gotoxy(i,2);
    cout << char(254);
    }
    for (i=0; i<62; i++)
    {
        color(YELLOW,BLACK);
        gotoxy(offsetX, offsetY);
        cout << char(201);
        gotoxy(offsetX + i, offsetY);
        cout << char(205);
        gotoxy(offsetX + i, offsetY + 22);
        cout << char(205);
        gotoxy(offsetX + 61, offsetY);
        cout << char(187);
        gotoxy(offsetX, offsetY + 22);
        cout << char(200);
        gotoxy(offsetX + 61, offsetY + 22);
        cout << char(188);
    }
    for (i=1; i<22; i++)
    {
        color(YELLOW,BLACK);
        gotoxy(offsetX, offsetY + i);
        cout << char(186);
        gotoxy(offsetX + 61, offsetY + i);
        cout << char(186);
    }
}
