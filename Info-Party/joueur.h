##include "liste.h"

typedef struct joueur{
  t_case * position;
  int nb_pieces;
  int nb_badges;
  struct joueur * liste_joueur[3];
}t_joueur;

t_joueur * tete;
t_joueur * jc;

/* primitives liste */
void init_list();
int liste_vide();
int hors_liste();
void en_tete();
void en_queue();
void precedent();
void suivant();
void effet_case(t_effet_case * e);
void modif_case(t_effet_case e);
void oter_case();
void ajout_droit(t_effet_case e);
void ajout_gauche(t_effet_case e);
