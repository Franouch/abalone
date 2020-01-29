#include <stdio.h>
#include <stdlib.h>

int menu()
{
	int choixmenu;
	
	printf("\n");
	printf("Bienvenue dans ABALONE \n");
	printf("\n");
	
	printf("1) Nouvelle partie Joueur vs. Joueur \n\n");
	printf("2) Restaurer partie Joueur vs. Joueur \n\n");
	printf("3) Nouvelle partie Joueur vs. I.A. \n\n");
	printf("4) Restaurer partie Joueur vs. I.A. \n\n");
	printf("5) Nouvelle partie I.A. vs. I.A. \n\n");
	printf("6) Nouvelle partie I.A. vs. I.A. en mode pas-à-pas \n\n");
	printf("7) Quitter \n\n");
	printf("\n>>> ");
	
	scanf("%d", &choixmenu);
	printf("\n");
	
	return choixmenu;
}
