#include <stdio.h>
#include <stdlib.h>
#include "../include/mini_jeux.h"

t_joueur ** cache_cache(j1, j2, j3, j4){

  t_joueur ** gagnants[2];


//code cache_cache


  gagnants[0]= //le premier
  gagnants[1]= //le deuxieme
  return(gagnants);
}

/*
void crea_mj(void (*cache_cache)(int *e)){
  int i;

  // initialisation/création des mj 1vs1vs1vs1
  for(i=0; i<NB_MJ_NORM; i++){
    switch (i) {

      case 0: liste_mj_norm[0]= cache_cache;
              break;

      case 1:
              break;

      case 2:
              break;

      case 3:
              break;

      case 4:
              break;

      case 5:
              break;

      case 6:
              break;

      case 7:
              break;

    }
  }

  // initialisation/création des mj 2vs2
  for(i=0; i<NB_MJ_VS2; i++){
    switch (i) {

      case 0:

      case 1:

    }
  }

  // initialisation/création des mj 1vs3
  for(i=0; i<NB_MJ_VS3; i++){
    switch (i) {

      case 0:

      case 1:

    }
  }
} */

void appel_mj_fin_tour(){
  int random;
  rand()%NB_MJ_NORM;
  switch(random){
    case 0: cache_cache();
  }
}
