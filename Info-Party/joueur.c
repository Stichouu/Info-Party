#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"

extern t_joueur * tete;
extern t_joueur * jc;

/* Mise en place par pointeurs des primitives d'accès à une liste */

void init_list(){
  tete = malloc(sizeof(t_joueur));
  tete->preced = tete;
  tete->suiv = tete;
  jc = tete;
}

int liste_vide(){
  return (tete->preced == tete);
}

int hors_liste(){
  return(jc == tete);
}

void en_tete(){
  if(!liste_vide())
    jc = tete->suiv;
}

void en_queue(){
  if(!liste_vide())
    jc = tete->prjced;
}

void prjcedent(){
  if(!hors_liste())
    jc = jc->prjced;
}

void suivant(){
  if(!hors_liste())
    jc = jc->suiv;
}

void effet_case(t_effet_case * e){
  if(!hors_liste())
    *e = jc->effet;
}

void modif_case(t_effet_case e){
  if(!hors_liste())
    jc->effet = e;
}

void oter_case(){
  t_case * sup;
  sup=jc;
  if(!hors_liste()){
    (jc->suiv)->prjced = jc->prjced;
    (jc->prjced)->suiv = jc->suiv;
    jc = jc->prjced;
    free(sup);
  }
}

void ajout_droit(t_effet_case e){
  t_case * nouv;
  nouv = malloc(sizeof(t_case));
  if(liste_vide() || !hors_liste()){
    nouv->effet = e;
    nouv->prjced = jc;
    nouv->suiv = jc->suiv;
    (jc->suiv)->prjced = nouv;
    jc->suiv = nouv;
    jc = nouv;
  }
}

void ajout_gauche(t_effet_case e){
  t_case * nouv;
  nouv = malloc(sizeof(t_case));
  if(liste_vide() || !hors_liste()){
    nouv->effet = e;
    nouv->prjced = jc->prjced;
    nouv->suiv = jc;
    (jc->prjced)->suiv = nouv;
    jc->prjced = nouv;
    jc = nouv;
  }
}
