#ifndef INTELLIGENCE_H
#define INTELLIGENCE_H

int recuplignerougebasse(int grille[11][11]);
int recupcolrougebasse(int grille[11][11], int lrb);
int recuplignebleuehaute(int grille[11][11]);
//int recupcolbleuehaute(int grille[11][11], int lbh);

int recuplignerougehaute(int grille[11][11]);
int recuplignebleuebasse(int grille[11][11]);

int recupcolbleuehautedroite(int grille[11][11], int lbh);
int recupcolbleuehautegauche(int grille[11][11], int lbh);

int recupcolrougebassegauche(int grille[11][11], int lrb);
int recupcolrougebassedroite(int grille[11][11], int lrb);

#endif
