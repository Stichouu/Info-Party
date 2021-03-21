#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#define Fenetre_width 1280
#define Fenetre_height 720
void clean_ressources(SDL_Window *w,SDL_Renderer *r,SDL_Texture *t);
void SDL_AfficherUneImage(SDL_Renderer *rendu,SDL_Surface *image,SDL_Texture *texture,SDL_Rect rectangle);
void SDL_ExitWithError(const char *message);