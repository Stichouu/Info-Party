#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

#define Fenetre_width 1280
#define Fenetre_height 720
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
int main(int argc, char *argv[])
{
    Uint32 affiche_fenetre=0;
    int fenetre_w,fenetre_h;
    SDL_Window *window = NULL;
    SDL_Renderer *rendu= NULL;
    SDL_Surface *image=NULL;
    SDL_Texture *texture=NULL;
    SDL_Rect rectangle={0,0,Fenetre_width,Fenetre_height};
    SDL_Rect nb_joueur={ 850,100,400,100};
    SDL_Rect nb_tour={ 850,201,400,100 };
    SDL_bool program =SDL_TRUE;
    int une_seule=0;

    //Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("Initialisation SDL");
    //Création fenêtre et rendu
    if(SDL_CreateWindowAndRenderer(Fenetre_width,Fenetre_height,affiche_fenetre,&window,&rendu) != 0)
        SDL_ExitWithError("Impossible de creer la fenetre et le rendu");
    image= IMG_Load("src/lac_en_montagne.bmp");
    SDL_AfficherUneImage(rendu,image,texture,rectangle);
    image = IMG_Load("src/case_chiffrer.png");
    SDL_AfficherUneImage(rendu,image,texture,nb_joueur);
    image = IMG_Load("src/nb_joueur.png");
    SDL_AfficherUneImage(rendu,image,texture,nb_tour);
    while(program){
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch(event.type)
            {
                case SDL_QUIT:
                    program=SDL_FALSE;
                    break;
                case SDL_MOUSEBUTTONUP:
                    printf("%i : %i \n",event.button.x,event.button.y);
                    if(une_seule!=2 && (event.button.x>850 && event.button.x<850+125) && (event.button.y>201 && event.button.y<201+100)){
                        image = IMG_Load("src/nb_joueur.png");
                        SDL_AfficherUneImage(rendu,image,texture,nb_tour);
                        image = IMG_Load("src/nb_2_entourer.png");
                        SDL_AfficherUneImage(rendu,image,texture,nb_tour);
                        une_seule=2;
                    }
                    if(une_seule!=3 && (event.button.x>850+125 && event.button.x<850+125+125) && (event.button.y>201 && event.button.y<201+100)){
                        image = IMG_Load("src/nb_joueur.png");
                        SDL_AfficherUneImage(rendu,image,texture,nb_tour);
                        image = IMG_Load("src/nb_joueur.png");
                        SDL_AfficherUneImage(rendu,image,texture,nb_tour);
                        une_seule=3;
                    }
                    if(une_seule!=4 && (event.button.x>850+125+125 && event.button.x<850+125+125+125) && (event.button.y>201 && event.button.y<201+100)){
                        image = IMG_Load("src/nb_joueur.png");
                        SDL_AfficherUneImage(rendu,image,texture,nb_tour);
                        image = IMG_Load("src/nb_joueur.png");
                        SDL_AfficherUneImage(rendu,image,texture,nb_tour);
                        une_seule=4;
                    }
                    
                    break;
                default:
                    break;
            }
        }
    }   
    
    clean_ressources(window,rendu,texture);
    SDL_Quit();
    return EXIT_SUCCESS;
}

//gcc src/creer_partie.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image