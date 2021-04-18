#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

int Fenetre_width;
int Fenetre_height; 
void clean_ressources(SDL_Window *w,SDL_Renderer *r,SDL_Texture *t);
void SDL_AfficherUneImage(SDL_Renderer *rendu,SDL_Surface *image,SDL_Texture *texture,SDL_Rect rectangle);
void SDL_ExitWithError(const char *message);
void creation_partie(SDL_Window *fenetre,int * joueur, int * tour,int * quitter);
void menu(SDL_Window *fenetre,int * joueur, int * tour,int * quitter);
