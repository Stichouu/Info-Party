#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "../lib/petite_fonction.h"
void creation_partie(SDL_Window *fenetre,int * joueur, int * tour)
{
    SDL_Renderer *rendu= NULL;
    SDL_Surface *image=NULL;
    SDL_Texture *texture=NULL;
    SDL_Texture *imagefond=NULL;
    SDL_bool program =SDL_TRUE;
    int acceder_menu=0;
    //Création du rendu
    rendu=SDL_CreateRenderer(fenetre,-1,0);
    if(rendu == NULL)
    {
      SDL_ExitWithError("Le rendu n'a pas pu être créé");
    }
    //Création des rectangles 
    SDL_Rect fond={0,0,Fenetre_width,Fenetre_height};
    SDL_Rect quitter={25,25,200,100};
    SDL_Rect banderole={850,0,400,100};
    SDL_Rect nb_tour={850,101,400,100};
    SDL_Rect nb_tour_chiffre={850,202,400,100};
    SDL_Rect nb_joueur={850,303,400,100};
    SDL_Rect nb_joueur_chiffre={850,404,400,100};
    SDL_Rect creer_la_partie={850,505,400,215};
	//Création images et affichage
	image= IMG_Load("src/img/lac_en_montagne.bmp");
    SDL_AfficherUneImage(rendu,image,imagefond,fond);
    image = IMG_Load("src/img/banderole_creation_partie.png");
    SDL_AfficherUneImage(rendu,image,texture,banderole);
    image = IMG_Load("src/img/nb_tour.png");
    SDL_AfficherUneImage(rendu,image,texture,nb_tour);
    image = IMG_Load("src/img/nb_tour_chiffre_4.png");
    SDL_AfficherUneImage(rendu,image,texture,nb_tour_chiffre);
    image = IMG_Load("src/img/nb_joueur.png");
    SDL_AfficherUneImage(rendu,image,texture,nb_joueur);
    image = IMG_Load("src/img/nb_joueur_chiffre_2.png");
    SDL_AfficherUneImage(rendu,image,texture,nb_joueur_chiffre);
	image = IMG_Load("src/img/quitter.png");
    SDL_AfficherUneImage(rendu,image,texture,quitter);
    image = IMG_Load("src/img/creation_partie.png");
    SDL_AfficherUneImage(rendu,image,texture,creer_la_partie);

    //les events
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
                    if((*tour)!=4 && (event.button.x>850 && event.button.x<850+100) && (event.button.y>202 && event.button.y<202+100)){
                        image = IMG_Load("src/img/nb_tour_chiffre_4.png");
                        SDL_AfficherUneImage(rendu,image,texture,nb_tour_chiffre);
                        (*tour)=4;
                    }
                    if((*tour)!=5 && (event.button.x>850+100 && event.button.x<850+200) && (event.button.y>202 && event.button.y<202+100)){
                        image = IMG_Load("src/img/nb_tour_chiffre_5.png");
                        SDL_AfficherUneImage(rendu,image,texture,nb_tour_chiffre);
                        (*tour)=5;
                    }
                    if((*tour)!=6 && (event.button.x>850+200 && event.button.x<850+300) && (event.button.y>202 && event.button.y<202+100)){
                        image = IMG_Load("src/img/nb_tour_chiffre_6.png");
                        SDL_AfficherUneImage(rendu,image,texture,nb_tour_chiffre);
                        (*tour)=6;
                    }
                    if((*tour)!=7 && (event.button.x>850+300 && event.button.x<850+400) && (event.button.y>202 && event.button.y<202+100)){
                        image = IMG_Load("src/img/nb_tour_chiffre_7.png");
                        SDL_AfficherUneImage(rendu,image,texture,nb_tour_chiffre);
                        (*tour)=7;
                    }
                    if((*joueur)!=2 && (event.button.x>850 && event.button.x<850+133) && (event.button.y>404 && event.button.y<404+100)){
                        image = IMG_Load("src/img/nb_joueur_chiffre_2.png");
                        SDL_AfficherUneImage(rendu,image,texture,nb_joueur_chiffre);
                        (*joueur)=2;
                    }
                    if((*joueur)!=3 && (event.button.x>850+133 && event.button.x<850+133+133) && (event.button.y>404 && event.button.y<404+100)){
                        image = IMG_Load("src/img/nb_joueur_chiffre_3.png");
                        SDL_AfficherUneImage(rendu,image,texture,nb_joueur_chiffre);
                        (*joueur)=3;
                    }
                    if((*joueur)!=4 && (event.button.x>850+133+133 && event.button.x<850+133+133+134) && (event.button.y>404 && event.button.y<404+100)){
                        image = IMG_Load("src/img/nb_joueur_chiffre_4.png");
                        SDL_AfficherUneImage(rendu,image,texture,nb_joueur_chiffre);
                        (*joueur)=4;
                    }
                    if((event.button.x>25 && event.button.x<25+200) && (event.button.y>25 && event.button.y<25+100)){
                    	acceder_menu=1;
                    	program=SDL_FALSE;
                    }
                    if((event.button.x>850 && event.button.x<850+400) && (event.button.y>505 && event.button.y<720)){
                        program=SDL_FALSE;
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
    if(acceder_menu==1)
        menu(fenetre,joueur,tour);
}

//gcc src/creer_partie.c src/petite_fonction.c src/test/test_creer_partie.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image