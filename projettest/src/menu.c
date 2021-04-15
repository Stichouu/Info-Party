#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "fonction_utile.h"
void clean_ressources(SDL_Window *w,SDL_Renderer *r,SDL_Texture *t)
{
    if(t != NULL)
        SDL_DestroyTexture(t);
    if(r != NULL)
        SDL_DestroyRenderer(r);
    if(w != NULL)
        SDL_DestroyWindow(w);
    SDL_Quit();
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
    if(SDL_QueryTexture(texture,NULL,NULL,&rectangle.w,&rectangle.h)!=0){
        clean_ressources(NULL,rendu,texture);
        SDL_ExitWithError("Impossible de charger la texture");
    }
    if(SDL_RenderCopy(rendu,texture,NULL,&rectangle)!=0){
        clean_ressources(NULL,rendu,texture);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }
    SDL_RenderPresent(rendu);
}
void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}


int main(int argc, char *argv[])
{
	SDL_Window *window = NULL;
	SDL_Renderer *rendu= NULL;
	SDL_Surface *imagefond =NULL;
	SDL_Surface *etoile =NULL;
	SDL_Texture *texture=NULL;
	Uint32 affiche_fenetre=SDL_WINDOW_MAXIMIZED;
    SDL_Rect rectangle={0,0,Fenetre_width,Fenetre_height};
    SDL_Rect dst={ 0, 0, 1200, 700 };
    SDL_bool program =SDL_TRUE;

  	//Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("Initialisation SDL");
    //Création fenêtre et rendu
    if(SDL_CreateWindowAndRenderer(Fenetre_width,Fenetre_height,affiche_fenetre,&window,&rendu) != 0)
        SDL_ExitWithError("Impossible de creer la fenetre et le rendu");
    imagefond = IMG_Load("src/lac_en_montagne.bmp");
    SDL_AfficherUneImage(rendu,imagefond,texture,rectangle);
    while(program){
    	SDL_Event event;
    	while (SDL_PollEvent(&event)) {
    		switch(event.type)
    		{
    			case SDL_QUIT:
    				program=SDL_FALSE;
    				break;
    			case SDL_MOUSEBUTTONUP:
    				if((event.button.x>900 && event.button.x<1000) && (event.button.y>800 && event.button.y<900))
    					program=SDL_FALSE;
    				break;
    			default:
    				break;
    		}
    	}
    }	

	clean_ressources(window,rendu,texture);
	return EXIT_SUCCESS;
}

/*
    GNU/Linux et MacOS
        > gcc menu.c $(sdl2-config --cflags --libs) -o prog
        > gcc *.c $(sdl2-config --cflags --libs) -o prog
    Windows
        > gcc src/menu.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
        > gcc src/menu.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows
*/