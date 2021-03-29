#include <stdio.h>
#include <stdlib.h>
#include "../lib/partie.h"

void trie(int * t, int n){
// trie dans l'ordre décroissant (trie bulle)
  int i, j, x;
  for(i=0; i<n; i++){
    for(j=n-1; j>i; j--){
      if(t[j-1] < t[j]){
        x=t[j];
        t[j] = t[j-1];
        t[j-1] = x;
      }
    }
  }
}

void ordre_jeu(){
// Fonction qui définit l'ordre de jeu en début de partie.

  int i, nb_obtenu, de1, de2, de3, de4;

  int flag_jou1 = 0;
  int flag_jou2 = 0;
  int flag_jou3 = 0;
  int flag_jou4 = 0;
  int de_ok;

  int tab_de[NB_JOUEURS];

  /* chaque joueur lance un dé */
  for(i=0; i<NB_JOUEURS; i++){
    nb_obtenu = rand()%9+1;
    switch (i) {

      case 0: printf("Le joueur 1 lance un dé ...\n");
              printf("Il a obtenu un %i.\n",nb_obtenu);
              de1=nb_obtenu;
              break;

      case 1: printf("Le joueur 2 lance un dé ...\n");
              printf("Il a obtenu un %i.\n",nb_obtenu);
              de2=nb_obtenu;
              break;

      case 2: printf("Le joueur 3 lance un dé ...\n");
              printf("Il a obtenu un %i.\n",nb_obtenu);
              de3=nb_obtenu;
              break;

      case 3: printf("Le joueur 4 lance un dé ...\n");
              printf("Il a obtenu un %i.\n",nb_obtenu);
              de4=nb_obtenu;
              break;
    }
    tab_de[i] = nb_obtenu;
  }

  /* tri décroissant (celui qui fait le plus gros score commence) */
  trie(tab_de, NB_JOUEURS);

  for(i=0; i<NB_JOUEURS; i++){
    de_ok = 0;

    if(tab_de[i] == de1 && de_ok == 0){
      if(flag_jou1 == 0){
        liste_joueurs[i] = jou1;
        flag_jou1 = 1;
        de_ok = 1;
      }
    }

    if(tab_de[i] == de2 && de_ok == 0){
      if(flag_jou2 == 0){
        liste_joueurs[i] = jou2;
        flag_jou2 = 1;
        de_ok = 1;
      }
    }

    if(tab_de[i] == de3 && de_ok == 0){
      if(flag_jou3 == 0){
        liste_joueurs[i] = jou3;
        flag_jou3 = 1;
        de_ok = 1;
      }
    }

    if(tab_de[i] == de4 && de_ok == 0){
      if(flag_jou4 == 0){
        liste_joueurs[i] = jou4;
        flag_jou4 = 1;
        de_ok = 1;
      }
    }
  }

}

void une_partie(int nb_tours){
  int i, j, k;
  int jet_de;

  ordre_jeu();

  /* Gestion des tours */

  for(i=0; i<NB_TOURS; i++){
    printf("\n \n -- Nous sommes au tour %i --\n \n ", i+1);
      for(j=0; j<NB_JOUEURS; j++){
        printf("Au tour du joueur %i.\n",liste_joueurs[j]->num_joueur);
        printf("Lancez un dé.\n");
        jet_de = rand()%9+1;

        /* parcours du plateau */
        for(k=0; k<jet_de; k++){
          suivant_plat();
          if(hors_liste_plat()){
            en_tete_plat();
          }
          liste_joueurs[j]->position=ec;
        }
        effet_case(liste_joueurs[j]);
        printf("Vous avez %i pièces et %i badges.\n", liste_joueurs[j]->nb_pieces, liste_joueurs[j]->nb_badges);
      }
  }
}
