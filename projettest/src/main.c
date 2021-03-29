#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#define Fenetre_width 1280
#define Fenetre_height 720

// gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
// bin\prog.exe




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


int main(int argc, char ** argv)
{
    SDL_Window *window =NULL;
    SDL_Renderer *rendu=NULL;
    SDL_Surface *picture = NULL;
    SDL_Texture *texture= NULL;
    int i=0;
    SDL_Rect rectangle={0,0,Fenetre_width,Fenetre_height};


    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
      SDL_ExitWithError("Initialisation SDL");
    }

    if(SDL_CreateWindowAndRenderer(Fenetre_width,Fenetre_height,0,&window,&rendu) != 0)
        SDL_ExitWithError("Impossible de creer la fenetre et le rendu");


    picture = IMG_Load("src/arbre.jpg");
    SDL_AfficherUneImage( rendu, picture, texture, rectangle);
    picture = IMG_Load("src/creer_une_partie.png");
    SDL_Rect rectangle1={0,0,0,0};
      SDL_AfficherUneImage( rendu, picture, texture, rectangle1);
    picture = IMG_Load("src/rejoindre_une_partie.png");
    SDL_Rect rectangle2={0,100,0,0};
      SDL_AfficherUneImage( rendu, picture, texture, rectangle2);
    picture = IMG_Load("src/options.png");
      SDL_Rect rectangle3={0,200,0,0};
        SDL_AfficherUneImage( rendu, picture, texture, rectangle3);
    picture = IMG_Load("src/quitter_le_jeu.png");
    SDL_Rect rectangle4={0,300,0,0};
    SDL_AfficherUneImage( rendu, picture, texture, rectangle4);



    SDL_bool program_launched = SDL_TRUE;
    while(program_launched)
    {
      SDL_Event event;
      while(SDL_PollEvent(&event))
      {
        switch(event.type)
        {

          case SDL_QUIT:
          program_launched=SDL_FALSE;
          break;

          case SDL_MOUSEBUTTONUP:
            //if( event.button.button == SDL_BUTTON_LEFT){                               //si le bouton de gauche est appuyé
            printf("clic gauche sur %d/%d",event.button.x,event.button.y);

              if((event.button.x > 00 && event.button.x < 100) && (event.button.y > 0 && event.button.y < 480 )){ // endroit ou il y aura le bouton pour lancer le jeu

                  /* programme pour créer une partie */

            }
            if((event.button.x > 100 && event.button.x < 200) && (event.button.y > 0 && event.button.y < 480 )){ // endroit ou il y aura le bouton pour rejoindre le jeu
                /* programme pour rejoindre une parties */
              }
              if((event.button.x > 200 && event.button.x < 300) && (event.button.y > 0 && event.button.y < 480 )){ // endroit ou il y aura le bouton pour rejoindre le jeu
                  /* programme pour les options */

                  }
                if((event.button.x > 0 && event.button.x < 400) && (event.button.y > 0 && event.button.y < 480 )){  // endroit ou il y aura le bouton pour quitter le jeu
                  program_launched = SDL_FALSE;

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
