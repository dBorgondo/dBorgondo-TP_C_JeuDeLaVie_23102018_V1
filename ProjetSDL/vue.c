#include "values.h"
#include <stdio.h>
/*-----------------------------------
 Descriptions : Affiche le tableau dans la console
 Entrées : Tableau de tCell
 Sorties : Tableau affiche dans la console
-----------------------------------*/
void printArea(tCell Area[TAILLE][TAILLE]){
    int nCptx=0;
    int nCpty=0;
    printf("\n");
    for(nCptx=0;nCptx<TAILLE;nCptx++){
        for(nCpty=0;nCpty<TAILLE;nCpty++){
            if((Area[nCpty][nCptx])){
                printf("[#]");
            }
            else{
                printf("[ ]");
            }
        }
        printf("\n");
    }
}

