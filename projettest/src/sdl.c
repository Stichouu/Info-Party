#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

//gcc sdl.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows

void SDL_ExitWithError(const char *message)
{
SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
SDL_Quit();
exit(EXIT_FAILURE);
}

void clean_ressources(SDL_Window *w, SDL_Renderer *r, SDL_Texture **t, int cpt){
  int i;
  if(t != NULL){
    for(i=0; i<cpt; i++){
      SDL_DestroyTexture(t[i]);
    }
  }
  if(r != NULL){
    SDL_DestroyRenderer(r);
  }
  if(w != NULL){
    SDL_DestroyWindow(w);
  }
}

void SDL_AfficherFond(SDL_Renderer *rendu,SDL_Surface *image,SDL_Texture *texture,SDL_Rect rectangle, SDL_Texture **t, int cpt){
  printf("blop0\n");
    if(image ==NULL){
        clean_ressources(NULL,NULL,t,cpt);
        SDL_ExitWithError("Impossible de charger l'image");
    }
    printf("blop1\n");
    texture= SDL_CreateTextureFromSurface(rendu,image);
    t[cpt]=texture;

    SDL_FreeSurface(image);
     if(texture ==NULL){
        clean_ressources(NULL,NULL,t,cpt);
        SDL_ExitWithError("Impossible de creer la texture");
    }

    printf("blop2\n");

    if(SDL_RenderCopy(rendu,texture,NULL,&rectangle)!=0){
        clean_ressources(NULL,NULL,t,cpt);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }
    SDL_RenderPresent(rendu);

    printf("blop3\n");
}

void SDL_AfficherUneImage(SDL_Renderer *rendu,SDL_Surface *image,SDL_Texture *texture,SDL_Rect rectangle, SDL_Texture **t, int cpt){
    if(image ==NULL){
        clean_ressources(NULL,NULL,t,cpt);
        SDL_ExitWithError("Impossible de charger l'image");
    }
    texture= SDL_CreateTextureFromSurface(rendu,image);
    t[cpt]=texture;

    SDL_FreeSurface(image);
     if(texture ==NULL){
        clean_ressources(NULL,NULL,t,cpt);
        SDL_ExitWithError("Impossible de creer la texture");
    }

    if(SDL_QueryTexture(texture,NULL,NULL,&rectangle.w,&rectangle.h)!=0){
        clean_ressources(NULL,NULL,t,cpt);
        SDL_ExitWithError("Impossible de charger la texture");
    }

    if(SDL_RenderCopy(rendu,texture,NULL,&rectangle)!=0){
        clean_ressources(NULL,NULL,t,cpt);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }
    SDL_RenderPresent(rendu);
}

int main(int argc, char **argv){

  //variables
  Uint32 affich_fenetre = SDL_WINDOW_MAXIMIZED;
  int fenetre_w;
  int fenetre_h;
  SDL_Window *fenetre = NULL;
  SDL_Renderer *rendu = NULL;
  SDL_Texture * texture = NULL;
  SDL_Texture * option = NULL;
  SDL_Texture * tab_text[500];
  int cpt_text = 0;
  SDL_Surface *image = NULL;

  printf("Donald\n");
  //initialisation SDL
  if(SDL_Init(SDL_INIT_VIDEO) != 0){
    SDL_ExitWithError("Initialisation SDL");
  }

  printf("riri\n");

//  SDL_CreateWindowAndRenderer(1280, 720, 0, &fenetre, &rendu);


  //Creation de la fenetre
  fenetre = SDL_CreateWindow("Info-Party",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, affich_fenetre);
  if(fenetre==NULL)
  {
    clean_ressources(NULL,NULL,tab_text,cpt_text);
    SDL_ExitWithError("Creation fenetre");
  }

  //Prendre les coordonné de la fenetre de l'utilisateur
  printf("fifi\n");
   SDL_GetWindowSize(fenetre, &fenetre_w, &fenetre_h);

  //Creation du rendu
  rendu = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_SOFTWARE);
  if(rendu==NULL){
    clean_ressources(fenetre,NULL,tab_text,cpt_text);
    SDL_ExitWithError("Creation rendu");
  }

printf("loulou\n");

  //Creation de l'image fond
  SDL_Rect fond;
  fond.w = fenetre_w;
  fond.h = fenetre_h;
  image = IMG_Load("img/fond_blanc.jpg");
  SDL_AfficherFond(rendu, image, texture, fond, tab_text, cpt_text);
  cpt_text++;

  printf("coucou\n");
  SDL_Rect bloc_option;
  bloc_option.w = 500;
  bloc_option.h = 500;

// SDL_AfficherUneImage(rendu,image,option, bloc_option, tab_text, cpt_text);
  cpt_text++;

  printf("coucou2\n");



  SDL_Delay(3000);
  /* ------ */

  clean_ressources(fenetre,rendu,tab_text,cpt_text);
  SDL_Quit();

  return(0);
}
