#include <stdio.h>
#include <stdlib.h>
#include "../lib/plateau.h"
#include "../lib/petite_fonction.h"
#include <SDL.h>
#include <SDL_image.h>




/* Mise en place par pointeurs des primitives d'accès à une liste */

void init_list_plat(){
  drapeau = malloc(sizeof(t_case));
  drapeau->preced = drapeau;
  drapeau->suiv = drapeau;
  ec = drapeau;
}

int liste_vide_plat(){
  return (drapeau->preced == drapeau);
}

int hors_liste_plat(){
  return(ec == drapeau);
}

void en_tete_plat(){
  if(!liste_vide_plat())
    ec = drapeau->suiv;
}

void en_queue_plat(){
  if(!liste_vide_plat())
    ec = drapeau->preced;
}

void precedent_plat(){
  if(!hors_liste_plat())
    ec = ec->preced;
}

void suivant_plat(){
  if(!hors_liste_plat())
    ec = ec->suiv;
}

void effet_case_plat(t_effet_case * e){
  if(!hors_liste_plat())
    *e = ec->effet;
}

void modif_case_plat(t_effet_case e){
  if(!hors_liste_plat())
    ec->effet = e;
}

void oter_case_plat(){
  t_case * sup;
  sup=ec;
  if(!hors_liste_plat()){
    (ec->suiv)->preced = ec->preced;
    (ec->preced)->suiv = ec->suiv;
    ec = ec->preced;
    free(sup);
  }
}

void ajout_droit_plat(t_effet_case e){
  t_case * nouv;
  nouv = malloc(sizeof(t_case));
  if(liste_vide_plat() || !hors_liste_plat()){
    nouv->effet = e;
    nouv->preced = ec;
    nouv->suiv = ec->suiv;
    (ec->suiv)->preced = nouv;
    ec->suiv = nouv;
    ec = nouv;
  }
}

void ajout_gauche_plat(t_effet_case e){
  t_case * nouv;
  nouv = malloc(sizeof(t_case));
  if(liste_vide_plat() || !hors_liste_plat()){
    nouv->effet = e;
    nouv->preced = ec->preced;
    nouv->suiv = ec;
    (ec->preced)->suiv = nouv;
    ec->preced = nouv;
    ec = nouv;
  }
}

/* Fin des primitives */

/* Création du plateau */
void crea_plat(SDL_Window *fenetre){
  //initialistaion variables
  init_list_plat();
  int i;
  int liste_effet[NB_CASE-1];
  int indice;
  SDL_Renderer *rendu= NULL;
  SDL_Surface *image=NULL;
  //SDL_Texture *texture=NULL;
  SDL_Texture *imagefond=NULL;
  //SDL_bool program =SDL_TRUE;
  //Création du rendu
  rendu=SDL_CreateRenderer(fenetre,-1,0);
  if(rendu == NULL)
  {
   SDL_ExitWithError("Le rendu n'a pas pu être créé");
  }

  //Création de l'image de fond
  SDL_Rect fond={0,0,Fenetre_width,Fenetre_height};
  image= IMG_Load("src/img/lac_en_montagne.bmp");
  SDL_AfficherUneImage(rendu,image,imagefond,fond);


  // création de la liste de toutes les cases
  for(i=0; i<NB_CASE-1; i++){
    if(i<15){ // 15 cases bleues
      liste_effet[i]=1;
      //afficher_case(i,texture,image);
    }else if(15<=i && i<23){ // 8 cases rouges
      liste_effet[i]=2;
      //afficher_case(i,texture,image);
    }else if(23<=i && i<27){ // 4 cases shop
      liste_effet[i]=3;
      //afficher_case(i,texture,image);
    }else if(27<=i && i<36){ // 9 cases mini-jeux
      liste_effet[i]=4;
      //afficher_case(i,texture,image);
    }else{ // 3 cases mechant
      liste_effet[i]=5;
      //afficher_case(i,texture,image);
    }
  }

  t_effet_case effet = depart;
  ajout_droit_plat(effet);
  ec->nb_case=0;

  for(i=1; i<NB_CASE; i++){
    do {
      indice=rand()%(NB_CASE-1);
    } while(liste_effet[indice] == -1);
    
    effet = liste_effet[indice];
    if(!hors_liste_plat())
      ajout_droit_plat(effet);
    ec->nb_case=i;
    liste_effet[indice]=-1;
  }
  en_tete_plat();
}
