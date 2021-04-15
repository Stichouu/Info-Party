#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include "../lib/petite_fonction.h"

// gcc src/menu.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
// bin\prog.exe


void menu(SDL_Window *fenetre,int * joueur, int * tour)
{
    SDL_Renderer *rendu=NULL;
    SDL_Surface *picture = NULL;
    SDL_Texture *texture= NULL;
    int acces=0;
    SDL_Rect rectangle={0,0,Fenetre_width,Fenetre_height};
    rendu=SDL_CreateRenderer(fenetre,-1,0);
    if(rendu == NULL)
    {
      SDL_ExitWithError("Le rendu n'a pas pu être créé");
    }
    picture = IMG_Load("src/img/arbre.jpg");
    SDL_AfficherUneImage( rendu, picture, texture, rectangle);
    picture = IMG_Load("src/img/creer_une_partie.png");
    SDL_Rect rectangle1={0,0,100,480};
      SDL_AfficherUneImage( rendu, picture, texture, rectangle1);
    picture = IMG_Load("src/img/rejoindre_une_partie.png");
    SDL_Rect rectangle2={0,100,100,480};
      SDL_AfficherUneImage( rendu, picture, texture, rectangle2);
    picture = IMG_Load("src/img/options.png");
      SDL_Rect rectangle3={0,200,100,480};
        SDL_AfficherUneImage( rendu, picture, texture, rectangle3);
    picture = IMG_Load("src/img/quitter_le_jeu.png");
    SDL_Rect rectangle4={0,300,100,480};
    SDL_AfficherUneImage( rendu, picture, texture, rectangle4);



    SDL_bool program_launched = SDL_TRUE;
    while(program_launched)
    {
      SDL_Event event;
      while(SDL_PollEvent(&event))
      {
        switch(event.type)
        {


          case SDL_MOUSEBUTTONUP:
            if( event.button.button == SDL_BUTTON_LEFT){                               //si le bouton de gauche est appuyé
              if((event.button.x > 00 && event.button.x < 100) && (event.button.y > 0 && event.button.y < 480 )){ // endroit ou il y aura le bouton pour creer le jeu
                 acces=1;
                 program_launched = SDL_FALSE;
              }
              if((event.button.x > 100 && event.button.x < 200) && (event.button.y > 0 && event.button.y < 480 )){ // endroit ou il y aura le bouton pour rejoindre le jeu
                acces=2;
                program_launched = SDL_FALSE;                
              }
              if((event.button.x > 200 && event.button.x < 300) && (event.button.y > 0 && event.button.y < 480 )){ // endroit ou il y aura le bouton option
                acces=3;
                program_launched = SDL_FALSE;
              }
              if((event.button.x > 0 && event.button.x < 400) && (event.button.y > 0 && event.button.y < 480 ))  // endroit ou il y aura le bouton pour quitter le jeu
                program_launched = SDL_FALSE;
            }
            break;
          case SDL_QUIT:
             program_launched=SDL_FALSE;
             break;  
        }
      }
    }
  clean_ressources(NULL,rendu,texture);
  switch(acces){
      case 1:
        creation_partie(fenetre,joueur,tour);
      break;
      case 2:
        //rejoindre_partie();
      break;
      case 3:
        //option();
      break;
  }
}
