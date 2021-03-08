#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"


/* Initialisation des joueurs */
void crea_joueurs(){
  int i;
  jou1 = malloc(sizeof(t_joueur));

  jou2 = malloc(sizeof(t_joueur));

  jou3 = malloc(sizeof(t_joueur));

  jou4 = malloc(sizeof(t_joueur));

  en_tete_plat(); // pour placer ec sur la case de départ
  for(i=0; i<NB_JOUEURS; i++){
    switch(i){
      case 0: liste_joueurs[i]=jou1;break;
      case 1: liste_joueurs[i]=jou2; break;
      case 2: liste_joueurs[i]=jou3; break;
      case 3: liste_joueurs[i]=jou4; break;
    }
    liste_joueurs[i]->position=ec; // tous les joueurs commencent sur la case de départ
    liste_joueurs[i]->nb_pieces=10;
    liste_joueurs[i]->nb_badges=0;
    liste_joueurs[i]->num_joueur=i+1;
  }
}
