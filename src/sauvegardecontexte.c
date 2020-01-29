#include <stdio.h>
#include "global.h"

int sauvegarde(int grille[11][11], int tourjoueur, int nbdeplacebleu, int nbdeplacerouge, int boulesperduesbleu, int boulesperduesrouge)
{
	int i,j;
	
	FILE *fichier;
	// Ouverture du fichier en écriture grâce à "w"
	fichier = fopen("res/sauvegarde.txt","w");
	
	// Verifier que le fichier a bien été ouvert
	if (fichier != NULL)
	{
		//Écriture
		for(i=0;i<11;i++)
		{
			for(j=0;j<11;j++)
			{
				fprintf(fichier, "%d ", grille[i][j]);
			}
			fprintf(fichier, "\n");
		}
		
		fprintf(fichier, "%d\n", tourjoueur);
		fprintf(fichier, "%d\n", nbdeplacebleu);
		fprintf(fichier, "%d\n", nbdeplacerouge);
		fprintf(fichier, "%d\n", boulesperduesbleu);
		fprintf(fichier, "%d\n", boulesperduesrouge);
		
		// Fermeture du fichier
		fclose(fichier);
	}
	return 0;
}


int reprise()
{
	int i,j;
	
	FILE *fichier;
	// Ouverture du fichier en écriture grâce à "r"
	fichier = fopen("res/sauvegarde.txt","r");
	
	// Verifier que le fichier a bien été ouvert
	if (fichier != NULL)
	{
		//Lecture
		rewind(fichier);
		
		for(i=0;i<11;i++)
		{
			for(j=0;j<11;j++)
			{
				fscanf(fichier, "%d ", &grille[i][j]);
			}
			//fprintf(fichier, "\n");
		}
		
		fscanf(fichier, "%d", &tourjoueur);
		fscanf(fichier, "%d", &nbdeplacebleu);
		fscanf(fichier, "%d", &nbdeplacerouge);
		fscanf(fichier, "%d", &boulesperduesbleu);
		fscanf(fichier, "%d", &boulesperduesrouge);
		
		// Fermeture du fichier
		fclose(fichier);
	}
	return 0;
}

