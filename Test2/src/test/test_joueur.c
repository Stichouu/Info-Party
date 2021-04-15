#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>
#include "../lib/plateau.h"
#include "../lib/joueur.h"
#include "../lib/partie.h"
#include "../lib/petite_fonction.h"

int main(int argc,char ** argv){
  SDL_Window * fenetre=NULL;
  Uint32 affich_fenetre=SDL_WINDOW_MAXIMIZED;
  if(SDL_Init(SDL_INIT_VIDEO) != 0) //Lancement SDL
    SDL_ExitWithError("Initialisation SDL");
  fenetre=SDL_CreateWindow("INFO PARTY",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Fenetre_width,Fenetre_height,affich_fenetre);
  if (fenetre == NULL) {
    SDL_ExitWithError("La fenêtre n'a pas pu être créé");
  }
  SDL_GetWindowSize(fenetre,&Fenetre_width,&Fenetre_height);

  int i;
  crea_plat(fenetre);

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
