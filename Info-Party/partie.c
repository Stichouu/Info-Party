#include <stdio.h>
#include <stdlib.h>
#include "partie.h"
#include "joueur.h"

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
  int tab_de[NB_JOUEURS];
  for(i=0; i<NB_JOUEURS; i++){
    nb_obtenu = rand()%5+1;
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

  trie(tab_de, NB_JOUEURS);

  for(i=0; i<NB_JOUEURS; i++){
    if(tab_de[i] == de1){

    }else if(tab_de[i] == de2){

    }else if(tab_de[i] == de3){

    }else{

    }
  }

}

void une_partie(int nb_tours){
  ordre_jeu();
}
