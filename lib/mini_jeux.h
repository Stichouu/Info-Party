#ifndef _MINI_JEUX_H_
#define _MINI_JEUX_H_

 //mj = "mini-jeux"
 //vs2 = 2vs2
 //vs3 = 1vs3
 //normal = 1vs1vs1vs1

 #define NB_MJ_NORM 8
 #define NB_MJ_VS2 2
 #define NB_MJ_VS3 2

typedef enum {normal, vs2, vs3} t_type_mj;

typedef struct mj{
  char * nom_mj;
  t_type_mj type_mj;
  t_joueur (*pt_fonc_mj) (t_joueur **);
}t_mj;

t_mj  liste_mj_norm[NB_MJ_NORM];
t_mj  liste_mj_vs2[NB_MJ_VS2];
t_mj  liste_mj_vs3[NB_MJ_VS3];

#endif
