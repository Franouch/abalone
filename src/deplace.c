#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define couleur(param) printf("\033[%sm",param)

extern int boulesperduesbleu;
extern int boulesperduesrouge;
extern int tourjoueur;
extern int senstrain;

//faire fct deplace avec param : la case d'origine
//et la case de destination

//faire fonction de conversion A1==95
//Pour les nombres a deux chiffres
//95/10 = 9
//95%10 = 5

/*
 Le tableau est le suivant

  0 0 0 0 0 0 0 0 0 0 0
I 0 3 3 3 3 3 0 0 0 0 0
H 0 3 3 3 3 3 3 0 0 0 0
G 0 1 1 3 3 3 1 1 0 0 0
F 0 1 1 1 1 1 1 1 1 0 0
E 0 1 1 1 1 1 1 1 1 1 0
D 0 0 1 1 1 1 1 1 1 1 9
C 0 0 0 1 1 2 2 2 1 1 8
B 0 0 0 0 2 2 2 2 2 2 7
A 0 0 0 0 0 2 2 2 2 2 6
  0 0 0 0 0 1 2 3 4 5 6
*/



//Convertit la lettre entrée en ligne de tableau
int conversionLettreLigne(char Lettre)
{		
	return (9 - (Lettre - 65));
}





//Conversion en position colonne dans le tableau final
//Etant donné que la position en colonne dans le tableau
//dépend de la ligne à laquelle on se trouve
//Attention : on a pas encore vérifié si la case sélectionnée
//est bien un pion et qu'on a le droit de le déplacer
int conversionPositionColonne(int ligne, int colonne)
{
	
	//à remplacer par un switch case si j'ai le temps
	
	
	if(ligne<=0 || ligne>9)
	{
		printf("Erreur d'entrée (mauvaise ligne dans conversionPositionColonne)\n");
		return 0;
	}
	
	//Ligne A
	if(ligne==9)
	{
		if(colonne==1){return 5;}
		if(colonne==2){return 6;}
		if(colonne==3){return 7;}
		if(colonne==4){return 8;}
		if(colonne==5){return 9;}
	}
	
	//Ligne B
	if(ligne==8)
	{
		if(colonne==1){return 4;}
		if(colonne==2){return 5;}
		if(colonne==3){return 6;}
		if(colonne==4){return 7;}
		if(colonne==5){return 8;}
		if(colonne==6){return 9;}
	}
	
	//Ligne C
	if(ligne==7)
	{
		if(colonne==1){return 3;}
		if(colonne==2){return 4;}
		if(colonne==3){return 5;}
		if(colonne==4){return 6;}
		if(colonne==5){return 7;}
		if(colonne==6){return 8;}
		if(colonne==7){return 9;}
	}
	
	//Ligne D
	if(ligne==6)
	{
		if(colonne==1){return 2;}
		if(colonne==2){return 3;}
		if(colonne==3){return 4;}
		if(colonne==4){return 5;}
		if(colonne==5){return 6;}
		if(colonne==6){return 7;}
		if(colonne==7){return 8;}
		if(colonne==8){return 9;}
	}
	
	//Ligne E
	if(ligne==5)
	{
		if(colonne==1){return 1;}
		if(colonne==2){return 2;}
		if(colonne==3){return 3;}
		if(colonne==4){return 4;}
		if(colonne==5){return 5;}
		if(colonne==6){return 6;}
		if(colonne==7){return 7;}
		if(colonne==8){return 8;}
		if(colonne==9){return 9;}
	}
	
	//Ligne F
	if(ligne==4)
	{
		if(colonne==2){return 1;}
		if(colonne==3){return 2;}
		if(colonne==4){return 3;}
		if(colonne==5){return 4;}
		if(colonne==6){return 5;}
		if(colonne==7){return 6;}
		if(colonne==8){return 7;}
		if(colonne==9){return 8;}
	}
	
	//Ligne G
	if(ligne==3)
	{
		if(colonne==3){return 1;}
		if(colonne==4){return 2;}
		if(colonne==5){return 3;}
		if(colonne==6){return 4;}
		if(colonne==7){return 5;}
		if(colonne==8){return 6;}
		if(colonne==9){return 7;}
	}
	
	//Ligne H
	if(ligne==2)
	{
		if(colonne==4){return 1;}
		if(colonne==5){return 2;}
		if(colonne==6){return 3;}
		if(colonne==7){return 4;}
		if(colonne==8){return 5;}
		if(colonne==9){return 6;}
	}
	
	//Ligne I
	if(ligne==1)
	{
		if(colonne==5){return 1;}
		if(colonne==6){return 2;}
		if(colonne==7){return 3;}
		if(colonne==8){return 4;}
		if(colonne==9){return 5;}
	}

	
	return 0;
	
}


