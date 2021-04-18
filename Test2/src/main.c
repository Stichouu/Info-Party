#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>
#include "../lib/plateau.h"
#include "../lib/joueur.h"
#include "../lib/partie.h"
#include "../lib/petite_fonction.h"



int main(int argc, char *argv[]){
  int joueur=4;
  int tour=4;
  int quitter=0;
  int liste_cases[NB_CASE];
  SDL_Rect cases[NB_CASE];
  SDL_Window *fenetre=NULL;
  SDL_Renderer *rendu= NULL;
  Uint32 affich_fenetre=SDL_WINDOW_MAXIMIZED;
  if(SDL_Init(SDL_INIT_VIDEO) != 0) //Lancement SDL
    SDL_ExitWithError("Initialisation SDL");
  //Création de la fenêtre
  fenetre=SDL_CreateWindow("INFO PARTY",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Fenetre_width,Fenetre_height,affich_fenetre);
  if (fenetre == NULL) {
    SDL_ExitWithError("La fenêtre n'a pas pu être créé");
  }
  SDL_GetWindowSize(fenetre,&Fenetre_width,&Fenetre_height);
  menu(fenetre,&joueur,&tour,&quitter);
  if(quitter==0){
  printf("%i",joueur);
  srand( time( NULL ) );
  crea_plat(liste_cases,cases);
    //Création du rendu de plateau
  rendu=SDL_CreateRenderer(fenetre,-1,0);
  if(rendu == NULL)
    SDL_ExitWithError("Le rendu n'a pas pu être créé");

  afficher_plateau(fenetre,rendu,cases,liste_cases);
  crea_joueurs();
  une_partie(fenetre,rendu,cases,liste_cases,tour,joueur);
  clean_ressources(fenetre,rendu,NULL);
  }
  return 0;
}
