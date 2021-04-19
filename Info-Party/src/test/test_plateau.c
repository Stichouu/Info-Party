#include "../../include/plateau.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
  crea_plat();
  int i;

  printf("\n Test creation plateau \n\n");
  for(i=0;i<NB_CASE && !hors_liste_plat(); i++){
      printf("effet case %i: %i\n\n",ec->nb_case,ec->effet);
      suivant_plat();
  }

  return(0);
}
