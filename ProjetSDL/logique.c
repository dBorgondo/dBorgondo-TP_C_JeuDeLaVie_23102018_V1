#include "values.h"
#include <stdlib.h>
#include <stdio.h>
/*-----------------------------------
 Descriptions : Initilise le tableau
 Entrées : Tableau de tCell
 Sorties : Tableau Initialisé
-----------------------------------*/
void initTab(tCell Area[TAILLE][TAILLE]){
    int nCptx=0;
    int nCpty=0;
    for(nCptx=0;nCptx<TAILLE;nCptx++){
        for(nCpty=0;nCpty<TAILLE;nCpty++){
            Area[nCptx][nCpty]=empty;
        }
    }
}
/*-----------------------------------
 Descriptions : On met des cellules du tableau alétoirement a l etat "vivant"
 Entrées : tableau de tCell
 Sorties : Tableau avec des cellules vivantes
-----------------------------------*/
void populate(tCell Area[TAILLE][TAILLE]){
    int nCptx=0;
    int nCpty=0;
    for(nCptx=0;nCptx<TAILLE;nCptx++){
        for(nCpty=0;nCpty<TAILLE;nCpty++){
            if((rand()%FERTILITY)==0){
            Area[nCptx][nCpty]=alive;
            }
        }
    }
}

/*-----------------------------------
 Descriptions : Compte le nombre de cellules voisines d'une cellule
 Entrées : Tableau de tCell, Abscisse de la cellule, Ordonnée de la cellule
 Sorties : Nombre de cellules voisines
-----------------------------------*/
void countNeighbors(tCell Area[TAILLE][TAILLE],int nX,int nY,int* result){
    int nCptx=0;
    int nCpty=0;
    int nCptcell=0;
    nX-=1;
    nY-=1;
    for(nCptx=0;nCptx<3;nCptx++){
        for(nCpty=0;nCpty<3;nCpty++){
            if(((((nX+nCptx)>=0)&&((nY+nCpty)>=0))&&(((nX+nCptx)<TAILLE)&&((nY+nCpty)<TAILLE)))&&(!(((nX+nCptx)==nX+1)&&((nY+nCpty)==nY+1)))&&((Area[nX+nCptx][nY+nCpty]))){ //On test si la cellule est vivante et on exclu la cellule dont on test les voisins
                nCptcell++;
            }
        }
    }
    *result=nCptcell;
}
/*-----------------------------------
 Descriptions : Met une cellule a son etat de la generation suivante
 Entrées : tableau de tCell a modifie, tableau de tCell reference,abcisse de la cellue, ordonnee de la cellule
 Sorties : cellule a son etat suivant
-----------------------------------*/
void evolve(tCell Area[TAILLE][TAILLE],tCell holderArea[TAILLE][TAILLE],int nX,int nY){
    int nNeighbors=0;
    int* pNeighbors=&nNeighbors;
    countNeighbors(holderArea,nX,nY,pNeighbors);
    if ((nNeighbors==3)||((Area[nX][nY]==alive)&&(nNeighbors==2))){
        Area[nX][nY]=alive;
    }
    else Area[nX][nY]=empty;
}
/*-----------------------------------
 Descriptions : Copie un Tableau dans un autre
 Entrées : Tableau a copie et tableau cible
 Sorties : Tableau copie
-----------------------------------*/
void copyArea(tCell Area[TAILLE][TAILLE],tCell pastedArea[TAILLE][TAILLE]){
    int nCptx=0;
    int nCpty=0;
    for(nCptx=0;nCptx<TAILLE;nCptx++){
        for(nCpty=0;nCpty<TAILLE;nCpty++){
            pastedArea[nCptx][nCpty]=Area[nCptx][nCpty];
    }
}
}

/*-----------------------------------
 Descriptions : Fait avancer un tableau de cellules a son etat suivant
 Entrées : Tableau de tCell
 Sorties : Tableau a son etat suivant
-----------------------------------*/
void evolveArea(tCell Area[TAILLE][TAILLE]){
    tCell holderArea[TAILLE][TAILLE];
    initTab(holderArea);
    copyArea(Area,holderArea);//On utilise un tableau tampon pour contenir l etat initial du tableau
    int nCptx=0;
    int nCpty=0;
    for(nCptx=0;nCptx<TAILLE;nCptx++){
        for(nCpty=0;nCpty<TAILLE;nCpty++){
            evolve(Area,holderArea,nCptx,nCpty);
    }
}
}
/*-----------------------------------
 Descriptions : Compte le nombre de cellule vivante dans un tableau
 Entrées : Tableau de tCell
 Sorties : Nombre de cellules vivantes
-----------------------------------*/
int countAlive(tCell Area[TAILLE][TAILLE]){
    int nResult=0;
    int nCptx=0;
    int nCpty=0;
    for(nCptx=0;nCptx<TAILLE;nCptx++){
        for(nCpty=0;nCpty<TAILLE;nCpty++){
            if(Area[nCptx][nCpty]){
                nResult++;
            }
        }
    }
    return nResult;
}

/*-----------------------------------
 Descriptions : Transformes les valeurs des conditions initial en chaine de caracteres
 Entrées : Buffer, Taille , Fetilite,
 Sorties : Chaine de caractere contenant les informations sur les conditions initale
-----------------------------------*/
void initialCondition(char cBuffer[SIZEBUFFER],int nTaille, int nFertility){
    snprintf(cBuffer,SIZEBUFFER,"Condition Initiales :\nTaille : %d  Fertilite : %d \n\n",nTaille,nFertility);
}

/*-----------------------------------
 Descriptions : Transformes le nombre de cellule vivante d'une generation en chaine de caracteres
 Entrées : Buffer, Numero de la generation, nombre de cellules vivantes
 Sorties : Cahines de caractere contenant les informations sur la generation
-----------------------------------*/
void generationInfo(char cBuffer[SIZEBUFFER],int nGeneration,int nbCells){
    snprintf(cBuffer,SIZEBUFFER,"Generation %d : %d\n",nGeneration,nbCells);
    nGeneration++;
}
/*-----------------------------------
 Descriptions : Recupere le nombre de generation que l utilisateur souhaite generer
 Entrées :
 Sorties : Nombre d iteration
-----------------------------------*/
void getIteration(int* nIteration){
    printf("Veuillez entrez le nombre de generation a generer:\n");
    scanf("%d",nIteration);
}
