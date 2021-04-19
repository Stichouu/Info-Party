#ifndef _PARTIE_H_
#define _PARTIE_H_
#include "joueur.h"
#include "plateau.h"
/**
* \file partie.h
* \author Tan Tony
* \author Tessier Killian
* \version 1.3
* \brief fonction prototype de partie.c
*/
/**
*\param NB_TOURS le nombre de tours sert à faire tourner le jeu pendant un certaun nombre de tour et en l'occurence, ici, 20
* 
*/

#define NB_TOURS 20

void ordre_jeu();
void une_partie(SDL_Window *fenetre,SDL_Renderer * rendu,SDL_Rect cases[NB_CASE],int liste_case[NB_CASE],int nb_tours,int nb_joueurs);

#endif
