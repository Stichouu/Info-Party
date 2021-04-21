#include <stdio.h>
#include <stdlib.h>
#include "../lib/plateau.h"
#include "../lib/petite_fonction.h"
#include <SDL.h>
#include <SDL_image.h>
/**
* \file plateau.c
* \author Tan Tony
* \author Tessier Killian
* \version 3.0
* \brief Le plateau de notre jeu
*/

/* Mise en place par pointeurs des primitives d'accès à une liste */

/**
* \fn void init_list_plat()
* \brief On initialise notre liste.
*/
void init_list_plat(){
  drapeau = malloc(sizeof(t_case));
  drapeau->preced = drapeau;
  drapeau->suiv = drapeau;
  ec = drapeau;
}

/**
* \fn int liste_vide_plat
* \brief Une fonction booléenne qui renvoie vrai si la liste est vide.
*/
int liste_vide_plat(){
  return (drapeau->preced == drapeau);
}

/**
* \fn int hors_liste_plat()
*\brief Une fonction booléenne qui renvoie vrai si l'élément courant est sorti de la liste.
*/
int hors_liste_plat(){
  return(ec == drapeau);
}

/**
* \fn en_tete_plat()
* \brief Cette fonction place l'élément courant, à l'élément en tête de liste si la liste n'est pas vide.
*/
void en_tete_plat(){
  if(!liste_vide_plat())
    ec = drapeau->suiv;
}

/**
* \fn en_queue_plat()
* \brief Cette fonction place l'élément courant, à l'élément en queue de liste si la liste n'est pas vide.
*/
void en_queue_plat(){
  if(!liste_vide_plat())
    ec = drapeau->preced;
}

/**
* \fn void precedent_plat()
* \brief Place l'élément courant à l'élément précédent si nous ne sommes pas sorti de la liste.
*/
void precedent_plat(){
  if(!hors_liste_plat())
    ec = ec->preced;
}

/**
* \fn void suivant_plat()
* \brief Place l'élément courant à l'élément suivant si nous ne sommes pas sorti de la liste.
*/
void suivant_plat(){
  if(!hors_liste_plat())
    ec = ec->suiv;
}

/**
* \fn void effet_case_plat(t_effet_case * e)
* \param adresse d'un type enum correspondant à un effet de case.
* \brief Renvoie à l'adresse entrée en paramètre l'effet de l'élément courant.
*/
void effet_case_plat(t_effet_case * e){
  if(!hors_liste_plat())
    *e = ec->effet;
}

/**
* \fn void modif_case_plat(t_effet_case e)
* \param e Objet de type t_effet_case correspondant à un effet de case.
* \brief Donne à l'effet de l'élément courant la valeur entrée en paramètre.
*/
void modif_case_plat(t_effet_case e){
  if(!hors_liste_plat())
    ec->effet = e;
}

/**
* \fn void oter_case_plat()
* \brief Si nous ne sommes pas sortis de la liste, supprimer l'élément courant.
*/
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

/**
* \fn void ajout_droit_plat(t_effet_case e)
* \param Objet de type t_effet_case correspondant à un effet de case.
* \brief Ajoute à droite de l'élément courant une case avec pour effet la valeur entrée en paramètre.
*/
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

/**
* \fn void ajout_gauche_plat(t_effet_case e)
* \param Objet de type t_effet_case correspondant à un effet de case.
* \brief Ajoute à gauche de l'élément courant une case avec pour effet la valeur entrée en paramètre.
*/
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

