#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "../lib/petite_fonction.h"
void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

void clean_ressources(SDL_Window *w,SDL_Renderer *r,SDL_Texture *t)
{
    if(t != NULL)
        SDL_DestroyTexture(t);
    if(r != NULL)
        SDL_DestroyRenderer(r);
    if(w != NULL)
        SDL_DestroyWindow(w);
}

void SDL_AfficherUneImage(SDL_Renderer *rendu,SDL_Surface *image,SDL_Texture *texture,SDL_Rect rectangle){
    if(image ==NULL){
        clean_ressources(NULL,rendu,texture);
        SDL_ExitWithError("Impossible de charger l'image");
    }
    texture= SDL_CreateTextureFromSurface(rendu,image);

    SDL_FreeSurface(image);
     if(texture ==NULL){
        clean_ressources(NULL,rendu,texture);
        SDL_ExitWithError("Impossible de creer la texture");
    }
    if(SDL_RenderCopy(rendu,texture,NULL,&rectangle)!=0){
        clean_ressources(NULL,rendu,texture);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }
    SDL_RenderPresent(rendu);
}