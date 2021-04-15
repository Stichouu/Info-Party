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

#endif
