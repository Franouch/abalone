#ifndef AFFICHE_H
#define AFFICHE_H

#include <stdio.h>
#include <stdlib.h>
#define couleur(param) printf("\033[%sm",param)


void affichesimple(int grille[11][11]);
void affiche(int grille[11][11]);
void affichediag(int grille[11][11]);
void afficheinit(int grille[11][11]);
void affichedeplace(int grille[11][11]);


#endif
