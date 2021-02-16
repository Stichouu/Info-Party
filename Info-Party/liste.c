#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

extern t_case * drapeau;
extern t_case * ec;



/* Mise en place par pointeurs des primitives d'accès à une liste */

void init_list(){
  drapeau = malloc(sizeof(t_case));
  drapeau->preced = drapeau;
  drapeau->suiv = drapeau;
  ec = drapeau;
}

int liste_vide(){
  return (drapeau->preced == drapeau);
}

int hors_liste(){
  return(ec == drapeau);
}

void en_tete(){
  if(!liste_vide())
    ec = drapeau->suiv;
}

void en_queue(){
  if(!liste_vide())
    ec = drapeau->preced;
}

void precedent(){
  if(!hors_liste())
    ec = ec->preced;
}

void suivant(){
  if(!hors_liste())
    ec = ec->suiv;
}

void effet_case(t_effet_case * e){
  if(!hors_liste())
    *e = ec->effet;
}

void modif_case(t_effet_case e){
  if(!hors_liste())
    ec->effet = e;
}

void oter_case(){
  t_case * sup;
  sup=ec;
  if(!hors_liste()){
    (ec->suiv)->preced = ec->preced;
    (ec->preced)->suiv = ec->suiv;
    ec = ec->preced;
    free(sup);
  }
}

void ajout_droit(t_effet_case e){
  t_case * nouv;
  nouv = malloc(sizeof(t_case));
  if(liste_vide() || !hors_liste()){
    nouv->effet = e;
    nouv->preced = ec;
    nouv->suiv = ec->suiv;
    (ec->suiv)->preced = nouv;
    ec->suiv = nouv;
    ec = nouv;
  }
}

void ajout_gauche(t_effet_case e){
  t_case * nouv;
  nouv = malloc(sizeof(t_case));
  if(liste_vide() || !hors_liste()){
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
void crea_plat(){
  //initialistaion variables
  init_list();
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

  t_effet_case effet = depart;
  ajout_droit(effet);
  ec->nb_case=0;

  for(i=1; i<NB_CASE; i++){
    do {
      indice=rand()%(NB_CASE-1);
    } while(liste_effet[indice] == -1);

    effet = liste_effet[indice];
    if(!hors_liste())
      ajout_droit(effet);
    ec->nb_case=i;
    liste_effet[indice]=-1;
  }
  en_tete();
}
