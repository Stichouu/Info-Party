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

      case 0: printf("Le joueur 1 lance un des ...\n");
              printf("Il a obtenu un %i.\n",nb_obtenu);
              de1=nb_obtenu;
              break;

      case 1: printf("Le joueur 2 lance un des ...\n");
              printf("Il a obtenu un %i.\n",nb_obtenu);
              de2=nb_obtenu;
              break;

      case 2: printf("Le joueur 3 lance un des ...\n");
              printf("Il a obtenu un %i.\n",nb_obtenu);
              de3=nb_obtenu;
              break;

      case 3: printf("Le joueur 4 lance un des ...\n");
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

void une_partie(SDL_Window *fenetre,SDL_Renderer * rendu,SDL_Rect cases[NB_CASE],int liste_case[NB_CASE],int nb_tours,int nb_joueurs){
  int i, j, k;
  int jet_de;
  int case_courant[NB_JOUEURS];
  int stop=0;

  for (i=0 ; i < NB_JOUEURS; i++)
  {
    case_courant[i] = 0;
  }
  ordre_jeu();
  for(int y=0; y< nb_joueurs;y++){
      afficher_joueur_case(rendu,cases,case_courant,y);
  }
  /* Gestion des tours */

  for(i=0; i<nb_tours && stop!=1; i++){
    SDL_bool program =SDL_TRUE;
    printf("\n \n -- Nous sommes au tour %i --\n \n ", i+1);
      for(j=0; j<nb_joueurs; j++){
        printf("Au tour du joueur %i.\n",liste_joueurs[j]->num_joueur);
        printf("Lancez un des.\n");
        jet_de = rand()%9+1;
        affichage_joueur_et_des(rendu,liste_joueurs[j]->num_joueur,jet_de);
        while(program){
          SDL_Event event;
          while(SDL_PollEvent(&event)){
            switch(event.type)
            {
              case SDL_QUIT:
                program=SDL_FALSE;
                stop=1;
                break;
              case SDL_KEYUP:
                switch(event.key.keysym.sym)
                {
                  case SDLK_SPACE:
                    program=SDL_FALSE; 
                    break;
                }
                break;
            }
          }
        }
        if(stop!=1){

        case_courant[j]=case_courant[j]+jet_de;
        printf("%i\n",case_courant[j]);
        /* parcours du plateau */
        for(k=0; k<jet_de; k++){
          suivant_plat();
          if(hors_liste_plat()){
            en_tete_plat();
          }
          liste_joueurs[j]->position=ec;
          printf("%i \n",liste_joueurs[j]->position->effet);
        }
        effet_case(liste_joueurs[j]);
        afficher_joueur_bouge(fenetre,rendu,cases,liste_case,jet_de,case_courant,liste_joueurs[j]->num_joueur,nb_joueurs);


        printf("Vous avez %i pièces et %i badges.\n", liste_joueurs[j]->nb_pieces, liste_joueurs[j]->nb_badges);
      }
    }
  }
}
