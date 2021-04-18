#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "../lib/petite_fonction.h"
void creation_partie(SDL_Window *fenetre,int * joueur, int * tour,int * quitter)
{
    SDL_Renderer *rendu= NULL;
    SDL_Surface *image=NULL;
    SDL_Surface *chiffre_contour=NULL;
    SDL_Texture *texture=NULL;
    SDL_Texture *imagefond=NULL;
    SDL_Texture *contour=NULL;
    SDL_bool program =SDL_TRUE;
    int acceder_menu=0;
    //Création du rendu
    rendu=SDL_CreateRenderer(fenetre,-1,0);
    if(rendu == NULL)
    {
      SDL_ExitWithError("Le rendu n'a pas pu être créé");
    }
    //Création des rectangles
    int x= Fenetre_width;
      int y=Fenetre_height;

      SDL_Rect fond={0,0,x,y};
      SDL_Rect retour={0,0,x/8,y/8};
      SDL_Rect banderole={x-(x/4),(y/10)*0,(x/4),y/10};
      SDL_Rect nb_tour={x-(x/4),(y/10)*1,(x/4),y/10};
      SDL_Rect nb_tour_chiffre={x-(x/4),(y/10)*2,(x/4),y/10};
      SDL_Rect nb_joueur={x-(x/4),(y/10)*3,(x/4),y/10};
      SDL_Rect nb_joueur_chiffre={x-(x/4),(y/10)*4,(x/4),y/10};
      SDL_Rect creer_la_partie={x-(x/4),(y/10)*5,(x/4),y-(y/10)*5};

      SDL_Rect nb_joueur2={(x/12)*9,(y/10)*4,x-(x/12)*11,y/10};
      SDL_Rect nb_joueur3={(x/12)*10,(y/10)*4,x-(x/12)*11,y/10};
      SDL_Rect nb_joueur4={(x/12)*11,(y/10)*4,x-(x/12)*11,y/10};

      SDL_Rect nb_tour4={(x/16)*12,(y/10)*2,x-(x/16)*15,y/10};
      SDL_Rect nb_tour5={(x/16)*13,(y/10)*2,x-(x/16)*15,y/10};
      SDL_Rect nb_tour6={(x/16)*14,(y/10)*2,x-(x/16)*15,y/10};
      SDL_Rect nb_tour7={(x/16)*15,(y/10)*2,x-(x/16)*15,y/10};

    //Création images et affichage
    image= IMG_Load("src/img/lac_en_montagne.bmp");
    SDL_AfficherUneImage(rendu,image,imagefond,fond);

    // création banderole
    image = IMG_Load("src/img/creer_une_partie.png");
    SDL_AfficherUneImage(rendu,image,texture,banderole);

    // création case nb tours
    image = IMG_Load("src/img/nombre_tour.png");
    SDL_AfficherUneImage(rendu,image,texture,nb_tour);
    image = IMG_Load("src/img/bloc_fond.png");
    SDL_AfficherUneImage(rendu,image,texture,nb_tour_chiffre);
    image = IMG_Load("src/img/4 pixel art.png");
    SDL_AfficherUneImage(rendu,image,texture,nb_tour4);
    image = IMG_Load("src/img/5 pixel art.png");
    SDL_AfficherUneImage(rendu,image,texture,nb_tour5);
    image = IMG_Load("src/img/6 pixel art.png");
    SDL_AfficherUneImage(rendu,image,texture,nb_tour6);
    image = IMG_Load("src/img/7 pixel art.png");
    SDL_AfficherUneImage(rendu,image,texture,nb_tour7);


    // création case nb joueur
    image = IMG_Load("src/img/nombre_joueur.png");
    SDL_AfficherUneImage(rendu,image,texture,nb_joueur);
    image = IMG_Load("src/img/bloc_fond.png");
    SDL_AfficherUneImage(rendu,image,texture,nb_joueur_chiffre);
    image = IMG_Load("src/img/2 pixel art.png");
    SDL_AfficherUneImage(rendu,image,texture,nb_joueur2);
    image = IMG_Load("src/img/3 pixel art.png");
    SDL_AfficherUneImage(rendu,image,texture,nb_joueur3);
    image = IMG_Load("src/img/4 pixel art.png");
    SDL_AfficherUneImage(rendu,image,texture,nb_joueur4);

    // création la case quitter
    image = IMG_Load("src/img/retour.png");
    SDL_AfficherUneImage(rendu,image,texture,retour);

    // création la case creer_partie
    image = IMG_Load("src/img/valider.png");
    SDL_AfficherUneImage(rendu,image,texture,creer_la_partie);

    // création du contour d'un chiffre
    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_tour4);
    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_joueur4);
 

    //les events
    while(program){
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch(event.type)
            {
                case SDL_QUIT:
                    program=SDL_FALSE;
                    (*quitter)=1;
                    break;
                case SDL_MOUSEBUTTONUP:
                    if( event.button.button == SDL_BUTTON_LEFT){
                        if((*tour)!=4 && (event.button.x>(x/16)*12 && event.button.x<(x/16)*13) && (event.button.y>(y/10)*2 && event.button.y<(y/10)*3)){
                            clean_ressources(NULL,NULL,imagefond);
                            clean_ressources(NULL,NULL,contour);                            
                            (*tour)=4;
                            image= IMG_Load("src/img/lac_en_montagne.bmp");
                            SDL_AfficherUneImage(rendu,image,imagefond,fond);
                            image = IMG_Load("src/img/creer_une_partie.png");
                            SDL_AfficherUneImage(rendu,image,texture,banderole);
                            image = IMG_Load("src/img/nombre_tour.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour);
                            image = IMG_Load("src/img/bloc_fond.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour_chiffre);
                            image = IMG_Load("src/img/4 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour4);
                            image = IMG_Load("src/img/5 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour5);
                            image = IMG_Load("src/img/6 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour6);
                            image = IMG_Load("src/img/7 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour7);
                            image = IMG_Load("src/img/nombre_joueur.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur);
                            image = IMG_Load("src/img/bloc_fond.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur_chiffre);
                            image = IMG_Load("src/img/2 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur2);
                            image = IMG_Load("src/img/3 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur3);
                            image = IMG_Load("src/img/4 pixel art.png");
                             SDL_AfficherUneImage(rendu,image,texture,nb_joueur4);
                            image = IMG_Load("src/img/retour.png");
                            SDL_AfficherUneImage(rendu,image,texture,retour);
                            image = IMG_Load("src/img/valider.png");
                            SDL_AfficherUneImage(rendu,image,texture,creer_la_partie);
                            chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                            SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_tour4);
                            switch((*joueur))
                            {
                                case 2:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_joueur2);
                                    break;


                                case 3:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_joueur3);
                                    break;

                                case 4:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_joueur4);
                                    break;

                            }
                        }
                        if((*tour)!=5 && (event.button.x>(x/16)*13 && event.button.x<(x/16)*14) && (event.button.y>(y/10)*2 && event.button.y<(y/10)*3)){
                            clean_ressources(NULL,NULL,imagefond);
                            clean_ressources(NULL,NULL,contour);  
                            (*tour)=5;
                            image= IMG_Load("src/img/lac_en_montagne.bmp");
                            SDL_AfficherUneImage(rendu,image,imagefond,fond);
                            image = IMG_Load("src/img/creer_une_partie.png");
                            SDL_AfficherUneImage(rendu,image,texture,banderole);
                            image = IMG_Load("src/img/nombre_tour.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour);
                            image = IMG_Load("src/img/bloc_fond.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour_chiffre);
                            image = IMG_Load("src/img/4 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour4);
                            image = IMG_Load("src/img/5 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour5);
                            image = IMG_Load("src/img/6 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour6);
                            image = IMG_Load("src/img/7 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour7);
                            image = IMG_Load("src/img/nombre_joueur.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur);
                            image = IMG_Load("src/img/bloc_fond.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur_chiffre);
                            image = IMG_Load("src/img/2 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur2);
                            image = IMG_Load("src/img/3 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur3);
                            image = IMG_Load("src/img/4 pixel art.png");
                             SDL_AfficherUneImage(rendu,image,texture,nb_joueur4);
                            image = IMG_Load("src/img/retour.png");
                            SDL_AfficherUneImage(rendu,image,texture,retour);
                            image = IMG_Load("src/img/valider.png");
                            SDL_AfficherUneImage(rendu,image,texture,creer_la_partie);
                            chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                            SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_tour5);
                            switch((*joueur))
                            {
                                case 2:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_joueur2);
                                    break;


                                case 3:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_joueur3);
                                    break;

                                case 4:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_joueur4);
                                    break;

                            }
                        }
                        if((*tour)!=6 && (event.button.x>(x/16)*14 && event.button.x<(x/16)*15) && (event.button.y>(y/10)*2 && event.button.y<(y/10)*3)){
                            clean_ressources(NULL,NULL,imagefond);
                            clean_ressources(NULL,NULL,contour);  
                            (*tour)=6;
                            image= IMG_Load("src/img/lac_en_montagne.bmp");
                            SDL_AfficherUneImage(rendu,image,imagefond,fond);
                            image = IMG_Load("src/img/creer_une_partie.png");
                            SDL_AfficherUneImage(rendu,image,texture,banderole);
                            image = IMG_Load("src/img/nombre_tour.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour);
                            image = IMG_Load("src/img/bloc_fond.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour_chiffre);
                            image = IMG_Load("src/img/4 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour4);
                            image = IMG_Load("src/img/5 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour5);
                            image = IMG_Load("src/img/6 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour6);
                            image = IMG_Load("src/img/7 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour7);
                            image = IMG_Load("src/img/nombre_joueur.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur);
                            image = IMG_Load("src/img/bloc_fond.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur_chiffre);
                            image = IMG_Load("src/img/2 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur2);
                            image = IMG_Load("src/img/3 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur3);
                            image = IMG_Load("src/img/4 pixel art.png");
                             SDL_AfficherUneImage(rendu,image,texture,nb_joueur4);
                            image = IMG_Load("src/img/retour.png");
                            SDL_AfficherUneImage(rendu,image,texture,retour);
                            image = IMG_Load("src/img/valider.png");
                            SDL_AfficherUneImage(rendu,image,texture,creer_la_partie);
                            chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                            SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_tour6);
                            switch((*joueur))
                            {
                                case 2:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_joueur2);
                                    break;


                                case 3:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_joueur3);
                                    break;

                                case 4:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_joueur4);
                                    break;

                            }
                        }
                        if((*tour)!=7 && (event.button.x>(x/16)*15 && event.button.x<x) && (event.button.y>(y/10)*2 && event.button.y<(y/10)*3)){
                            clean_ressources(NULL,NULL,imagefond);
                            clean_ressources(NULL,NULL,contour);  
                            (*tour)=7;
                            image= IMG_Load("src/img/lac_en_montagne.bmp");
                            SDL_AfficherUneImage(rendu,image,imagefond,fond);
                            image = IMG_Load("src/img/creer_une_partie.png");
                            SDL_AfficherUneImage(rendu,image,texture,banderole);
                            image = IMG_Load("src/img/nombre_tour.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour);
                            image = IMG_Load("src/img/bloc_fond.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour_chiffre);
                            image = IMG_Load("src/img/4 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour4);
                            image = IMG_Load("src/img/5 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour5);
                            image = IMG_Load("src/img/6 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour6);
                            image = IMG_Load("src/img/7 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour7);
                            image = IMG_Load("src/img/nombre_joueur.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur);
                            image = IMG_Load("src/img/bloc_fond.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur_chiffre);
                            image = IMG_Load("src/img/2 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur2);
                            image = IMG_Load("src/img/3 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur3);
                            image = IMG_Load("src/img/4 pixel art.png");
                             SDL_AfficherUneImage(rendu,image,texture,nb_joueur4);
                            image = IMG_Load("src/img/retour.png");
                            SDL_AfficherUneImage(rendu,image,texture,retour);
                            image = IMG_Load("src/img/valider.png");
                            SDL_AfficherUneImage(rendu,image,texture,creer_la_partie);
                            chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                            SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_tour7);
                            switch((*joueur))
                            {
                                case 2:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_joueur2);
                                    break;


                                case 3:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_joueur3);
                                    break;

                                case 4:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_joueur4);
                                    break;

                            }
                        }
                        if((*joueur)!=2 && (event.button.x>(x/12)*9 && event.button.x<(x/12)*10) && (event.button.y>(y/10)*4 && event.button.y<(y/10)*5)){
                            clean_ressources(NULL,NULL,imagefond);
                            clean_ressources(NULL,NULL,contour);  
                            (*joueur)=2;
                            image= IMG_Load("src/img/lac_en_montagne.bmp");
                            SDL_AfficherUneImage(rendu,image,imagefond,fond);
                            image = IMG_Load("src/img/creer_une_partie.png");
                            SDL_AfficherUneImage(rendu,image,texture,banderole);
                            image = IMG_Load("src/img/nombre_tour.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour);
                            image = IMG_Load("src/img/bloc_fond.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour_chiffre);
                            image = IMG_Load("src/img/4 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour4);
                            image = IMG_Load("src/img/5 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour5);
                            image = IMG_Load("src/img/6 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour6);
                            image = IMG_Load("src/img/7 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour7);
                            image = IMG_Load("src/img/nombre_joueur.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur);
                            image = IMG_Load("src/img/bloc_fond.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur_chiffre);
                            image = IMG_Load("src/img/2 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur2);
                            image = IMG_Load("src/img/3 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur3);
                            image = IMG_Load("src/img/4 pixel art.png");
                             SDL_AfficherUneImage(rendu,image,texture,nb_joueur4);
                            image = IMG_Load("src/img/retour.png");
                            SDL_AfficherUneImage(rendu,image,texture,retour);
                            image = IMG_Load("src/img/valider.png");
                            SDL_AfficherUneImage(rendu,image,texture,creer_la_partie);
                            image = IMG_Load("src/img/bloc_chiffre_contour.png");
                            SDL_AfficherUneImage(rendu,image,contour,nb_joueur2);
                            switch((*tour))
                            {
                                case 4:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_tour4);
                                    break;


                                case 5:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_tour5);
                                    break;

                                case 6:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_tour6);
                                    break;

                                case 7:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_tour7);
                                    break;
                            }

                        }
                        if((*joueur)!=3 && (event.button.x>(x/12)*10 && event.button.x<(x/12)*11) && (event.button.y>(y/10)*4 && event.button.y<(y/10)*5)){
                            clean_ressources(NULL,NULL,imagefond);
                            clean_ressources(NULL,NULL,contour);  
                            (*joueur)=3;
                            image= IMG_Load("src/img/lac_en_montagne.bmp");
                            SDL_AfficherUneImage(rendu,image,imagefond,fond);
                            image = IMG_Load("src/img/creer_une_partie.png");
                            SDL_AfficherUneImage(rendu,image,texture,banderole);
                            image = IMG_Load("src/img/nombre_tour.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour);
                            image = IMG_Load("src/img/bloc_fond.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour_chiffre);
                            image = IMG_Load("src/img/4 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour4);
                            image = IMG_Load("src/img/5 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour5);
                            image = IMG_Load("src/img/6 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour6);
                            image = IMG_Load("src/img/7 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour7);
                            image = IMG_Load("src/img/nombre_joueur.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur);
                            image = IMG_Load("src/img/bloc_fond.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur_chiffre);
                            image = IMG_Load("src/img/2 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur2);
                            image = IMG_Load("src/img/3 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur3);
                            image = IMG_Load("src/img/4 pixel art.png");
                             SDL_AfficherUneImage(rendu,image,texture,nb_joueur4);
                            image = IMG_Load("src/img/retour.png");
                            SDL_AfficherUneImage(rendu,image,texture,retour);
                            image = IMG_Load("src/img/valider.png");
                            SDL_AfficherUneImage(rendu,image,texture,creer_la_partie);
                            image = IMG_Load("src/img/bloc_chiffre_contour.png");
                            SDL_AfficherUneImage(rendu,image,contour,nb_joueur3);
                            switch((*tour))
                            {
                                case 4:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_tour4);
                                    break;


                                case 5:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_tour5);
                                    break;

                                case 6:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_tour6);
                                    break;

                                case 7:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_tour7);
                                    break;
                            }



                        }
                        if((*joueur)!=4 && (event.button.x>(x/12)*11 && event.button.x<x) && (event.button.y>(y/10)*4 && event.button.y<(y/10)*5)){
                            clean_ressources(NULL,NULL,imagefond);
                            clean_ressources(NULL,NULL,contour);  
                            (*joueur)=4;
                            image= IMG_Load("src/img/lac_en_montagne.bmp");
                            SDL_AfficherUneImage(rendu,image,imagefond,fond);
                            image = IMG_Load("src/img/creer_une_partie.png");
                            SDL_AfficherUneImage(rendu,image,texture,banderole);
                            image = IMG_Load("src/img/nombre_tour.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour);
                            image = IMG_Load("src/img/bloc_fond.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour_chiffre);
                            image = IMG_Load("src/img/4 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour4);
                            image = IMG_Load("src/img/5 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour5);
                            image = IMG_Load("src/img/6 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour6);
                            image = IMG_Load("src/img/7 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_tour7);
                            image = IMG_Load("src/img/nombre_joueur.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur);
                            image = IMG_Load("src/img/bloc_fond.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur_chiffre);
                            image = IMG_Load("src/img/2 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur2);
                            image = IMG_Load("src/img/3 pixel art.png");
                            SDL_AfficherUneImage(rendu,image,texture,nb_joueur3);
                            image = IMG_Load("src/img/4 pixel art.png");
                             SDL_AfficherUneImage(rendu,image,texture,nb_joueur4);
                            image = IMG_Load("src/img/retour.png");
                            SDL_AfficherUneImage(rendu,image,texture,retour);
                            image = IMG_Load("src/img/valider.png");
                            SDL_AfficherUneImage(rendu,image,texture,creer_la_partie);
                            image = IMG_Load("src/img/bloc_chiffre_contour.png");
                            SDL_AfficherUneImage(rendu,image,contour,nb_joueur4);
                            switch((*tour))
                            {
                                case 4:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_tour4);
                                    break;


                                case 5:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_tour5);
                                    break;

                                case 6:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_tour6);
                                    break;

                                case 7:
                                    chiffre_contour =IMG_Load("src/img/bloc_chiffre_contour.png");
                                    SDL_AfficherUneImage(rendu,chiffre_contour,contour,nb_tour7);
                                    break;
                            }

                        }
                        if((event.button.x>0 && event.button.x<x/8) && (event.button.y>0 && event.button.y<y/8)){
                           acceder_menu=1;
                           program=SDL_FALSE;
                       }
                        if((event.button.x>x-(x/4) && event.button.x<x) && (event.button.y>(y/10)*5 && event.button.y<y)){
                            program=SDL_FALSE;
                        }
                    }
                        break;
                    default:
                        break;
            }
        }
    }

    //on nettoie tout sauf la fenetre on la garde.
    clean_ressources(NULL,rendu,texture);
    clean_ressources(NULL,NULL,imagefond);
    clean_ressources(NULL,NULL,contour);
    if(acceder_menu==1)
        menu(fenetre,joueur,tour,quitter);
}