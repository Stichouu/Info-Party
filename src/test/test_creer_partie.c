#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "../lib/petite_fonction.h"
int main(int argc,char ** argv){
    SDL_Window *fenetre=NULL;
    int quitter=0;
    Uint32 affich_fenetre=SDL_WINDOW_MAXIMIZED;
    if(SDL_Init(SDL_INIT_VIDEO) != 0) //Lancement SDL
        SDL_ExitWithError("Initialisation SDL");
    fenetre=SDL_CreateWindow("INFO PARTY",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Fenetre_width,Fenetre_height,affich_fenetre);
    if (fenetre == NULL) {
        SDL_ExitWithError("La fenêtre n'a pas pu être créé");
    }
    SDL_GetWindowSize(fenetre,&Fenetre_width,&Fenetre_height);
    int joueur=4;
    int tour=4;
    creation_partie(fenetre,&joueur,&tour,&quitter);
    return 0;
}