#ifndef LOGIQUE_H_INCLUDED
#define LOGIQUE_H_INCLUDED

extern void initTab(tCell Area[TAILLE][TAILLE]);
extern void populate(tCell Area[TAILLE][TAILLE]);
extern void countNeighbors(tCell Area[TAILLE][TAILLE],int nX,int nY,int* result);
extern void evolve(tCell Area[TAILLE][TAILLE],tCell holderArea[TAILLE][TAILLE],int nX,int nY);
extern void evolveArea(tCell Area[TAILLE][TAILLE]);
extern void copyArea(tCell Area[TAILLE][TAILLE],tCell pastedArea[TAILLE][TAILLE]);
extern int countAlive(tCell Area[TAILLE][TAILLE]);
extern void initialCondition(char cBuffer[SIZEBUFFER],int nTaille, int nFertility);
extern void generationInfo(char cBuffer[SIZEBUFFER],int nGeneration,int nbCells);
extern void getIteration(int* nIteration);

#endif // LOGIQUE_H_INCLUDED

