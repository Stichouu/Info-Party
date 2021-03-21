/*
    GNU/Linux et MacOS
        > gcc main.c $(sdl2-config --cflags --libs) -o prog
        > gcc *.c $(sdl2-config --cflags --libs) -o prog
    Windows
        > gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
        > gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#define Fenetre_width 1280
#define Fenetre_height 720
void SDL_ExitWithError(const char *message);

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *rendu= NULL;
    SDL_Surface *image =NULL;
    SDL_Texture *texture=NULL;
    SDL_Rect rectangle;
    rectangle.x=Fenetre_width/4;
    rectangle.y=Fenetre_height/4;
    int droite=0;
    int imagew=Fenetre_width/2;
    int imageh=Fenetre_height/2;
    SDL_bool program =SDL_TRUE;

    //Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("Initialisation SDL");
    //Création fenêtre et rendu
    if(SDL_CreateWindowAndRenderer(Fenetre_width,Fenetre_height,0,&window,&rendu) != 0)
        SDL_ExitWithError("Impossible de creer la fenetre et le rendu");

 if(SDL_SetRenderDrawColor(rendu,0,0,0,SDL_ALPHA_OPAQUE) !=0)
        SDL_ExitWithError("Impossible de changer la couleur pour le rendu");

    /*------------------------------------------------------------*/
    image = SDL_LoadBMP("src/étoile.bmp");
    if(image ==NULL){
        SDL_DestroyRenderer(rendu);
        SDL_DestroyWindow(window);
         SDL_ExitWithError("Impossible de charger l'image");
    }
    texture= SDL_CreateTextureFromSurface(rendu,image);

    SDL_FreeSurface(image);
     if(texture ==NULL){
        SDL_DestroyRenderer(rendu);
        SDL_DestroyWindow(window);
         SDL_ExitWithError("Impossible de creer la texture");
    }
    if(SDL_QueryTexture(texture,NULL,NULL,&rectangle.w,&rectangle.h)!=0){
        SDL_DestroyRenderer(rendu);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger la texture");
    }
    if(SDL_RenderCopy(rendu,texture,NULL,&rectangle)!=0){
        SDL_DestroyRenderer(rendu);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }
   /*   
    if(SDL_RenderDrawPoint(rendu,100,450)!= 0)
        SDL_ExitWithError("Impossible de dessiner un point");
    
    

    if(SDL_RenderFillRect(rendu,&rectangle)!= 0)
        SDL_ExitWithError("Impossible de dessiner un rectangle");
   */

    SDL_RenderPresent(rendu);
    while(program)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    program=SDL_FALSE;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    printf("Click on %d / %d\n", event.motion.x,event.motion.y);
                    break;
               /* case SDL_MOUSEBUTTONUP:
                    if(event.motion.x>imagew)
                */default:
                    break;
            }
        }

    }

    /*------------------------------------------------------------*/
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}

void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}