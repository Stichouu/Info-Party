#include <stdio.h>
#include <stdlib.h>
#include "../lib/mini_jeux.h"
/**
* \file mini_jeux.c
* \author Tessier Killian
* \version 1.4
* \brief L'accès aux mini-jeux mais ce fichier ne sert pas dans notre code
*/

/** 
* \fn void crea_mj()
*\brief la fonction permet d'initialiser les différents mini-jeux.
*/
void crea_mj(){
  int i;

  // initialisation/création des mj 1vs1vs1vs1
  for(i=0; i<NB_MJ_NORM; i++){
    switch (i) {

      case 0:
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
}