int selectionnombreboules()
{
	int nbboule;
	printf("Nombre de boules à déplacer (1, 2 ou 3) : ");
	scanf("%d", &nbboule);
	printf("\n");
	
	if(nbboule<=0 || nbboule>3)
	{
		printf("Erreur, on ne peut déplacer que 3 boules au maximum \n");
		//faire retour au menu
	}
	
	return nbboule;	
}


//non utilisée
/*

int selection()
{
	int nbboule=0;
	
	char lettreboule1;
	int chiffreboule1;
	int x1, y1;
	
	char lettreboule2;
	int chiffreboule2;
	int x2, y2;
	
	char lettreboule3;
	int chiffreboule3;
	int x3, y3;
	
	
	printf("Nombre de boules à déplacer : ");
	scanf("%d", &nbboule);
	printf("\n");
	
	
	if(nbboule<=0 || nbboule>3)
	{
		printf("Erreur ! \n");
		printf("On ne peut déplacer que 3 boules au maximum \n");
		//faire retour au menu
    }
	
	
	if(nbboule==1)
	{
		printf("Coordonées de la boule 1 à déplacer (LETTRE) : ");
		scanf("%s", &lettreboule1);
		
		printf("Coordonées de la boule 1 à déplacer (CHIFFRE) : ");
		scanf("%d", &chiffreboule1);
		
		x1=conversionLettreLigne(lettreboule1);
		y1=conversionPositionColonne(x1, chiffreboule1);
	}
	

    if(nbboule==2)
    {
		printf("Coordonées de la boule 1 à déplacer (LETTRE) : ");
		scanf("%s", &lettreboule1);
		
		printf("Coordonées de la boule 1 à déplacer (CHIFFRE) : ");
		scanf("%d", &chiffreboule1);
		printf("\n");
		
		printf("Coordonées de la boule 2 à déplacer (LETTRE) : ");
		scanf("%s", &lettreboule2);
		
		printf("Coordonées de la boule 2 à déplacer (CHIFFRE) : ");
		scanf("%d", &chiffreboule2);
		printf("\n");
		
		x1=conversionLettreLigne(lettreboule1);
		y1=conversionPositionColonne(x1, chiffreboule1);
		
		x2=conversionLettreLigne(lettreboule2);
		y2=conversionPositionColonne(x2, chiffreboule2);
	}
	
	if(nbboule==3)
    {
		printf("Coordonées de la boule 1 à déplacer (LETTRE) : ");
		scanf("%s", &lettreboule1);
		
		printf("Coordonées de la boule 1 à déplacer (CHIFFRE) : ");
		scanf("%d", &chiffreboule1);
		printf("\n");
		
		printf("Coordonées de la boule 2 à déplacer (LETTRE) : ");
		scanf("%s", &lettreboule2);
		
		printf("Coordonées de la boule 2 à déplacer (CHIFFRE) : ");
		scanf("%d", &chiffreboule2);
		printf("\n");
		
		printf("Coordonées de la boule 3 à déplacer (LETTRE) : ");
		scanf("%s", &lettreboule3);
		
		printf("Coordonées de la boule 3 à déplacer (CHIFFRE) : ");
		scanf("%d", &chiffreboule3);
		printf("\n");
		
		x1=conversionLettreLigne(lettreboule1);
		y1=conversionPositionColonne(x1, chiffreboule1);
		
		x2=conversionLettreLigne(lettreboule2);
		y2=conversionPositionColonne(x2, chiffreboule2);
		
		x3=conversionLettreLigne(lettreboule3);
		y3=conversionPositionColonne(x3, chiffreboule3);
	}
	
	return 0;
}


//Penser à vérifier dans quel sens sont alignées les boules
//Si en ligne verticale ou horizontale
//On ne peut pas pousser si on déplace en horizontal une ligne verticale
//Forcément 1vs1, donc impossible de pousser si y'a des voisins.
//
//    * ->
//   * ->
//  * ->
//

int restriction(int grille[11][11], int x1, int y1, int x2, int y2, int x3, int y3, int direction, int nbboule)
{
	
	return 0;
}


*/


