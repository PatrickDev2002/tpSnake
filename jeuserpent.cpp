#include "jeuserpent.h"

JeuSerpent::JeuSerpent()
{
    jouerJeuSerpent();
}
//-----------------------------------------------------------------------------------------------------------
/*
Algorithme methode jouerJeuSerpent()
auteur : delvoye
date : 15 fevrier
Attribut de classe :
    boa : Serpent
    plateau : PlateauJeu
    appat : Vitamine
    vitesse : entier
Variables :
    car : caractere
Debut
    faire
    {
        appel de la methode plateau.affichePlateau()
        changement de couleur
        aller a droite du plateau (avec x=75 et y=5)
        afficher : "Utilisez les flèches pour vous diriger"
        appel de la methode boa.initSerpent()
        appel de la methode appat.deplaceVitamine()
        initialisation de la variable vitesse // vitesse à 150
        appel de la methode boa.afficheSerpent ()
        attente de l’appuie d’une toucheClavier pour débuter la partie.
        faire
        {
        appel de la methode appat.afficheVitamine()
        si (position de la tete du serpent en x=position de la vitamine en x ET position tete serpent en y = position vitamine en y)
            {
            appel methode boa.allongeSerpent()
            appel methode appat.deplaceVitamine()
            changement de couleur
            placement curseur
            afficher " Niveau :" boa.longueur                 // pour voir a quel niveau le joueur est en fonction de la taille du serpent
            si (boa.longueur = 3) vitesse <- vitesse -10
            si (boa.longueur = 6) vitesse <- vitesse -10
            si (boa.longueur = 9) vitesse <- vitesse -10
            si (boa.longueur = 12) vitesse <- vitesse -10
            si (boa.longueur = 18) vitesse <- vitesse -5
            si (boa.longueur = 24) vitesse <- vitesse -5
            si (boa.longueur = 30) vitesse <- vitesse -5
            si (boa.longueur = 40) vitesse <- vitesse -5
            changement de couleur
            placement curseur
            afficher "Vitesse :" vitesse
            }
        appel methode boa.deplaceSerpent()
        appel methode boa.afficheSerpent

        si (touche clavier = 1)                             //ici on utilise la fonction kbhit pour verifier si une touche est tapee
            {
            car <- fonction qui retourne la touche tapée au clavier
            si (car = 224)                                  //ici on verifie si la touche correspond la ou se trouve les fleches directionnelles
                {
                car <- fonction qui retourne la touche tapée au clavier
                si(car = 72)
                    {
                    boa.direction.posX <- 0
                    boa.direction.posY <- -1
                    }
                si (car = 80)
                    {
                    boa.direction.posX <- 0
                    boa.direction.posY <- 1
                    }
                si (car = 75)
                    {
                    boa.direction.posX <- -1
                    boa.direction.posY <- 0
                    }
                si (car = 77)
                    {
                    boa.direction.posX <- 1
                    boa.direction.posY <- 0
                    }
                }
            }
            placement curseur
            Sleep(vitesse)                                  //ici on utilise la fonction Sleep pour gerer la vitesse de jeu en fonction de la vitesse
        }
        tant que boa.mortSerpent <> 1
        placement curseur
        afficher " Perdu - Voulez-vous recommencer (o/n) ? "
        car <- fonction qui retourne la touche tapée au clavier
    }tant que ( car = 'n' ou car = 'N' )
*/
void JeuSerpent::jouerJeuSerpent()
{
    unsigned char car;
    do
    {
        plateau.affichePlateau();
        color(BLUE, BLACK);
        gotoxy(76,5);
        cout<< "Utilisez les fl"<<char(138)<<"ches pour vous diriger";
        boa.initSerpent();
        appat.deplaceVitamine();
        vitesse=150;
        boa.afficheSerpent();
        getch();
        do
        {
            appat.afficheVitamine();
            if (boa.tete.posX == appat.vit.posX && boa.tete.posY == appat.vit.posY)
            {
                boa.allongeSerpent();
                appat.deplaceVitamine();
                color(PURPLE,BLACK);
                gotoxy(75,7);                                       //affichage de la longueur du serpent
                cout<< " Niveau : "<<boa.longueur;
                if (boa.longueur==3) vitesse = vitesse -10;         //diminution de la vitesse au fur et a mesure
                if (boa.longueur==6) vitesse = vitesse -10;         //apparition de la nouvelle vitamine quand la longueur a depasse 6
                if (boa.longueur==9) vitesse = vitesse -10;
                if (boa.longueur==12) vitesse = vitesse -10;
                if (boa.longueur==18) vitesse = vitesse -5;
                if (boa.longueur==24) vitesse = vitesse -5;
                if (boa.longueur==30) vitesse = vitesse -5;
                if (boa.longueur==40) vitesse = vitesse -5;
                color(RED,BLACK);
                gotoxy(75,9);
                cout<< " Vitesse :"<<vitesse/10<<" millisecondes/cases";
            }
            boa.deplaceSerpent();
            boa.afficheSerpent();

            if (kbhit() == 1)
            {
                car = getch();
                if (car==224)                                   //correspond au bloc des fleches directionelles
                {
                    // 77 = fleche de droite
                    // 72 = fleche du haut
                    // 75 = fleche de gauche
                    // 80 = fleche du bas
                    car = getch();
                    if (car==72)
                    {
                        boa.direction.posX = 0;
                        boa.direction.posY = -1;
                    }
                    if (car==80)
                    {
                        boa.direction.posX = 0;
                        boa.direction.posY = 1;
                    }
                    if (car==75)
                    {
                        boa.direction.posX = -1;
                        boa.direction.posY = 0;
                    }
                    if(car==77)
                    {
                        boa.direction.posX = 1;
                        boa.direction.posY = 0;
                    }
                }

            }
            color(YELLOW,BLACK);
            gotoxy(offsetX, offsetY);       // sans cette ligne pour "actualiser" le coin supérieur gauche, il s'efface
            cout << char(201);
            color(GREEN,BLACK);
            gotoxy(1,1);                                                  //met le curseur en haut a gauche de la fenetre, en dehors du plateau
            Sleep(vitesse);
        } while (boa.mortSerpent()!=1);
        gotoxy(20,27);
        cout << "Perdu ! - Voulez-vous recommencer (o/n) ? ";
        car = getch();
    } while (car != 'n' && car != 'N');
    clear();
    gotoxy(40,15);
    cout<<"Merci d'avoir joue a mon jeu ...";
}
