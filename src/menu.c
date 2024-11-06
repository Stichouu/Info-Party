#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include "../lib/petite_fonction.h"
/**
* \file menu.c
* \author Pennachi Cyprien
* \version 1.6
* \brief Le menu de notre jeu
*/

/**
* \fn void menu(SDL_Window *fenetre,int * joueur, int * tour,int * quitter)
* \param fenetre Pointeur sur un objet de type SDL_Window pour garder ma fenêtre.
* \param joueur Pointeur sur un objet de type integer pour changer si besoin sa valeur pour avoir le nombre de joueurs.
* \param tour Pointeur sur un objet de type integer pour changer si besoin sa valeur pour avoir le nombre de tours.
* \param quitter Pointeur sur un objet de type integer pour changer si besoin sa valeur afin de savoir si on quitte le programme.
* \brief la fonction permettant d'afficher notre menu en conservant la fenêtre et permettant d'accéder à la création d'une partie,de rejoindre une partie,des options
ou à quitter le jeu en cliquant sur la case dédiée.
*/
void menu(SDL_Window *fenetre,int * joueur, int * tour,int * quitter)
{
    SDL_Renderer *rendu=NULL;
    SDL_Surface *picture = NULL;
    SDL_Texture *texture= NULL;
    int acces=0;
    rendu=SDL_CreateRenderer(fenetre,-1,0);
    if(rendu == NULL)
    {
      SDL_ExitWithError("Le rendu n'a pas pu être créé");
    }
    SDL_Rect rectangle={0,0,Fenetre_width,Fenetre_height};
    picture = IMG_Load("src/img/lac_en_montagne.bmp");
    SDL_AfficherUneImage( rendu, picture, texture, rectangle);

    picture = IMG_Load("src/img/creer_une_partie.png");
    SDL_Rect rectangle1={0,Fenetre_height/8,Fenetre_width/4,Fenetre_height/6};
    SDL_AfficherUneImage( rendu, picture, texture, rectangle1);
    
    picture = IMG_Load("src/img/rejoindre_une_partie.png");
    SDL_Rect rectangle2={0,Fenetre_height/3,Fenetre_width/4,Fenetre_height/6};
    SDL_AfficherUneImage( rendu, picture, texture, rectangle2);
    
    picture = IMG_Load("src/img/options.png");
    SDL_Rect rectangle3={0,Fenetre_height/1.85,Fenetre_width/4,Fenetre_height/6};
    SDL_AfficherUneImage( rendu, picture, texture, rectangle3);
    
    picture = IMG_Load("src/img/quitter_le_jeu.png");
    SDL_Rect rectangle4={0,Fenetre_height/1.325,Fenetre_width/4,Fenetre_height/6};
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
              if((event.button.x > 0 && event.button.x < Fenetre_width/4) && (event.button.y > Fenetre_height/8 && event.button.y < (Fenetre_height/8)+Fenetre_height/6)){ // endroit ou il y aura le bouton pour creer le jeu
                 acces=1;
                 program_launched = SDL_FALSE;
              }
              if((event.button.x > 0 && event.button.x < Fenetre_width/4) && (event.button.y > Fenetre_height/3 && event.button.y < (Fenetre_height/3)+Fenetre_height/6 )){ // endroit ou il y aura le bouton pour rejoindre le jeu
                acces=2;             
              }
              if((event.button.x > 0 && event.button.x < Fenetre_width/4) && (event.button.y > Fenetre_height/1.85 && event.button.y < (Fenetre_height/1.85)+Fenetre_height/6 )){ // endroit ou il y aura le bouton option
                acces=3;
              }
              if((event.button.x > 0 && event.button.x < Fenetre_width/4) && (event.button.y > Fenetre_height/1.325 && event.button.y < (Fenetre_height/1.325)+Fenetre_height/6 )){  // endroit ou il y aura le bouton pour quitter le jeu
                program_launched = SDL_FALSE;
                (*quitter)=1;
              }
            }
            break;
          case SDL_QUIT:
             program_launched=SDL_FALSE;
             (*quitter)=1;
             break;  
        }
      }
    }
  clean_ressources(NULL,rendu,texture);
  switch(acces){
      case 1:
        creation_partie(fenetre,joueur,tour,quitter);
      break;
      case 2:
        //rejoindre_partie();
      break;
      case 3:
        //option();
      break;
  }
}
