#include <SDL2/SDL.h>
#include "VueSDL.h"
#include <stdio.h>
#include <stdlib.h>
#define TWindow 500
#include <time.h>
#include "values.h"
#include "vue.h"
#include "fichier.h"
#include "logique.h"
int main(int argc, char* argv[])
{
    SDL_Window* window;
    tCell Area[TAILLE][TAILLE];
    int nGeneration=0;
    int nIterations=10;
    char cBuffer[SIZEBUFFER]="";//Buffer utiliser pour transmettre les chaines de character au fichier txt
    srand(time(NULL));//Initialisation de la seed du random
    createFile();//Création du fichier
    initialCondition(cBuffer,TAILLE,FERTILITY);//On place les condition initiale dans le buffer
    addtoFile(cBuffer);//Ecriture des condition initial dans le fichier txt
    initTab(Area);//Initalisation du Tableau
    populate(Area);//Population du Tableau (Les cellules sont mit aléatoirement à alive ou empty)
    getIteration(&nIterations);//On demande à l utilisateur combien de generation il souhaite generer
    creatWindow(&window);//Creation de la fenetre SDL
    for(nGeneration=0;nGeneration<=nIterations;nGeneration++){
        printf("Generation %d:",nGeneration);//Affichage du numéro de la generation
        printAreaSDL(&window,Area);//On affichage le tableau dans la fenetre SDL
        printArea(Area);//On affiche le tableau dans la console
        generationInfo(cBuffer,nGeneration,countAlive(Area));//On place les information sur la generation dans le buffer
        addtoFile(cBuffer);//On ecrit les informations dans le fichier
        evolveArea(Area);//On fait evoluer toutes les cellules
        system("pause");
    }
    return 0;
}


