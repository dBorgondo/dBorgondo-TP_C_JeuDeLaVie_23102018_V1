#include <SDL2/SDL.h>
#include <stdio.h>
#define TWindow 500
#include "values.h"
/*-----------------------------------
 Descriptions : Creation de la fenetre SDL
 Entrées : Pointeur vers la fenetre a cree
 Sorties : Fenetre cree
-----------------------------------*/
void creatWindow(SDL_Window** window){
    SDL_Init(SDL_INIT_VIDEO);
    *(window) = SDL_CreateWindow("Jeux de la vie",
                        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                        TWindow, TWindow,
                         SDL_WINDOW_RESIZABLE);
}

/*-----------------------------------
 Descriptions :Affichage du tableau dans fenetre SDL
 Entrées :Pointeur vers la fenetre ou affiche, tableau de tCell a afficher
 Sorties :Tableau affiche dans la fenetre
-----------------------------------*/
int printAreaSDL(SDL_Window** window, tCell Area[TAILLE][TAILLE])
{
    while (1) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {//Mit en place pour eviter que la fenetre soit considerer comme "ne repond pas" par absence d event
}
        SDL_Renderer* renderer;
        int nX=0;
        int nY=0;
        int nCpt=0;
        renderer = SDL_CreateRenderer(*(window), -1, 0);//Creation du pinceau
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);//On met la couleur a blanc
        for(nCpt=0;nCpt<TAILLE;nCpt++){
            SDL_RenderDrawLine(renderer, 0, nCpt*(TWindow/TAILLE), TWindow, nCpt*(TWindow/TAILLE));//On dessine les lignes horizontal du quadrillage
        }
        for(nCpt=0;nCpt<TAILLE;nCpt++){
            SDL_RenderDrawLine(renderer, nCpt*(TWindow/TAILLE), 0, nCpt*(TWindow/TAILLE), TWindow);//On dessine les lignes verticales du quadrillage
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);//On met la couleur à jaune
        SDL_Rect r;
        for(nY=0;nY<TAILLE;nY++){
            for(nX=0;nX<TAILLE;nX++){
            if(Area[nX][nY]){//On dessine un carre si jamais les coordonne correspondante du tableau sont de valeur "vivante"
                r.x = (((TWindow/TAILLE)*nX)+1);
                r.y = (((TWindow/TAILLE)*nY)+1);
                r.w = ((TWindow/TAILLE)-1);
                r.h = ((TWindow/TAILLE)-1);
                SDL_RenderFillRect( renderer, &r );
            }
            }
        }
        SDL_RenderPresent(renderer);//On applique les modifications
        SDL_DestroyRenderer(renderer);//On supprime le pinceau
        return 0;
    }
}


