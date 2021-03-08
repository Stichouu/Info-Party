#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
/*
    if(SDL_Init(SDL_INIT_EVERYTHING) !=0)quitter(SDL_BASE);
    if( !(IMG_Init(IMG_INIT_PNG)) )quitter(SDL_IMAGE);
    if(TTF_Init() != 0)quitter(SDL_TTF);
    if(!Mix_Init(MIX_INIT_MP3))quitter(SDL_MIXER);
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)quitter(SDL_MIXER); //Initialisation de l'API Mixer
*/
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

int main(int argc, char ** argv)
{
	Uint32 flags = SDL_WINDOW_FULLSCREEN;
    SDL_Window *window =NULL;
    SDL_Renderer *renderer=NULL;
    SDL_Surface *picture = NULL;
    SDL_Texture *texture= NULL;
    SDL_Rect dest_rect = {0,0,640,480}; //rectangle 
    int i=0;

    if(SDL_Init(SDL_INIT_EVERITHING)!=0)
    {
        SDL_Log("ERROR > %s\n", SDL_GetError());
        clean_ressources(NULL,NULL,NULL);
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow("Affichage avec SDL2_image", SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,640,480,flags);
    if(window==NULL)
    {
        SDL_Log("ERROR > %s\n", SDL_GetError());
        clean_ressources(NULL,NULL,NULL);
        exit(EXIT_FAILURE);
    }

    renderer= SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE); //SDL_RENDERER_ACCELERATED

    if(renderer==NULL)
    {
        SDL_Log("ERROR > %s\n", SDL_GetError());
        clean_ressources(window,NULL,NULL);
        exit(EXIT_FAILURE);
    }

    picture = IMG_Load("src/arbre.jpg"); // charger une librairie
 if(picture==NULL)
    {
        SDL_Log("ERROR > %s\n", SDL_GetError());
        clean_ressources(window,renderer,NULL);
        exit(EXIT_FAILURE);
    }

texture = SDL_CreateTextureFromSurface(renderer,picture);
    SDL_FreeSurface(picture);
    if(texture==NULL)
    {
        SDL_Log("ERROR > %s\n", SDL_GetError());
        clean_ressources(window,renderer,NULL);
        exit(EXIT_FAILURE);
    }

	//demande taille texture 

    if(SDL_QueryTexture(texture,NULL,NULL,&dest_rect.w,&dest_rect.h)!=0)
    {
        SDL_Log("ERROR > %s\n", SDL_GetError());
        clean_ressources(window,renderer,texture);
        exit(EXIT_FAILURE);
    }

    if(SDL_RenderCopy(renderer,texture,NULL,&dest_rect)!=0) //if(SDL_RenderCopy(renderer,texture,NULL,NULL)!=0)
    {
        SDL_Log("ERROR > %s\n", SDL_GetError());
        clean_ressources(window,renderer,texture);
        exit(EXIT_FAILURE);
    }
    SDL_RenderPresent(renderer);
        SDL_Delay(5000);
    clean_ressources(window,renderer,texture);
    return EXIT_SUCCESS;
}
