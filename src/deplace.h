#ifndef DEPLACE_H
#define DEPLACE_H

int conversionLettreLigne(char Lettre);
int conversionPositionColonne(int ligne, int colonne);
int selectionnombreboules();
int selection();
int deplace(int grille[11][11], int x1, int y1, int x2, int y2, int x3, int y3, int direction, int nbboule, int senstrain);

#endif
