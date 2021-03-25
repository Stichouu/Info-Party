#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>

void SDL_AfficherUneImage(SDL_Renderer *rendu,SDL_Surface *image,SDL_Texture *texture,SDL_Rect rectangle){
    if(image ==NULL){
        clean_ressources(NULL,NULL,NULL);
        SDL_ExitWithError("Impossible de charger l'image");
    }
    texture= SDL_CreateTextureFromSurface(rendu,image);

    SDL_FreeSurface(image);
     if(texture ==NULL){
        clean_ressources(NULL,NULL,NULL);
        SDL_ExitWithError("Impossible de creer la texture");
    }
    if(SDL_QueryTexture(texture,NULL,NULL,&rectangle.w,&rectangle.h)!=0){
        clean_ressources(NULL,NULL,NULL);
        SDL_ExitWithError("Impossible de charger la texture");
    }
    if(SDL_RenderCopy(rendu,texture,NULL,&rectangle)!=0){
        clean_ressources(NULL,NULL,NULL);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }
    SDL_RenderPresent(rendu);
}
