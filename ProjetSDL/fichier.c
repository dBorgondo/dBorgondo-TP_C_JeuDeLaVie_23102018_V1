#include <stdio.h>
#include "values.h"
#define PATH "historique.txt"
/*-----------------------------------
 Descriptions : Creation du fichier txt
 Entr�es :
 Sorties : Fichier txt
-----------------------------------*/
void createFile(){

    FILE *pFile;
    if (((pFile=fopen(PATH,"w")))==NULL){
        perror("Error");
    }else{
        pFile = fopen(PATH,"w");
        fclose(pFile);
    }

}
/*-----------------------------------
 Descriptions : On ecrit la chaine de caractere entre dans la procedure dans le fichier txt
 Entr�es : chaine de charactere a ecrire
 Sorties : fichier txt modifie
-----------------------------------*/
void addtoFile(char cBuffer[SIZEBUFFER]){

    FILE *pFile;
    if (((pFile=fopen(PATH,"a")))==NULL){
        perror("Erreur fichier introuvable. Veuillez le cr�er d'abord.");
    }else{
        pFile = fopen(PATH,"a");
        fprintf(pFile,cBuffer);
        fclose(pFile);
    }

}

