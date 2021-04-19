#include <stdio.h>
#include <stdlib.h>
#include "../include/joueur.h"


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
