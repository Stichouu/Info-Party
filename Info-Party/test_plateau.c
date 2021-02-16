#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "liste.h"

extern t_case * drapeau;
extern t_case * ec;


int main(){
  srand( time( NULL ) );
  crea_plat();
  int i,nb_choix;

  for(i=0;i<NB_CASE && !hors_liste(); i++){
    printf("effet case %i: %i\n",ec->nb_case,ec->effet);
    suivant();
  }

  /* position de départ et initialisation des joueur*/
  t_joueur * j1;
  en_tete();
  j1=malloc(sizeof(t_joueur));
  j1->position=ec;
  j1->nb_pieces=0;
  j1->nb_badges=0;

  /* parcours du plateau */
  printf("choisissez un nombre \n");
  scanf("%i",&nb_choix);
  for(i=0; i<nb_choix; i++){
    suivant();
    if(hors_liste()){
      en_tete();
    }
    j1->position=ec;
  }
  printf("Vous êtes sur la case %i qui a pour effet: %i\n",j1->position->nb_case,j1->position->effet);

  /* effet case */
  switch(j1->position->effet){
    case 0: printf("Vous êtes sur la case de départ\n");
            break;
    case 1: printf("Vous êtes sur une case bleu, vous gagnez 3 pièces\n");
            j1->nb_pieces+=3;
            printf("Vous avez %i pièces\n",j1->nb_pieces);
            break;
    case 2: printf("Vous êtes sur une case rouge, vous perdez 3 pièces\n");
            if(j1->nb_pieces!=0){
                j1->nb_pieces-=3;
            }
            printf("Vous avez %i pièces\n",j1->nb_pieces);
            break;
    case 3: printf("Vous êtes sur une case shop\n");
            break;
    case 4: printf("Vous êtes sur une case mini-jeux (1v3/2v2)\n");
            break;
    case 5: printf("Vous êtes sur une case méchante\n");
            break;
  }

  return 0;
}