int deplace(int grille[11][11], int x1, int y1, int x2, int y2, int x3, int y3, int direction, int nbboule, int senstrain)
{	
	//Rappeler à qui de jouer (couleur)
	//intégrer la fonction de sélection ici
	//Empêcher au joueur bleu de pouvoir déplacer les boules rouges


/*
 * senstrain peut prendre les valeurs 1-6 ou 2-5 ou 3-4
 * Il correspond respectivement à l'alignement des boules :
 * 1-6 : diagonale haut droite
 * 2-5 : diagonale haut gauche
 * 3-4 : horizontale
*/
	
/* haut droite : 1
 * haut gauche : 2
 * gauche : 3
 * droite : 4
 * bas droite : 5
 * bas gauche : 6
*/


	if(nbboule==1)
	{
		//pour 1 boule
		switch(direction)
		{
			case 1:
				//restrictions de deplacement
				//Suicide interdit pour boule seule, on peut pas aller seul dans une case contenant 0;
				if(grille[x1-1][y1]==1)
				{
					//deplacement
					grille[x1-1][y1]=grille[x1][y1];
					grille[x1][y1]=1;
				}
				else if(grille[x1-1][y1]==0)
				{
					//Suicide interdit
					couleur("5");
					printf("\n   Suicide Interdit !\n");
					couleur("0");
				}
				break;
			
			case 2:
				if(grille[x1-1][y1-1]==1)
				{
					grille[x1-1][y1-1]=grille[x1][y1];
					grille[x1][y1]=1;
				}
				else if(grille[x1-1][y1-1]==0)
				{
					couleur("5");
					printf("\n   Suicide Interdit !\n");
					couleur("0");
				}
				break;
			
			case 3:
				if(grille[x1][y1-1]==1)
				{
					grille[x1][y1-1]=grille[x1][y1];
					grille[x1][y1]=1;
				}
				else if(grille[x1][y1-1]==0)
				{
					couleur("5");
					printf("\n   Suicide Interdit !\n");
					couleur("0");
				}
				break;
			
			case 4:
				if(grille[x1][y1+1]==1)
				{
					grille[x1][y1+1]=grille[x1][y1];
					grille[x1][y1]=1;
				}
				else if(grille[x1][y1+1]==0)
				{
					couleur("5");
					printf("\n   Suicide Interdit !\n");
					couleur("0");
				}
				break;
			
			case 5:
				if(grille[x1+1][y1+1]==1)
				{
					grille[x1+1][y1+1]=grille[x1][y1];
					grille[x1][y1]=1;
				}
				else if(grille[x1+1][y1+1]==0)
				{
					couleur("5");
					printf("\n   Suicide Interdit !\n");
					couleur("0");
				}
				break;
			
			case 6:
				if(grille[x1+1][y1]==1)
				{
					grille[x1+1][y1]=grille[x1][y1];
					grille[x1][y1]=1;
				}
				else if(grille[x1+1][y1]==0)
				{
					couleur("5");
					printf("\n   Suicide Interdit !\n");
					couleur("0");
				}
				break;
			
			default :
				printf("\nErreur de direction (1 boule) \n");
		}
	}
	
	
/* haut droite : 1
 * haut gauche : 2
 * gauche : 3
 * droite : 4
 * bas droite : 5
 * bas gauche : 6
 * 
*
 * senstrain peut prendre les valeurs 1-6 ou 2-5 ou 3-4
 * Il correspond respectivement à l'alignement des boules :
 * 1-6 : diagonale haut droite
 * 2-5 : diagonale haut gauche
 * 3-4 : horizontale
*/
	
	
	if(nbboule==2)
	{
		//pour 2 boules
		switch(direction)
		{
			case 1:
				//sens qui ne peut pas pousser
				if (senstrain==3 || senstrain==4 || senstrain==2 || senstrain==5)
				{
					if(grille[x1-1][y1]==1 && grille[x2-1][y2]==1)
					{
						grille[x1-1][y1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2-1][y2]=grille[x2][y2];
						grille[x2][y2]=1;
					}
				}
				else //on suppose que la premiere boule selectionnee est celle qui débute le train, dans le sens de déplacememnt
				{
					if(grille[x1-1][y1]==1)//si c'est libre on va
					{
						grille[x1-1][y1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2-1][y2]=grille[x2][y2];
						grille[x2][y2]=1;
					}
					else if(grille[x1-1][y1]!=1 && grille[x1-2][y1]==1)//c'est occupé que par 1 boule ennemie
					{
						grille[x1-2][y1]=grille[x1-1][y1];
						
						grille[x1-1][y1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2-1][y2]=grille[x2][y2];
						grille[x2][y2]=1;
					}
					//Quand on pousse une boule et que derrière c'est la bordure
					else if(grille[x1-1][y1]!=1 && grille[x1-2][y1]==0)
					{
						//Si c'est le tour des bleus et qu'il veut bien pousser une boule rouge = ok
						if(tourjoueur%2==0 && grille[x1-1][y1]==3)
						{
							grille[x1-1][y1]=grille[x1][y1];
							grille[x1][y1]=1;
						
							grille[x2-1][y2]=grille[x2][y2];
							grille[x2][y2]=1;
							
							boulesperduesrouge++;
						}
						//Si c'est le tour des rouges et qu'il veut bien pousser une boule bleue = ok
						else if(tourjoueur%2==1 && grille[x1-1][y1]==2)
						{
							grille[x1-1][y1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2-1][y2]=grille[x2][y2];
							grille[x2][y2]=1;
							
							boulesperduesbleu++;
						}
						//Si un bleu veut sortir un bleu et idem pour les rouges
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
					}
				}
				
				break;
			
			case 2:
				//sens qui ne peut pas pousser
				if (senstrain==3 || senstrain==4 || senstrain==1 || senstrain==6)
				{
					if(grille[x1-1][y1-1]==1 && grille[x2-1][y2-1]==1)
					{
						grille[x1-1][y1-1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2-1][y2-1]=grille[x2][y2];
						grille[x2][y2]=1;
					}
				}
				else
				{
					if(grille[x1-1][y1-1]==1)//si c'est libre on va
					{
						grille[x1-1][y1-1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2-1][y2-1]=grille[x2][y2];
						grille[x2][y2]=1;
					}
					else if(grille[x1-1][y1-1]!=1 && grille[x1-2][y1-2]==1)//c'est occupé que par 1 boule ennemie
					{
						grille[x1-2][y1-2]=grille[x1-1][y1-1];
						
						grille[x1-1][y1-1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2-1][y2-1]=grille[x2][y2];
						grille[x2][y2]=1;
					}
					else if(grille[x1-1][y1-1]!=1 && grille[x1-2][y1-2]==0)
					{
						if(tourjoueur%2==0 && grille[x1-1][y1-1]==3)
						{
							grille[x1-1][y1-1]=grille[x1][y1];
							grille[x1][y1]=1;
						
							grille[x2-1][y2-1]=grille[x2][y2];
							grille[x2][y2]=1;
						
							boulesperduesrouge++;
						}
						else if(tourjoueur%2==1 && grille[x1-1][y1-1]==2)
						{
							grille[x1-1][y1-1]=grille[x1][y1];
							grille[x1][y1]=1;
						
							grille[x2-1][y2-1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							boulesperduesbleu++;
						}
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
					}
				}
				
				break;
			
			case 3:
				if (senstrain==1 || senstrain==6 || senstrain==2 || senstrain==5)
				{
					if(grille[x1][y1-1]==1 && grille[x2][y2-1]==1)
					{
						grille[x1][y1-1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2][y2-1]=grille[x2][y2];
						grille[x2][y2]=1;
					}
				}
				else
				{
					if(grille[x1][y1-1]==1)//si c'est libre on va
					{
						grille[x1][y1-1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2][y2-1]=grille[x2][y2];
						grille[x2][y2]=1;
					}
					else if(grille[x1][y1-1]!=1 && grille[x1][y1-2]==1)//c'est occupé que par 1 boule ennemie
					{
						grille[x1][y1-2]=grille[x1][y1-1];
						
						grille[x1][y1-1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2][y2-1]=grille[x2][y2];
						grille[x2][y2]=1;
					}
					else if(grille[x1][y1-1]!=1 && grille[x1][y1-2]==0)
					{
						if(tourjoueur%2==0 && grille[x1][y1-1]==3)
						{
							grille[x1][y1-1]=grille[x1][y1];
							grille[x1][y1]=1;
						
							grille[x2][y2-1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							boulesperduesrouge++;
						}
						else if(tourjoueur%2==1 && grille[x1][y1-1]==2)
						{
							grille[x1][y1-1]=grille[x1][y1];
							grille[x1][y1]=1;
						
							grille[x2][y2-1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							boulesperduesbleu++;
						}
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
					}
				}
				
				break;
			
			case 4:
				if (senstrain==1 || senstrain==6 || senstrain==2 || senstrain==5)
				{
					if(grille[x1][y1+1]==1 && grille[x2][y2+1]==1)
					{
						grille[x1][y1+1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2][y2+1]=grille[x2][y2];
						grille[x2][y2]=1;
					}
				}
				else
				{
					if(grille[x1][y1+1]==1)//si c'est libre on va
					{
						grille[x1][y1+1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2][y2+1]=grille[x2][y2];
						grille[x2][y2]=1;
					}
					else if(grille[x1][y1+1]!=1 && grille[x1][y1+2]==1)//c'est occupé que par 1 boule ennemie
					{
						grille[x1][y1+2]=grille[x1][y1+1];
						
						grille[x1][y1+1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2][y2+1]=grille[x2][y2];
						grille[x2][y2]=1;
					}
					else if(grille[x1][y1+1]!=1 && grille[x1][y1+2]==0)
					{
						if(tourjoueur%2==0 && grille[x1][y1+1]==3)
						{
							grille[x1][y1+1]=grille[x1][y1];
							grille[x1][y1]=1;
						
							grille[x2][y2+1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							boulesperduesrouge++;
						}
						else if(tourjoueur%2==1 && grille[x1][y1+1]==2)
						{
							grille[x1][y1+1]=grille[x1][y1];
							grille[x1][y1]=1;
						
							grille[x2][y2+1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							boulesperduesbleu++;
						}
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
					}
				}
				break;
			
			case 5:
				if (senstrain==3 || senstrain==4 || senstrain==1 || senstrain==6)
				{
					if(grille[x1+1][y1+1]==1 && grille[x2+1][y2+1]==1)
					{
						grille[x1+1][y1+1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2+1][y2+1]=grille[x2][y2];
						grille[x2][y2]=1;
					}
				}
				else
				{
					if(grille[x1+1][y1+1]==1)//si c'est libre on va
					{
						grille[x1+1][y1+1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2+1][y2+1]=grille[x2][y2];
						grille[x2][y2]=1;
					}
					else if(grille[x1+1][y1+1]!=1 && grille[x1+2][y1+2]==1)//c'est occupé que par 1 boule ennemie
					{
						grille[x1+2][y1+2]=grille[x1+1][y1+1];
						
						grille[x1+1][y1+1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2+1][y2+1]=grille[x2][y2];
						grille[x2][y2]=1;
					}
					else if(grille[x1+1][y1+1]!=1 && grille[x1+2][y1+2]==0)
					{
						if(tourjoueur%2==0 && grille[x1+1][y1+1]==3)
						{
							grille[x1+1][y1+1]=grille[x1][y1];
							grille[x1][y1]=1;
						
							grille[x2+1][y2+1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							boulesperduesrouge++;
						}
						else if(tourjoueur%2==1 && grille[x1+1][y1+1]==2)
						{
							grille[x1+1][y1+1]=grille[x1][y1];
							grille[x1][y1]=1;
						
							grille[x2+1][y2+1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							boulesperduesbleu++;
						}
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
					}
				}
				break;
			
			case 6:
				if (senstrain==3 || senstrain==4 || senstrain==2 || senstrain==5)
				{
					if(grille[x1+1][y1]==1 && grille[x2+1][y2]==1)
					{
						grille[x1+1][y1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2+1][y2]=grille[x2][y2];
						grille[x2][y2]=1;
					}
				}
				else //on suppose que la premiere boule selectionnee est celle qui débute le train, dans le sens de déplacememnt
				{
					if(grille[x1+1][y1]==1)//si c'est libre on va
					{
						grille[x1+1][y1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2+1][y2]=grille[x2][y2];
						grille[x2][y2]=1;
					}
					else if(grille[x1+1][y1]!=1 && grille[x1+2][y1]==1)//c'est occupé que par 1 boule ennemie
					{
						grille[x1+2][y1]=grille[x1+1][y1];
						
						grille[x1+1][y1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2+1][y2]=grille[x2][y2];
						grille[x2][y2]=1;
					}
					else if(grille[x1+1][y1]!=1 && grille[x1+2][y1]==0)
					{
						if(tourjoueur%2==0 && grille[x1+1][y1]==3)
						{
							grille[x1+1][y1]=grille[x1][y1];
							grille[x1][y1]=1;
						
							grille[x2+1][y2]=grille[x2][y2];
							grille[x2][y2]=1;
	
							boulesperduesrouge++;
						}
						else if(tourjoueur%2==1 && grille[x1+1][y1]==2)
						{
							grille[x1+1][y1]=grille[x1][y1];
							grille[x1][y1]=1;
						
							grille[x2+1][y2]=grille[x2][y2];
							grille[x2][y2]=1;
							
							boulesperduesbleu++;
						}
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
					}
				}
				break;
			
			default :
				printf("\nErreur de direction (2 boules) \n");
		}
	}
	
	
	
	
	if(nbboule==3)
	{
		//pour 3 boules
		switch(direction)
		{
			case 1:
				//sens qui ne peut pas pousser
				//ici on est dans le sens du train
				if (senstrain==3 || senstrain==4 || senstrain==2 || senstrain==5)
				{
					if(grille[x1-1][y1]==1 && grille[x2-1][y2]==1 && grille[x3-1][y3]==1)
					{
						grille[x1-1][y1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2-1][y2]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3-1][y3]=grille[x3][y3];
						grille[x3][y3]=1;
					}
				}
				else //on suppose que la premiere boule selectionnee est celle qui débute le train, dans le sens de déplacememnt
				{
					//on n'est pas dans le sens du train
					if(grille[x1-1][y1]==1)//si c'est libre on va
					{
						grille[x1-1][y1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2-1][y2]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3-1][y3]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					//c'est occupé que par 1 boule ennemie
					else if(grille[x1-1][y1]!=1 && grille[x1-2][y1]==1)
					{
						grille[x1-2][y1]=grille[x1-1][y1];
						
						grille[x1-1][y1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2-1][y2]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3-1][y3]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					//c'est occupé que par 2 boules ennemies
					else if(grille[x1-1][y1]!=1 && grille[x1-2][y1]!=1 && grille[x1-3][y1]==1)
					{
						grille[x1-3][y1]=grille[x1-2][y1];
						grille[x1-2][y1]=grille[x1-1][y1];
						
						grille[x1-1][y1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2-1][y2]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3-1][y3]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					//Pour marquer un point quand 3 boules en poussent 1
					else if(grille[x1-1][y1]!=1 && grille[x1-2][y1]==0)
					{
						if(tourjoueur%2==0  && grille[x1-1][y1]==3)
						{
							grille[x1-1][y1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2-1][y2]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3-1][y3]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesrouge++;
						}
						else if(tourjoueur%2==1 && grille[x1-1][y1]==2)
						{
							grille[x1-1][y1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2-1][y2]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3-1][y3]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesbleu++;
						}
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
						
					}
					//Pour marquer un point quand 3 boules en poussent 2
					else if(grille[x1-1][y1]!=1 && grille[x1-2][y1]!=1 && grille[x1-3][y1]==0)
					{
						if(tourjoueur%2==0  && grille[x1-1][y1]==3)
						{
							grille[x1-1][y1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2-1][y2]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3-1][y3]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesrouge++;
						}
						else if(tourjoueur%2==1 && grille[x1-1][y1]==2)
						{
							grille[x1-1][y1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2-1][y2]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3-1][y3]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesbleu++;
						}
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
					}
				}
			
						
				break;
			
			case 2:
				//sens qui ne peut pas pousser
				if (senstrain==3 || senstrain==4 || senstrain==1 || senstrain==6)
				{
					if(grille[x1-1][y1-1]==1 && grille[x2-1][y2-1]==1 && grille[x3-1][y3-1]==1)
					{
						grille[x1-1][y1-1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2-1][y2-1]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3-1][y3-1]=grille[x3][y3];
						grille[x3][y3]=1;
					}
				}
				else
				{
					if(grille[x1-1][y1-1]==1)//si c'est libre on va
					{
						grille[x1-1][y1-1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2-1][y2-1]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3-1][y3-1]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					//c'est occupé que par 1 boule ennemie
					else if(grille[x1-1][y1-1]!=1 && grille[x1-2][y1-2]==1)
					{
						grille[x1-2][y1-2]=grille[x1-1][y1-1];
						
						grille[x1-1][y1-1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2-1][y2-1]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3-1][y3-1]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					//c'est occupé que par 2 boules ennemies
					else if(grille[x1-1][y1-1]!=1 && grille[x1-2][y1-2]!=1 && grille[x1-3][y1-3]==1)
					{
						grille[x1-3][y1-3]=grille[x1-2][y1-2];
						grille[x1-2][y1-2]=grille[x1-1][y1-1];
						
						grille[x1-1][y1-1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2-1][y2-1]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3-1][y3-1]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					else if(grille[x1-1][y1-1]!=1 && grille[x1-2][y1-2]==0)
					{
						if(tourjoueur%2==0 && grille[x1-1][y1-1]==3)
						{
							grille[x1-1][y1-1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2-1][y2-1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3-1][y3-1]=grille[x3][y3];
							grille[x3][y3]=1;
						
							boulesperduesrouge++;
						}
						else if(tourjoueur%2==1 && grille[x1-1][y1-1]==2)
						{
							grille[x1-1][y1-1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2-1][y2-1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3-1][y3-1]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesbleu++;
						}
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
					}
					else if(grille[x1-1][y1-1]!=1 && grille[x1-2][y1-2]!=1 && grille[x1-3][y1-3]==0)
					{
						if(tourjoueur%2==0 && grille[x1-1][y1-1]==3)
						{
							grille[x1-1][y1-1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2-1][y2-1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3-1][y3-1]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesrouge++;
						}
						else if(tourjoueur%2==1 && grille[x1-1][y1-1]==2)
						{
							grille[x1-1][y1-1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2-1][y2-1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3-1][y3-1]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesbleu++;
						}
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
					}
				}
				
				
				break;
			
			case 3:
				if (senstrain==1 || senstrain==6 || senstrain==2 || senstrain==5)
				{
					if(grille[x1][y1-1]==1 && grille[x2][y2-1]==1 && grille[x3][y3-1]==1)
					{
						grille[x1][y1-1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2][y2-1]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3][y3-1]=grille[x3][y3];
						grille[x3][y3]=1;
					}
				}
				else
				{
					if(grille[x1][y1-1]==1)//si c'est libre on va
					{
						grille[x1][y1-1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2][y2-1]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3][y3-1]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					//c'est occupé que par 1 boule ennemie
					else if(grille[x1][y1-1]!=1 && grille[x1][y1-2]==1)
					{
						grille[x1][y1-2]=grille[x1][y1-1];
						
						grille[x1][y1-1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2][y2-1]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3][y3-1]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					//c'est occupé que par 2 boules ennemies
					else if(grille[x1][y1-1]!=1 && grille[x1][y1-2]!=1 && grille[x1][y1-3]==1)
					{
						grille[x1][y1-3]=grille[x1][y1-2];
						grille[x1][y1-2]=grille[x1][y1-1];
						
						grille[x1][y1-1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2][y2-1]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3][y3-1]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					else if(grille[x1][y1-1]!=1 && grille[x1][y1-2]==0)
					{
						if(tourjoueur%2==0 && grille[x1][y1-1]==3)
						{
							grille[x1][y1-1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2][y2-1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3][y3-1]=grille[x3][y3];
							grille[x3][y3]=1;
						
							boulesperduesrouge++;
						}
						else if(tourjoueur%2==1 && grille[x1][y1-1]==2)
						{
							grille[x1][y1-1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2][y2-1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3][y3-1]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesbleu++;
						}
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
					}
					else if(grille[x1][y1-1]!=1 && grille[x1][y1-2]!=1 && grille[x1][y1-3]==0)
					{
						if(tourjoueur%2==0 && grille[x1][y1-1]==3)
						{
							grille[x1][y1-1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2][y2-1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3][y3-1]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesrouge++;
						}
						else if(tourjoueur%2==1 && grille[x1][y1-1]==2)
						{
							grille[x1][y1-1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2][y2-1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3][y3-1]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesbleu++;
						}
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
					}
					
				}
				
				
				break;
			
			case 4:
				if (senstrain==1 || senstrain==6 || senstrain==2 || senstrain==5)
				{
					if(grille[x1][y1+1]==1 && grille[x2][y2+1]==1 && grille[x3][y3+1]==1)
					{
						grille[x1][y1+1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2][y2+1]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3][y3+1]=grille[x3][y3];
						grille[x3][y3]=1;
					}
				}
				else
				{
					if(grille[x1][y1+1]==1)//si c'est libre on va
					{
						grille[x1][y1+1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2][y2+1]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3][y3+1]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					//c'est occupé que par 1 boule ennemie
					else if(grille[x1][y1+1]!=1 && grille[x1][y1+2]==1)
					{
						grille[x1][y1+2]=grille[x1][y1+1];
						
						grille[x1][y1+1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2][y2+1]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3][y3+1]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					//c'est occupé que par 2 boules ennemies
					else if(grille[x1][y1+1]!=1 && grille[x1][y1+2]!=1 && grille[x1][y1+3]==1)
					{
						grille[x1][y1+3]=grille[x1][y1+2];
						grille[x1][y1+2]=grille[x1][y1+1];
						
						grille[x1][y1+1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2][y2+1]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3][y3+1]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					
					else if(grille[x1][y1+1]!=1 && grille[x1][y1+2]==0)
					{
						if(tourjoueur%2==0 && grille[x1][y1+1]==3)
						{
							grille[x1][y1+1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2][y2+1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3][y3+1]=grille[x3][y3];
							grille[x3][y3]=1;
						
							boulesperduesrouge++;
						}
						else if(tourjoueur%2==1 && grille[x1][y1+1]==2)
						{
							grille[x1][y1+1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2][y2+1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3][y3+1]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesbleu++;
						}
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
					}
					else if(grille[x1][y1+1]!=1 && grille[x1][y1+2]!=1 && grille[x1][y1+3]==0)
					{
						if(tourjoueur%2==0 && grille[x1][y1+1]==3)
						{
							grille[x1][y1+1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2][y2+1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3][y3+1]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesrouge++;
						}
						else if(tourjoueur%2==1 && grille[x1][y1+1]==2)
						{
							grille[x1][y1+1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2][y2+1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3][y3+1]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesbleu++;
						}
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
					}
					
				}
				
				break;
			
			case 5:
				if (senstrain==3 || senstrain==4 || senstrain==1 || senstrain==6)
				{
					if(grille[x1+1][y1+1]==1 && grille[x2+1][y2+1]==1 && grille[x3+1][y3+1]==1)
					{
						grille[x1+1][y1+1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2+1][y2+1]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3+1][y3+1]=grille[x3][y3];
						grille[x3][y3]=1;
					}
				}
				else
				{
					if(grille[x1+1][y1+1]==1)//si c'est libre on va
					{
						grille[x1+1][y1+1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2+1][y2+1]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3+1][y3+1]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					//c'est occupé que par 1 boule ennemie
					else if(grille[x1+1][y1+1]!=1 && grille[x1+2][y1+2]==1)
					{
						grille[x1+2][y1+2]=grille[x1+1][y1+1];
						
						grille[x1+1][y1+1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2+1][y2+1]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3+1][y3+1]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					//c'est occupé que par 2 boules ennemies
					else if(grille[x1+1][y1+1]!=1 && grille[x1+2][y1+2]!=1 && grille[x1+3][y1+3]==1)
					{
						grille[x1+3][y1+3]=grille[x1+2][y1+2];
						grille[x1+2][y1+2]=grille[x1+1][y1+1];
						
						grille[x1+1][y1+1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2+1][y2+1]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3+1][y3+1]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					
					//
					else if(grille[x1+1][y1+1]!=1 && grille[x1+2][y1+2]==0)
					{
						if(tourjoueur%2==0 && grille[x1+1][y1+1]==3)
						{
							grille[x1+1][y1+1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2+1][y2+1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3+1][y3+1]=grille[x3][y3];
							grille[x3][y3]=1;
						
							boulesperduesrouge++;
						}
						else if(tourjoueur%2==1 && grille[x1+1][y1+1]==2)
						{
							grille[x1+1][y1+1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2+1][y2+1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3+1][y3+1]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesbleu++;
						}
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
					}
					else if(grille[x1+1][y1+1]!=1 && grille[x1+2][y1+2]!=1 && grille[x1+3][y1+3]==0)
					{
						if(tourjoueur%2==0 && grille[x1+1][y1+1]==3)
						{
							grille[x1+1][y1+1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2+1][y2+1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3+1][y3+1]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesrouge++;
						}
						else if(tourjoueur%2==1 && grille[x1+1][y1+1]==2)
						{
							grille[x1+1][y1+1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2+1][y2+1]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3+1][y3+1]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesbleu++;
						}
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
					}
				}
				
				
				
				break;
			
			case 6:
				if (senstrain==3 || senstrain==4 || senstrain==2 || senstrain==5)
				{
					if(grille[x1+1][y1]==1 && grille[x2+1][y2]==1 && grille[x3+1][y3]==1)
					{
						grille[x1+1][y1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2+1][y2]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3+1][y3]=grille[x3][y3];
						grille[x3][y3]=1;
					}
				}
				else //on suppose que la premiere boule selectionnee est celle qui débute le train, dans le sens de déplacememnt
				{
					if(grille[x1+1][y1]==1)//si c'est libre on va
					{
						grille[x1+1][y1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2+1][y2]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3+1][y3]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					//c'est occupé que par 1 boule ennemie
					else if(grille[x1+1][y1]!=1 && grille[x1+2][y1]==1)
					{
						grille[x1+2][y1]=grille[x1+1][y1];
						
						grille[x1+1][y1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2+1][y2]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3+1][y3]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					//c'est occupé que par 2 boules ennemies
					else if(grille[x1+1][y1]!=1 && grille[x1+2][y1]!=1 && grille[x1+3][y1]==1)
					{
						grille[x1+3][y1]=grille[x1+2][y1];
						grille[x1+2][y1]=grille[x1+1][y1];
						
						grille[x1+1][y1]=grille[x1][y1];
						grille[x1][y1]=1;
						
						grille[x2+1][y2]=grille[x2][y2];
						grille[x2][y2]=1;
						
						grille[x3+1][y3]=grille[x3][y3];
						grille[x3][y3]=1;
					}
					//
					//Pour marquer un point quand 3 boules en poussent 1
					else if(grille[x1+1][y1]!=1 && grille[x1+2][y1]==0)
					{
						if(tourjoueur%2==0 && grille[x1+1][y1]==3)
						{
							grille[x1+1][y1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2+1][y2]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3+1][y3]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesrouge++;
						}
						else if(tourjoueur%2==1 && grille[x1+1][y1]==2)
						{
							grille[x1+1][y1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2+1][y2]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3+1][y3]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesbleu++;
						}
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
					}
					//Pour marquer un point quand 3 boules en poussent 2
					else if(grille[x1+1][y1]!=1 && grille[x1+2][y1]!=1 && grille[x1+3][y1]==0)
					{
						if(tourjoueur%2==0 && grille[x1+1][y1]==3)
						{
							grille[x1+1][y1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2+1][y2]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3+1][y3]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesrouge++;
						}
						else if(tourjoueur%2==1 && grille[x1+1][y1]==2)
						{
							grille[x1+1][y1]=grille[x1][y1];
							grille[x1][y1]=1;
							
							grille[x2+1][y2]=grille[x2][y2];
							grille[x2][y2]=1;
							
							grille[x3+1][y3]=grille[x3][y3];
							grille[x3][y3]=1;
							
							boulesperduesbleu++;
						}
						else
						{
							couleur("5");
							printf("\n Déplacement impossible !\n");
							couleur("0");
							printf("Vous avez perdu votre tour\n Il fallait réfléchir\n");
						}
					}
				}
				
				
				break;
			
			default :
				printf("\nErreur de direction (3 boules) \n");
		}
	}

	
	
	
	return 0;
	
}
