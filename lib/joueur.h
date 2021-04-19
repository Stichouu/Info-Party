#ifndef _JOUEUR_H_
#define _JOUEUR_H_

#include "plateau.h"

#define NB_JOUEURS 4


typedef struct joueur{
  t_case * position;
  int nb_pieces;
  int nb_badges;
  int num_joueur;
}t_joueur;

t_joueur * jou1;
t_joueur * jou2;
t_joueur * jou3;
t_joueur * jou4;
t_joueur * liste_joueurs[NB_JOUEURS];

void crea_joueurs();
void effet_case(t_joueur * jou);
void afficher_joueur_case(SDL_Renderer * rendu, SDL_Rect cases[NB_CASE], int case_courant[NB_JOUEURS], int joueur);
void afficher_joueur_bouge(SDL_Window *fenetre,SDL_Renderer * rendu, SDL_Rect cases[NB_CASE],int liste_case[NB_CASE],int NB_DES, int case_courant[NB_JOUEURS],int joueur,int nb_joueurs);
void affichage_joueur_et_des(SDL_Renderer * rendu,int joueur,int numero_des);
#endif