/**
* \fn void crea_plat(int liste_case[NB_CASE],SDL_Rect cases[NB_CASE])
* \param liste_cases[NB_CASE] Tableau de taille NB_CASE d'objet de type integer
* \param cases[NB_CASE] Tableau de taille NB_CASE d'objet de type SDL_Rect déjà initialisé
* \brief création du plateau et initialisation du plateau
*/
/* Création du plateau */
void crea_plat(int liste_case[NB_CASE],SDL_Rect cases[NB_CASE]){
  //initialistaion variables
  init_list_plat();
  int i;
  int liste_effet[NB_CASE-1];
  int indice;
  // création de la liste de toutes les cases
  for(i=0; i<NB_CASE-1; i++){
    if(i<15){ // 15 cases bleues
      liste_effet[i]=1;
    }else if(15<=i && i<23){ // 8 cases rouges
      liste_effet[i]=2;
    }else if(23<=i && i<27){ // 4 cases shop
      liste_effet[i]=3;
    }else if(27<=i && i<36){ // 9 cases mini-jeux
      liste_effet[i]=4;
    }else{ // 3 cases mechant
      liste_effet[i]=5;
    }
  }
    cases[0].w=Fenetre_height/8;
    cases[0].h=Fenetre_height/8;
    cases[0].x=0;
    cases[0].y=Fenetre_height-Fenetre_height/8;
    for(i=1;i<NB_CASE;i++){
      cases[i].w=Fenetre_height/8;
      cases[i].h=Fenetre_height/8;
      cases[i].x=cases[i-1].x+Fenetre_height/8;
      cases[i].y=cases[i-1].y;

      if(cases[i].x >Fenetre_width-Fenetre_height/8 && cases[i].y>Fenetre_height/8){
    	 cases[i].x=cases[i-1].x;
    	 cases[i].y=cases[i-1].y-Fenetre_height/8;
      }else
      if(cases[i].y<Fenetre_height/8 && cases[i].x>Fenetre_height/8){
          cases[i].y=cases[i-1].y;
        	cases[i].x=cases[i-1].x-Fenetre_height/8;
      }else if(cases[i].x<=Fenetre_height/8 && i>30){
              cases[i].x=cases[i-1].x;
              cases[i].y=cases[i-1].y+Fenetre_height/8;
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
    ec->effet=effet;
    liste_case[i]=effet;
    liste_effet[indice]=-1;
  }
  en_tete_plat();
}

/**
* \fn void afficher_plateau(SDL_Window *fenetre,SDL_Renderer * rendu,SDL_Rect cases[NB_CASE],int liste_case[NB_CASE])
* \param fenetre Pointeur sur un objet de type SDL_Window
* \param rendu Pointeur sur un objet de type SDL_Renderer
* \param liste_cases[NB_CASE] Tableau de taille NB_CASE d'objet de type integer
* \param cases[NB_CASE] Tableau de taille NB_CASE d'objet de type SDL_Rect déjà initialisé
* \brief affichage du plateau
*/
/*affichage du plateau */
void afficher_plateau(SDL_Window *fenetre,SDL_Renderer * rendu,SDL_Rect cases[NB_CASE],int liste_case[NB_CASE]){
  SDL_Surface *image=NULL;
  SDL_Texture *texture=NULL;
  SDL_Texture *imagefond=NULL;
  clean_ressources(NULL,rendu,NULL);
      //Création du rendu de plateau
  rendu=SDL_CreateRenderer(fenetre,-1,0);
  if(rendu == NULL)
    SDL_ExitWithError("Le rendu n'a pas pu être créé");


  //Création de l'image de fond
  SDL_Rect fond={0,0,Fenetre_width,Fenetre_height};
  image= IMG_Load("src/img/fond_plateau.png");
  SDL_AfficherUneImage(rendu,image,imagefond,fond);
  
  image= IMG_Load("src/img/case_depart.png");
  SDL_AfficherUneImage(rendu,image,texture,cases[0]);

  for(int i=0;i<NB_CASE;i++){
    switch(liste_case[i]){
      case 1:
        image= IMG_Load("src/img/case_bleue.png");
        SDL_AfficherUneImage(rendu,image,texture,cases[i]);
      break;
      case 2:
        image= IMG_Load("src/img/case_rouge.png");
        SDL_AfficherUneImage(rendu,image,texture,cases[i]);
      break;
      case 3:
        image= IMG_Load("src/img/case_shop.png");
        SDL_AfficherUneImage(rendu,image,texture,cases[i]);
      break;
      case 4:
        image= IMG_Load("src/img/case_mini_jeu.png");
        SDL_AfficherUneImage(rendu,image,texture,cases[i]);
      break;
      case 5:
        image= IMG_Load("src/img/case_méchant.png");
        SDL_AfficherUneImage(rendu,image,texture,cases[i]);    
      break;

    }
  }
  clean_ressources(NULL,NULL,texture);
  clean_ressources(NULL,NULL,imagefond);
}