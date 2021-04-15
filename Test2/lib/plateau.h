#ifndef _PLATEAU_H_
#define _PLATEAU_H_

#include "petite_fonction.h"

/* Création des Objets et variables globales */
#define NB_CASE 40

typedef enum {depart, bleu, rouge, shop, minijeux, mechant} t_effet_case;

typedef struct case_jeu{
  /* data */
  t_effet_case effet;
  int nb_case;
  struct case_jeu* preced;
  struct case_jeu* suiv;
}t_case;

t_case * drapeau;
t_case * ec;

/* primitives liste */
void init_list_plat();
int liste_vide_plat();
int hors_liste_plat();
void en_tete_plat();
void en_queue_plat();
void precedent_plat();
void suivant_plat();
void effet_case_plat(t_effet_case * e);
void modif_case_plat(t_effet_case e);
void oter_case_plat();
void ajout_droit_plat(t_effet_case e);
void ajout_gauche_plat(t_effet_case e);

/* fonctions plateau*/
void crea_plat(SDL_Window *fenetre);

#endif
