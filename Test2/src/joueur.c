#include <stdio.h>
#include <stdlib.h>
#include "../lib/joueur.h"
#include "../lib/petite_fonction.h"
#include "../lib/partie.h"
#include <SDL.h>
#include <SDL_image.h>

/* Initialisation des joueurs */
void crea_joueurs(){
  int i;
  jou1 = malloc(sizeof(t_joueur));

  jou2 = malloc(sizeof(t_joueur));

  jou3 = malloc(sizeof(t_joueur));

  jou4 = malloc(sizeof(t_joueur));

  en_tete_plat(); // pour placer ec sur la case de départ
  for(i=0; i<NB_JOUEURS; i++){
    switch(i){
      case 0: liste_joueurs[i]=jou1;break;
      case 1: liste_joueurs[i]=jou2; break;
      case 2: liste_joueurs[i]=jou3; break;
      case 3: liste_joueurs[i]=jou4; break;
    }
    liste_joueurs[i]->position=ec; // tous les joueurs commencent sur la case de départ
    liste_joueurs[i]->nb_pieces=10;
    liste_joueurs[i]->nb_badges=0;
    liste_joueurs[i]->num_joueur=i+1;
  }
}

void effet_case(t_joueur * jou){
  // chaque case à un effet mais il s'active que lorsqu'un joueur tombe sur celle-ci

  switch(jou->position->effet){
     case 0: printf("Vous êtes sur la case de départ\n");
             break;
     case 1: printf("Vous êtes sur une case bleu, vous gagnez 3 pièces\n");
             jou->nb_pieces += 3;
             break;
     case 2: printf("Vous êtes sur une case rouge, vous perdez 3 pièces\n");
             if(jou->nb_pieces > 0){
               jou->nb_pieces -= 3;
             }else if(jou->nb_pieces < 0){
               jou->nb_pieces = 0;
             }
             break;
     case 3: printf("Vous êtes sur une case shop\n");
             break;
     case 4: printf("Vous êtes sur une case mini-jeux (1v3/2v2)\n");
             break;
     case 5: printf("Vous êtes sur une case méchante\n");
             break;
   }

}


void afficher_joueur_case(SDL_Renderer * rendu, SDL_Rect cases[NB_CASE], int case_courant[NB_JOUEURS], int joueurs )
{
  SDL_Surface * tableau0=NULL;
  SDL_Texture *texture=NULL;
  tableau0=IMG_Load("src/img/bonhomme_entre_deux.png");
  SDL_Rect joueur= {cases[case_courant[joueurs]].x,cases[case_courant[joueurs]].y,Fenetre_width/10, Fenetre_height/10};
  SDL_AfficherUneImage( rendu, tableau0, texture, joueur);

}

void afficher_joueur_bouge(SDL_Window *fenetre,SDL_Renderer * rendu, SDL_Rect cases[NB_CASE],int liste_cases[NB_CASE],int NB_DES, int case_courant[NB_JOUEURS],int joueurs,int nb_joueurs)
{
  SDL_Surface * tableau0=NULL;
  SDL_Texture * texture=NULL;
  clean_ressources(NULL,rendu,texture);
  afficher_plateau(fenetre,rendu,cases,liste_cases);
  for(int y=0; y<nb_joueurs;y++){
    if(y!=joueurs)
      afficher_joueur_case(rendu,cases,case_courant,y);
  }
  tableau0=IMG_Load("src/img/bonhomme_entre_deux.png");
  SDL_Rect joueur_position_finale={cases[case_courant[joueurs]+NB_DES].x,cases[case_courant[joueurs]+NB_DES].y,Fenetre_width/10, Fenetre_height/10};
  SDL_AfficherUneImage( rendu, tableau0, texture, joueur_position_finale);

  clean_ressources(NULL,NULL,texture);
}


void affichage_joueur_et_des(SDL_Renderer * rendu,int joueur,int numero_des){
      SDL_Surface *image=NULL;
      SDL_Texture *texture=NULL;
      SDL_Rect case_de= {Fenetre_width/8*4,Fenetre_height/8*4,Fenetre_width/8,Fenetre_height/8};
      SDL_Rect tour_joueur= {Fenetre_width/8*5,Fenetre_height/8*5,Fenetre_width/8,Fenetre_height/8};

      SDL_Rect au_tour_de= {Fenetre_width/8*4,Fenetre_height/8*5,Fenetre_width/8,Fenetre_height/8};
      image= IMG_Load("src/img/au_tour_de.png");
      SDL_AfficherUneImage(rendu,image,texture,au_tour_de);

      switch(joueur)
      {
        case 1:

          image= IMG_Load("src/img/Joueur1.png");
          SDL_AfficherUneImage(rendu,image,texture,tour_joueur);
          break;
        case 2:

          image= IMG_Load("src/img/Joueur2.png");
          SDL_AfficherUneImage(rendu,image,texture,tour_joueur);
          break;
        case 3:

          image= IMG_Load("src/img/Joueur3.png");
          SDL_AfficherUneImage(rendu,image,texture,tour_joueur);
          break;
        case 4:

          image= IMG_Load("src/img/Joueur4.png");
          SDL_AfficherUneImage(rendu,image,texture,tour_joueur);
          break;

      }

      switch(numero_des)
      {
        case 1:

          image= IMG_Load("src/img/de1.png");
          SDL_AfficherUneImage(rendu,image,texture,case_de);
          break;
        case 2:

          image= IMG_Load("src/img/de2.png");
          SDL_AfficherUneImage(rendu,image,texture,case_de);
          break;
        case 3:

          image= IMG_Load("src/img/de3.png");
          SDL_AfficherUneImage(rendu,image,texture,case_de);
          break;
        case 4:

          image= IMG_Load("src/img/de4.png");
          SDL_AfficherUneImage(rendu,image,texture,case_de);
          break;

        case 5:

          image= IMG_Load("src/img/de5.png");
          SDL_AfficherUneImage(rendu,image,texture,case_de);
          break;

        case 6:

          image= IMG_Load("src/img/de6.png");
          SDL_AfficherUneImage(rendu,image,texture,case_de);
          break;
        case 7:

          image= IMG_Load("src/img/de7.png");
          SDL_AfficherUneImage(rendu,image,texture,case_de);
          break;

        case 8:

          image= IMG_Load("src/img/de8.png");
          SDL_AfficherUneImage(rendu,image,texture,case_de);
          break;

        case 9:

            image= IMG_Load("src/img/de9.png");
            SDL_AfficherUneImage(rendu,image,texture,case_de);
            break;

        case 10:

            image= IMG_Load("src/img/de10.png");
            SDL_AfficherUneImage(rendu,image,texture,case_de);
            break;
      }
  clean_ressources(NULL,NULL,texture);
}