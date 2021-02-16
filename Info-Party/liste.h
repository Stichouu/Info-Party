
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

typedef struct joueur{
  t_case * position;
  int nb_pieces;
  int nb_badges;
}t_joueur;

t_case * drapeau;
t_case * ec;

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

/* fonctions plateau*/
void crea_plat();
