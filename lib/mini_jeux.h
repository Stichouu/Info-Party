#ifndef _MINI_JEUX_H_
#define _MINI_JEUX_H_
/**
* \file mini_jeux.h
* \author Tessier Killian
* \version 1.2
* \brief Les fonctions prototypes de mini_jeux.c
*/
 //mj = "mini-jeux"
 //vs2 = 2vs2
 //vs3 = 1vs3
 //normal = 1vs1vs1vs1

 #define NB_MJ_NORM 8
 #define NB_MJ_VS2 2
 #define NB_MJ_VS3 2
/**
*\enum t_type_mj
*\brief Une énumération de tous les types de mini-jeux
*\param normal un mini-jeu chacun pour soi
*\param vs2 un mini-jeu 2v2
*\param vs3 un mini-jeu 1v3
*/
typedef enum {normal, vs2, vs3} t_type_mj;

/**
*\struct mj
*\brief Un mini-jeu contient un pointeur sur le nom du mini-jeu,le type de mini-jeu et un pointeur sur une fonction d'un mini-jeu.
*\param nom_mj Pointeur sur un objet de type char 
*\param Objet de type t_type_mj
*\param Pointeur sur une fonction de type t_joueur avec en paramètre un pointeur sur un pointeur qui pointe un objet de type t_joueur.
*/
typedef struct mj{
  char * nom_mj;
  t_type_mj type_mj;
  t_joueur (*pt_fonc_mj) (t_joueur **);
}t_mj;
/**la liste de tous les mini-jeux normaux*/
t_mj  liste_mj_norm[NB_MJ_NORM];
/**la liste de tous les mini-jeux 2v2*/
t_mj  liste_mj_vs2[NB_MJ_VS2];
/**la liste de tous les mini-jeux 1v3*/
t_mj  liste_mj_vs3[NB_MJ_VS3];

#endif
