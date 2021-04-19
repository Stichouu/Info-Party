#include "../../include/joueur.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
  int i;
  crea_plat();

  printf("\n Test création joueurs... \n\n");
  crea_joueurs();
  for(i=0; i<NB_JOUEURS; i++){
    printf("Position du joueur: %i\n", liste_joueurs[i]->position->nb_case);
    printf("Nombre de pieces: %i\n", liste_joueurs[i]->nb_pieces);
    printf("Nombre de badge: %i\n", liste_joueurs[i]->nb_badges);
    printf("Numero du joueur: %i\n\n\n", liste_joueurs[i]->num_joueur);
  }


  return(0);
}
