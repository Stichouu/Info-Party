#ifndef _PARTIE_H_
#define _PARTIE_H_
#include "joueur.h"
#include "plateau.h"


#define NB_TOURS 20

void ordre_jeu();
void une_partie(SDL_Window *fenetre,SDL_Renderer * rendu,SDL_Rect cases[NB_CASE],int liste_case[NB_CASE],int nb_tours,int nb_joueurs);

#endif
