#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../../lib/plateau.h"
#include "../../lib/joueur.h"
#include "../../lib/partie.h"
#include "../../lib/petite_fonction.h"

int main(int argc,char ** argv){
  int liste_cases[NB_CASE];
  SDL_Rect cases[NB_CASE];
  int i;
  crea_plat(liste_cases,cases);

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
