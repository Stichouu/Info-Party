#ifndef _PLATEAU_H_
#define _PLATEAU_H_
/**
* \file plateau.h
* \author Tan Tony
* \version 2.6
* \brief Les fonctions prototypes de plateau.c
*/
#include "petite_fonction.h"
/* Création des Objets et variables globales */
#define NB_CASE 40
/**
*\enum t_effet_case
*\brief les effets possibles d'une case.
*\param depart Désigne la case de départ.
*\param bleu Fait gagner 3 pièces à un joueur.
*\param rouge Fait perdre 3 pièces à un joueur.
*\param shop Permet d'ouvrir une boutique et d'acheter des objets.
*\param minijeux Déclenche un mini-jeu aléatoire.
*\param mechant Fait apparaître "le méchant" et ce dernier donne un malus aléatoire pour tous les joueurs ou seulement un joueur.
*/
typedef enum {depart, bleu, rouge, shop, minijeux, mechant} t_effet_case;
/**
* \struct case_jeu
*\brief Une case possède un effet,le numéro de la case,un pointeur sur la case précédente et un pointeur sur la case suivante.
*\param effet Objet de type t_effet_case Pour l'effet de la case
*\param nb_case Objet de type integer Pour le numéro de la case
*\param preced Pointeur sur un objet de type case_jeu Pour pointer la case précedente
*\param suiv Pointeur sur un objet de type case_jeu Pour pointer la case suivante
*/
typedef struct case_jeu{
  /* data */
  t_effet_case effet;
  int nb_case;
  struct case_jeu* preced;
  struct case_jeu* suiv;
}t_case;
/**le drapeau de notre liste */
t_case * drapeau;
/**l'élément courant de notre liste */
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
void crea_plat(int liste_case[NB_CASE],SDL_Rect cases[NB_CASE]);
void afficher_plateau(SDL_Window * fenetre,SDL_Renderer * rendu,SDL_Rect cases[NB_CASE],int liste_case[NB_CASE]);

#endif
