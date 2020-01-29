#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "init.h"
#include "affiche.h"
#include "menu.h"
#include "deplace.h"
#include "outils.h"
#include "intelligence.h"
#include "sauvegardecontexte.h"
#include "global.h"

#define couleur(param) printf("\033[%sm",param)



int main()
{	
	int resterdansmenu=0;
	int selectionmenu;
	int nbboules=0;
	int direction=0;
	int senstrain=0;
	char xc1, xc2, xc3;//Char pour la lecture de la lettre
	int x1, x2, x3;//Ils seront convertis en int
	int yi1, yi2, yi3; // les entiers en entrée, in	
	int y1, y2, y3;// Ils seront convertis en int de la grille
	char s[20];
    char * strretour;
	int saveorquit=0;
	
	int troulibre=0;//Aide l'IA à savoir si un emplcement est disponible
	
	boulesperduesbleu=0;
	boulesperduesrouge=0;
	tourjoueur=0;
	nbdeplacebleu=0;
	nbdeplacerouge=0;
	
	
	
	while(resterdansmenu==0)
	{
		selectionmenu=menu();
		
		if(selectionmenu==1 || selectionmenu==2)
		{
			if(selectionmenu==1)
			{
				initialisegrille(grille);
				nbdeplacebleu=0;
				nbdeplacerouge=0;
				tourjoueur=0;
				saveorquit=0;
				nbboules=0;
				boulesperduesbleu=0;
				boulesperduesrouge=0;
			}
			else 
			{
				reprise();
				saveorquit=0;
				nbboules=0;
			}
			
			while(saveorquit==0)
			{
				
				printf("\n");
				if(tourjoueur%2==0)
				{
					couleur("44");
					printf("C'est aux bleus de jouer");
					couleur("0");
					printf("\n\n");
				}
				else
				{
					couleur("41");
					printf("C'est aux rouges de jouer");
					couleur("0");
					printf("\n\n");
				}

						
				afficheinit(grille);
				
				

				printf("Entrez les coordonnées des boules à déplacer ");
				printf("(separées par \" \" ou \",\" ou \".\" ou \";\")\n>>> ");
				
				
				nbboules=0;
				lire(s, 20);
				strretour = strtok (s," ,.;");
				xc1=toupper(strretour[0]);
				yi1=strretour[1]-48;
				nbboules++;
				strretour = strtok (NULL," ,.;");
				if (strretour != NULL)
				{
					xc2 = toupper(strretour[0]);
					yi2 = strretour[1]-48;
					nbboules++;
				}
				strretour = strtok (NULL," ,.;");
				if (strretour != NULL)
				{
					xc3 = toupper(strretour[0]);
					yi3 = strretour[1]-48;
					nbboules++;
				}
				
				
				printf("\n");
				printf("Entrez une direction de déplacement et un sens de train \n");
				printf("\n");
				printf("   2     1   \n");
				printf("    \\   /    \n");
				printf(" 3-- XXX --4 \n");
				printf("    /   \\    \n");
				printf("   6     5   \n");
				printf("\nDirection >>> ");
				scanf("%d", &direction);
				printf("Sens train >>> ");
				scanf("%d", &senstrain);
				printf("\n");
					   
				
				if(nbboules==1)
				{					
					x1=conversionLettreLigne(xc1);
					y1=conversionPositionColonne(x1, yi1);
					
					x2=y2=x3=y3=0;
				}
				

				if(nbboules==2)
				{
					x1=conversionLettreLigne(xc1);
					y1=conversionPositionColonne(x1, yi1);
										
					x2=conversionLettreLigne(xc2);
					y2=conversionPositionColonne(x2, yi2);
										
					x3=y3=0;
				}
				
				if(nbboules==3)
				{			
					x1=conversionLettreLigne(xc1);
					y1=conversionPositionColonne(x1, yi1);
										
					x2=conversionLettreLigne(xc2);
					y2=conversionPositionColonne(x2, yi2);
					
					x3=conversionLettreLigne(xc3);
					y3=conversionPositionColonne(x3, yi3);
				}
				
				
				deplace(grille, x1, y1, x2, y2, x3, y3, direction, nbboules, senstrain);
				
				afficheinit(grille);
				
				
				//int lrb;
				//lrb=recuplignerougebasse(grille);
				
				//printf("\n *** Dernière ligne rouge = %d *** \n Bille la plus a gauche = %d\n", lrb, recupcolrougebasse(grille, lrb));
				
				
				printf("\n");
				printf("Boules bleues éliminées : ");
				couleur("44");
				printf("%d", boulesperduesbleu);
				couleur("0");
				printf("\n");
				printf("Boules rouges éliminées : ");
				couleur("41");
				printf("%d", boulesperduesrouge);
				couleur("0");
				printf("\n\n");
				
				
				if(tourjoueur%2==0)
				{
					nbdeplacebleu++;
					tourjoueur++;
				}
				else
				{
					nbdeplacerouge++;
					tourjoueur++;
				}
				
				
				if(boulesperduesbleu>=6)
				{
					printf("\n");
					couleur("41");
					printf("VICTOIRE DU JOUEUR ROUGE");
					couleur("0");
					printf(" (%d coups)", nbdeplacerouge);
					printf("\n\n");
					printf("Appuyez sur 1 pour revenir au menu >>> ");
					scanf("%d", &saveorquit);
				}
				else if(boulesperduesrouge>=6)
				{
					printf("\n");
					couleur("44");
					printf("VICTOIRE DU JOUEUR BLEU");
					couleur("0");
					printf(" (%d coups)", nbdeplacebleu);
					printf("\n\n");
					printf("Appuyez sur 1 pour revenir au menu >>> ");
					scanf("%d", &saveorquit);

				}
				else
				{
					printf("Continuer : 0  \nQuitter et retourner au menu : 1  \nSauver la partie et quitter : 2 \n>>> ");
					scanf("%d", &saveorquit);
					
					if(saveorquit==2)
					{
						sauvegarde(grille, tourjoueur, nbdeplacebleu, nbdeplacerouge, boulesperduesbleu, boulesperduesrouge);
						saveorquit=1;
					}
				}
			}
			
		}
		
		
		else if(selectionmenu==3 || selectionmenu==4)
		{
			
			if(selectionmenu==3)
			{
				initialisegrille(grille);
				nbdeplacebleu=0;
				nbdeplacerouge=0;
				tourjoueur=0;
				saveorquit=0;
				nbboules=0;
				boulesperduesbleu=0;
				boulesperduesrouge=0;
			}
			else 
			{
				reprise();
				saveorquit=0;
				nbboules=0;
			}
			
			
			
			while(saveorquit==0)
			{
				
				printf("\n");
				if(tourjoueur%2==0)
				{
					couleur("44");
					printf("C'est aux bleus de jouer");
					couleur("0");
					printf("\n\n");
				}
				else
				{
					printf("    ");
					couleur("41");
					printf("L'IA rouge joue");
					couleur("0");
					printf("\n\n");
				}

						
				afficheinit(grille);
				
				//Le tour du joueur humain (bleu)
				if(tourjoueur%2==0)
				{
					printf("Entrez les coordonnées des boules à déplacer ");
					printf("(separées par \" \" ou \",\" ou \".\" ou \";\")\n>>> ");
					
					
					nbboules=0;
					lire(s, 20);
					strretour = strtok (s," ,.;");
					xc1=toupper(strretour[0]);
					yi1=strretour[1]-48;
					nbboules++;
					strretour = strtok (NULL," ,.;");
					if (strretour != NULL)
					{
						xc2 = toupper(strretour[0]);
						yi2 = strretour[1]-48;
						nbboules++;
					}
					strretour = strtok (NULL," ,.;");
					if (strretour != NULL)
					{
						xc3 = toupper(strretour[0]);
						yi3 = strretour[1]-48;
						nbboules++;
					}
					
					
					printf("\n");
					printf("Entrez une direction de déplacement et un sens de train \n");
					printf("\n");
					printf("   2     1   \n");
					printf("    \\   /    \n");
					printf(" 3-- XXX --4 \n");
					printf("    /   \\    \n");
					printf("   6     5   \n");
					printf("\nDirection >>> ");
					scanf("%d", &direction);
					printf("Sens train >>> ");
					scanf("%d", &senstrain);
					printf("\n");
						   
					
					if(nbboules==1)
					{					
						x1=conversionLettreLigne(xc1);
						y1=conversionPositionColonne(x1, yi1);
						
						x2=y2=x3=y3=0;
					}
					

					if(nbboules==2)
					{
						x1=conversionLettreLigne(xc1);
						y1=conversionPositionColonne(x1, yi1);
											
						x2=conversionLettreLigne(xc2);
						y2=conversionPositionColonne(x2, yi2);
											
						x3=y3=0;
					}
					
					if(nbboules==3)
					{			
						x1=conversionLettreLigne(xc1);
						y1=conversionPositionColonne(x1, yi1);
											
						x2=conversionLettreLigne(xc2);
						y2=conversionPositionColonne(x2, yi2);
						
						x3=conversionLettreLigne(xc3);
						y3=conversionPositionColonne(x3, yi3);
					}
				
				}
				
				else//Ici c'est le tour rouge, donc l'IA joue
				{
					//Choix de la boule principale à déplacer
					//On va toujours jouer la boule la plus en bas, la plus à gauche
					x1=recuplignerougebasse(grille);
					y1=recupcolrougebasse(grille, x1);
					
					troulibre=0;//indication de trou libre dans la direction ou on veut de deplacer
					
					while(!troulibre)
					{
						//On choisit une direction aléatoire
						direction=directionaleatoire();
						
						//Switch pour choisir une direction valide (pas vers une boule rouge)
						switch(direction)
						{
							case 1 :
								
								if(grille[x1-1][y1]!=3)
								{
									troulibre=1;
								}
								break;
							
							case 2 :
								if(grille[x1-1][y1-1]!=3)
								{
									troulibre=1;
								}
								break;
							
							case 3 :
								if(grille[x1][y1-1]!=3)
								{
									troulibre=1;
								}
								break;
								
							case 4 :
								if(grille[x1][y1+1]!=3)
								{
									troulibre=1;
								}
								break;
							
							case 5 :
								if(grille[x1+1][y1+1]!=3)
								{
									troulibre=1;
								}
								break;
								
							case 6 :
								if(grille[x1+1][y1]!=3)
								{
									troulibre=1;
								}
								break;
								
						}
						
					}
					
					
					//On crée un train de 2 ou 3 boules dans le sens opposé de la direction
					//On fait les tests pour savoir quelles sont les boules voisinnes (dans un rayon de 2)
					nbboules=1;
					
					switch(direction)
						{
							case 1 :
								
								if(grille[x1+1][y1]==3)
								{
									x2=x1+1;
									y2=y1;
									nbboules=2;
									
									if(grille[x2+1][y2]==3)
									{
										x3=x2+1;
										y3=y2;
										nbboules=3;
									}
								}
								break;
							
							case 2 :
								if(grille[x1+1][y1+1]==3)
								{
									x2=x1+1;
									y2=y1+1;
									nbboules=2;
									
									if(grille[x2+1][y2+1]==3)
									{
										x3=x2+1;
										y3=y2+1;
										nbboules=3;
									}
								}
								break;
							
							case 3 :
								if(grille[x1][y1+1]==3)
								{
									x2=x1;
									y2=y1+1;
									nbboules=2;
									
									if(grille[x2][y2+1]==3)
									{
										x3=x2;
										y3=y2+1;
										nbboules=3;
									}
								}
								break;
								
							case 4 :
								if(grille[x1][y1-1]==3)
								{
									x2=x1;
									y2=y1-1;
									nbboules=2;
									
									if(grille[x2][y2-1]==3)
									{
										x3=x2;
										y3=y2-1;
										nbboules=3;
									}
								}
								break;
							
							case 5 :
								if(grille[x1-1][y1-1]==3)
								{
									x2=x1-1;
									y2=y1-1;
									nbboules=2;
									
									if(grille[x2-1][y2-1]==3)
									{
										x3=x2-1;
										y3=y2-1;
										nbboules=3;
									}
								}
								break;
								
							case 6 :
								if(grille[x1-1][y1]==3)
								{
									x2=x1-1;
									y2=y1;
									nbboules=2;
									
									if(grille[x2-1][y2]==3)
									{
										x3=x2-1;
										y3=y2;
										nbboules=3;
									}
								}
								break;
								
						}
						
						
						if(nbboules==1)
						{
							x2=y2=x3=y3=0;
						}
						if(nbboules==2)
						{
							x3=y3=0;
						}
						
						senstrain=direction; //On ne se place que dans des cas poussants
						
						//Indication pour savoir ce que joue l'IA
						//printf("L'IA joue : %d %d %d %d %d %d %d %d %d \n", x1, y1, x2, y2, x3, y3, direction, nbboules, senstrain);	
										
						printf("      résultat :\n\n");
				
				}//fin tour IA
				
				
				
				
				
				deplace(grille, x1, y1, x2, y2, x3, y3, direction, nbboules, senstrain);
				
				afficheinit(grille);
				
				
				
				
				
				//printf("\n");
				printf("Boules bleues éliminées : ");
				couleur("44");
				printf("%d", boulesperduesbleu);
				couleur("0");
				printf("\n");
				printf("Boules rouges éliminées : ");
				couleur("41");
				printf("%d", boulesperduesrouge);
				couleur("0");
				printf("\n\n");
				
				
				if(tourjoueur%2==0)
				{
					nbdeplacebleu++;
					tourjoueur++;
				}
				else
				{
					nbdeplacerouge++;
					tourjoueur++;
				}
				
				
				if(boulesperduesbleu>=6)
				{
					printf("\n");
					couleur("41");
					printf("VICTOIRE DU JOUEUR ROUGE");
					couleur("0");
					printf(" (%d coups)", nbdeplacerouge);
					printf("\n\n");
					printf("Appuyez sur 1 pour revenir au menu >>> ");
					scanf("%d", &saveorquit);
				}
				else if(boulesperduesrouge>=6)
				{
					printf("\n");
					couleur("44");
					printf("VICTOIRE DU JOUEUR BLEU");
					couleur("0");
					printf(" (%d coups)", nbdeplacebleu);
					printf("\n\n");
					printf("Appuyez sur 1 pour revenir au menu >>> ");
					scanf("%d", &saveorquit);

				}
				else
				{
					printf("Continuer : 0  ou  Quitter et retourner au menu : 1  ou  Sauver la partie et quitter : 2 \n>>> ");
					scanf("%d", &saveorquit);
					
					if(saveorquit==2)
					{
						sauvegarde(grille, tourjoueur, nbdeplacebleu, nbdeplacerouge, boulesperduesbleu, boulesperduesrouge);
						saveorquit=1;
					}
				}
			}
			
		}
		
		else if(selectionmenu==5)
		{
			//IA vs. IA
			
			
			
			initialisegrille(grille);
			nbdeplacebleu=0;
			nbdeplacerouge=0;
			tourjoueur=0;
			saveorquit=0;
			nbboules=0;
			boulesperduesbleu=0;
			boulesperduesrouge=0;
			
			
			
			while(saveorquit==0)
			{
				
				printf("\n");
				if(tourjoueur%2==0)
				{
					printf("    ");
					couleur("44");
					printf("L'IA bleue joue");
					couleur("0");
					printf("\n\n");
				}
				else
				{
					printf("    ");
					couleur("41");
					printf("L'IA rouge joue");
					couleur("0");
					printf("\n\n");
				}

						
				afficheinit(grille);
				
				
				//TOUR IA BLEUE
				if(tourjoueur%2==0)
				{
					//Choix de la boule principale à déplacer
					if(tourjoueur%4==0)
					{
						//On va toujours jouer la boule la plus en haut, la plus à droite
						x1=recuplignebleuehaute(grille);
						y1=recupcolbleuehautegauche(grille, x1);
					}
					else if(tourjoueur%6==0)
					{
						//On va toujours jouer la boule la plus en haut, la plus à droite
						x1=recuplignebleuebasse(grille);
						y1=recupcolbleuehautegauche(grille, x1);
					}
					else
					{
						//On va toujours jouer la boule la plus en haut, la plus à droite
						x1=recuplignebleuehaute(grille);
						y1=recupcolbleuehautedroite(grille, x1);
					}
					
					troulibre=0;//indication de trou libre dans la direction ou on veut de deplacer
					
					while(!troulibre)
					{
						//On choisit une direction aléatoire
						direction=directionaleatoire();
						
						//Switch pour choisir une direction valide (pas vers une boule rouge)
						switch(direction)
						{
							case 1 :
								
								if(grille[x1-1][y1]!=2)
								{
									troulibre=1;
								}
								break;
							
							case 2 :
								if(grille[x1-1][y1-1]!=2)
								{
									troulibre=1;
								}
								break;
							
							case 3 :
								if(grille[x1][y1-1]!=2)
								{
									troulibre=1;
								}
								break;
								
							case 4 :
								if(grille[x1][y1+1]!=2)
								{
									troulibre=1;
								}
								break;
							
							case 5 :
								if(grille[x1+1][y1+1]!=2)
								{
									troulibre=1;
								}
								break;
								
							case 6 :
								if(grille[x1+1][y1]!=2)
								{
									troulibre=1;
								}
								break;
								
						}
						
					}
					
					
					//On crée un train de 2 ou 3 boules dans le sens opposé de la direction
					//On fait les tests pour savoir quelles sont les boules voisinnes (dans un rayon de 2)
					nbboules=1;
					
					switch(direction)
						{
							case 1 :
								
								if(grille[x1+1][y1]==2)
								{
									x2=x1+1;
									y2=y1;
									nbboules=2;
									
									if(grille[x2+1][y2]==2)
									{
										x3=x2+1;
										y3=y2;
										nbboules=3;
									}
								}
								break;
							
							case 2 :
								if(grille[x1+1][y1+1]==2)
								{
									x2=x1+1;
									y2=y1+1;
									nbboules=2;
									
									if(grille[x2+1][y2+1]==2)
									{
										x3=x2+1;
										y3=y2+1;
										nbboules=3;
									}
								}
								break;
							
							case 3 :
								if(grille[x1][y1+1]==2)
								{
									x2=x1;
									y2=y1+1;
									nbboules=2;
									
									if(grille[x2][y2+1]==2)
									{
										x3=x2;
										y3=y2+1;
										nbboules=3;
									}
								}
								break;
								
							case 4 :
								if(grille[x1][y1-1]==2)
								{
									x2=x1;
									y2=y1-1;
									nbboules=2;
									
									if(grille[x2][y2-1]==2)
									{
										x3=x2;
										y3=y2-1;
										nbboules=3;
									}
								}
								break;
							
							case 5 :
								if(grille[x1-1][y1-1]==2)
								{
									x2=x1-1;
									y2=y1-1;
									nbboules=2;
									
									if(grille[x2-1][y2-1]==2)
									{
										x3=x2-1;
										y3=y2-1;
										nbboules=3;
									}
								}
								break;
								
							case 6 :
								if(grille[x1-1][y1]==2)
								{
									x2=x1-1;
									y2=y1;
									nbboules=2;
									
									if(grille[x2-1][y2]==2)
									{
										x3=x2-1;
										y3=y2;
										nbboules=3;
									}
								}
								break;
								
						}
						
						
						if(nbboules==1)
						{
							x2=y2=x3=y3=0;
						}
						if(nbboules==2)
						{
							x3=y3=0;
						}
						
						senstrain=direction; //On ne se place que dans des cas poussants
						
						//Indication pour savoir ce que joue l'IA
						//printf("L'IA joue : %d %d %d %d %d %d %d %d %d \n", x1, y1, x2, y2, x3, y3, direction, nbboules, senstrain);
									
						printf("      résultat :\n\n");
				
					
					
				}
				
				else//TOUR IA ROUGE
				{
					//Choix de la boule principale à déplacer
					if(tourjoueur%5==0)
					{
						
						x1=recuplignerougehaute(grille);
						y1=recupcolrougebassegauche(grille, x1);
					}
					else if(tourjoueur%3==0)
					{
						
						x1=recuplignerougebasse(grille);
						y1=recupcolrougebassedroite(grille, x1);
					}
					
					else
					{
						//On va toujours jouer la boule la plus en bas, la plus à gauche
						x1=recuplignerougebasse(grille);
						y1=recupcolrougebassegauche(grille, x1);
					}
					
					troulibre=0;//indication de trou libre dans la direction ou on veut de deplacer
					
					while(!troulibre)
					{
						//On choisit une direction aléatoire
						direction=directionaleatoire();
						
						//Switch pour choisir une direction valide (pas vers une boule rouge)
						switch(direction)
						{
							case 1 :
								
								if(grille[x1-1][y1]!=3)
								{
									troulibre=1;
								}
								break;
							
							case 2 :
								if(grille[x1-1][y1-1]!=3)
								{
									troulibre=1;
								}
								break;
							
							case 3 :
								if(grille[x1][y1-1]!=3)
								{
									troulibre=1;
								}
								break;
								
							case 4 :
								if(grille[x1][y1+1]!=3)
								{
									troulibre=1;
								}
								break;
							
							case 5 :
								if(grille[x1+1][y1+1]!=3)
								{
									troulibre=1;
								}
								break;
								
							case 6 :
								if(grille[x1+1][y1]!=3)
								{
									troulibre=1;
								}
								break;
								
						}
						
					}
					
					
					//On crée un train de 2 ou 3 boules dans le sens opposé de la direction
					//On fait les tests pour savoir quelles sont les boules voisinnes (dans un rayon de 2)
					nbboules=1;
					
					switch(direction)
						{
							case 1 :
								
								if(grille[x1+1][y1]==3)
								{
									x2=x1+1;
									y2=y1;
									nbboules=2;
									
									if(grille[x2+1][y2]==3)
									{
										x3=x2+1;
										y3=y2;
										nbboules=3;
									}
								}
								break;
							
							case 2 :
								if(grille[x1+1][y1+1]==3)
								{
									x2=x1+1;
									y2=y1+1;
									nbboules=2;
									
									if(grille[x2+1][y2+1]==3)
									{
										x3=x2+1;
										y3=y2+1;
										nbboules=3;
									}
								}
								break;
							
							case 3 :
								if(grille[x1][y1+1]==3)
								{
									x2=x1;
									y2=y1+1;
									nbboules=2;
									
									if(grille[x2][y2+1]==3)
									{
										x3=x2;
										y3=y2+1;
										nbboules=3;
									}
								}
								break;
								
							case 4 :
								if(grille[x1][y1-1]==3)
								{
									x2=x1;
									y2=y1-1;
									nbboules=2;
									
									if(grille[x2][y2-1]==3)
									{
										x3=x2;
										y3=y2-1;
										nbboules=3;
									}
								}
								break;
							
							case 5 :
								if(grille[x1-1][y1-1]==3)
								{
									x2=x1-1;
									y2=y1-1;
									nbboules=2;
									
									if(grille[x2-1][y2-1]==3)
									{
										x3=x2-1;
										y3=y2-1;
										nbboules=3;
									}
								}
								break;
								
							case 6 :
								if(grille[x1-1][y1]==3)
								{
									x2=x1-1;
									y2=y1;
									nbboules=2;
									
									if(grille[x2-1][y2]==3)
									{
										x3=x2-1;
										y3=y2;
										nbboules=3;
									}
								}
								break;
								
						}
						
						
						if(nbboules==1)
						{
							x2=y2=x3=y3=0;
						}
						if(nbboules==2)
						{
							x3=y3=0;
						}
						
						senstrain=direction; //On ne se place que dans des cas poussants
						
						//Indication pour savoir ce que joue l'IA
						//printf("L'IA joue : %d %d %d %d %d %d %d %d %d \n", x1, y1, x2, y2, x3, y3, direction, nbboules, senstrain);
									
						printf("      résultat :\n\n");
				
				}//fin tour IA
				
				
				
				
				
				deplace(grille, x1, y1, x2, y2, x3, y3, direction, nbboules, senstrain);
				
				afficheinit(grille);
				
				
				
				
				
				//printf("\n");
				printf("Boules bleues éliminées : ");
				couleur("44");
				printf("%d", boulesperduesbleu);
				couleur("0");
				printf("\n");
				printf("Boules rouges éliminées : ");
				couleur("41");
				printf("%d", boulesperduesrouge);
				couleur("0");
				printf("\n\n");
				
				
				if(tourjoueur%2==0)
				{
					nbdeplacebleu++;
					tourjoueur++;
				}
				else
				{
					nbdeplacerouge++;
					tourjoueur++;
				}
				
				
				if(boulesperduesbleu>=6)
				{
					printf("\n");
					couleur("41");
					printf("VICTOIRE DE L'IA ROUGE");
					couleur("0");
					printf(" (%d coups)", nbdeplacerouge);
					printf("\n\n");
					printf("Appuyez sur 1 pour revenir au menu >>> ");
					scanf("%d", &saveorquit);
				}
				else if(boulesperduesrouge>=6)
				{
					printf("\n");
					couleur("44");
					printf("VICTOIRE DE L'IA BLEUE");
					couleur("0");
					printf(" (%d coups)", nbdeplacebleu);
					printf("\n\n");
					printf("Appuyez sur 1 pour revenir au menu >>> ");
					scanf("%d", &saveorquit);

				}
				else
				{
					
					saveorquit=0;
					
					if(tourjoueur>=10000)
					{
						printf("\n\n");
						couleur("7");
						printf("ERREUR : conflit avec l'IA, impossible de terminer la partie");
						couleur("0");
						printf("\n\n");
						printf("Appuyez sur 1 pour revenir au menu >>> ");
						scanf("%d", &saveorquit);
					}
				}
			}
			
			
		}
		
		//IA vs IA en mode pas à pas
		else if(selectionmenu==6)
		{
			//IA vs. IA
			
			
			
			initialisegrille(grille);
			nbdeplacebleu=0;
			nbdeplacerouge=0;
			tourjoueur=0;
			saveorquit=0;
			nbboules=0;
			boulesperduesbleu=0;
			boulesperduesrouge=0;
			
			
			
			while(saveorquit==0)
			{
				
				printf("\n");
				if(tourjoueur%2==0)
				{
					printf("    ");
					couleur("44");
					printf("L'IA bleue joue");
					couleur("0");
					printf("\n\n");
				}
				else
				{
					printf("    ");
					couleur("41");
					printf("L'IA rouge joue");
					couleur("0");
					printf("\n\n");
				}

						
				afficheinit(grille);
				
				
				//TOUR IA BLEUE
				if(tourjoueur%2==0)
				{
					//Choix de la boule principale à déplacer
					if(tourjoueur%4==0)
					{
						//On va toujours jouer la boule la plus en haut, la plus à droite
						x1=recuplignebleuehaute(grille);
						y1=recupcolbleuehautegauche(grille, x1);
					}
					else if(tourjoueur%6==0)
					{
						//On va toujours jouer la boule la plus en haut, la plus à droite
						x1=recuplignebleuebasse(grille);
						y1=recupcolbleuehautegauche(grille, x1);
					}
					else
					{
						//On va toujours jouer la boule la plus en haut, la plus à droite
						x1=recuplignebleuehaute(grille);
						y1=recupcolbleuehautedroite(grille, x1);
					}
					
					troulibre=0;//indication de trou libre dans la direction ou on veut de deplacer
					
					while(!troulibre)
					{
						//On choisit une direction aléatoire
						direction=directionaleatoire();
						
						//Switch pour choisir une direction valide (pas vers une boule rouge)
						switch(direction)
						{
							case 1 :
								
								if(grille[x1-1][y1]!=2)
								{
									troulibre=1;
								}
								break;
							
							case 2 :
								if(grille[x1-1][y1-1]!=2)
								{
									troulibre=1;
								}
								break;
							
							case 3 :
								if(grille[x1][y1-1]!=2)
								{
									troulibre=1;
								}
								break;
								
							case 4 :
								if(grille[x1][y1+1]!=2)
								{
									troulibre=1;
								}
								break;
							
							case 5 :
								if(grille[x1+1][y1+1]!=2)
								{
									troulibre=1;
								}
								break;
								
							case 6 :
								if(grille[x1+1][y1]!=2)
								{
									troulibre=1;
								}
								break;
								
						}
						
					}
					
					
					//On crée un train de 2 ou 3 boules dans le sens opposé de la direction
					//On fait les tests pour savoir quelles sont les boules voisinnes (dans un rayon de 2)
					nbboules=1;
					
					switch(direction)
						{
							case 1 :
								
								if(grille[x1+1][y1]==2)
								{
									x2=x1+1;
									y2=y1;
									nbboules=2;
									
									if(grille[x2+1][y2]==2)
									{
										x3=x2+1;
										y3=y2;
										nbboules=3;
									}
								}
								break;
							
							case 2 :
								if(grille[x1+1][y1+1]==2)
								{
									x2=x1+1;
									y2=y1+1;
									nbboules=2;
									
									if(grille[x2+1][y2+1]==2)
									{
										x3=x2+1;
										y3=y2+1;
										nbboules=3;
									}
								}
								break;
							
							case 3 :
								if(grille[x1][y1+1]==2)
								{
									x2=x1;
									y2=y1+1;
									nbboules=2;
									
									if(grille[x2][y2+1]==2)
									{
										x3=x2;
										y3=y2+1;
										nbboules=3;
									}
								}
								break;
								
							case 4 :
								if(grille[x1][y1-1]==2)
								{
									x2=x1;
									y2=y1-1;
									nbboules=2;
									
									if(grille[x2][y2-1]==2)
									{
										x3=x2;
										y3=y2-1;
										nbboules=3;
									}
								}
								break;
							
							case 5 :
								if(grille[x1-1][y1-1]==2)
								{
									x2=x1-1;
									y2=y1-1;
									nbboules=2;
									
									if(grille[x2-1][y2-1]==2)
									{
										x3=x2-1;
										y3=y2-1;
										nbboules=3;
									}
								}
								break;
								
							case 6 :
								if(grille[x1-1][y1]==2)
								{
									x2=x1-1;
									y2=y1;
									nbboules=2;
									
									if(grille[x2-1][y2]==2)
									{
										x3=x2-1;
										y3=y2;
										nbboules=3;
									}
								}
								break;
								
						}
						
						
						if(nbboules==1)
						{
							x2=y2=x3=y3=0;
						}
						if(nbboules==2)
						{
							x3=y3=0;
						}
						
						senstrain=direction; //On ne se place que dans des cas poussants
						
						//Indication pour savoir ce que joue l'IA
						//printf("L'IA joue : %d %d %d %d %d %d %d %d %d \n", x1, y1, x2, y2, x3, y3, direction, nbboules, senstrain);					
						printf("      résultat :\n\n");
						//printf("         V V V\n");
				
					
					
				}
				
				else//TOUR IA ROUGE
				{
					//Choix de la boule principale à déplacer
					if(tourjoueur%5==0)
					{
						
						x1=recuplignerougehaute(grille);
						y1=recupcolrougebassegauche(grille, x1);
					}
					else if(tourjoueur%3==0)
					{
						
						x1=recuplignerougebasse(grille);
						y1=recupcolrougebassedroite(grille, x1);
					}
					
					else
					{
						//On va toujours jouer la boule la plus en bas, la plus à gauche
						x1=recuplignerougebasse(grille);
						y1=recupcolrougebassegauche(grille, x1);
					}
					
					troulibre=0;//indication de trou libre dans la direction ou on veut de deplacer
					
					while(!troulibre)
					{
						//On choisit une direction aléatoire
						direction=directionaleatoire();
						
						//Switch pour choisir une direction valide (pas vers une boule rouge)
						switch(direction)
						{
							case 1 :
								
								if(grille[x1-1][y1]!=3)
								{
									troulibre=1;
								}
								break;
							
							case 2 :
								if(grille[x1-1][y1-1]!=3)
								{
									troulibre=1;
								}
								break;
							
							case 3 :
								if(grille[x1][y1-1]!=3)
								{
									troulibre=1;
								}
								break;
								
							case 4 :
								if(grille[x1][y1+1]!=3)
								{
									troulibre=1;
								}
								break;
							
							case 5 :
								if(grille[x1+1][y1+1]!=3)
								{
									troulibre=1;
								}
								break;
								
							case 6 :
								if(grille[x1+1][y1]!=3)
								{
									troulibre=1;
								}
								break;
								
						}
						
					}
					
					
					//On crée un train de 2 ou 3 boules dans le sens opposé de la direction
					//On fait les tests pour savoir quelles sont les boules voisinnes (dans un rayon de 2)
					nbboules=1;
					
					switch(direction)
						{
							case 1 :
								
								if(grille[x1+1][y1]==3)
								{
									x2=x1+1;
									y2=y1;
									nbboules=2;
									
									if(grille[x2+1][y2]==3)
									{
										x3=x2+1;
										y3=y2;
										nbboules=3;
									}
								}
								break;
							
							case 2 :
								if(grille[x1+1][y1+1]==3)
								{
									x2=x1+1;
									y2=y1+1;
									nbboules=2;
									
									if(grille[x2+1][y2+1]==3)
									{
										x3=x2+1;
										y3=y2+1;
										nbboules=3;
									}
								}
								break;
							
							case 3 :
								if(grille[x1][y1+1]==3)
								{
									x2=x1;
									y2=y1+1;
									nbboules=2;
									
									if(grille[x2][y2+1]==3)
									{
										x3=x2;
										y3=y2+1;
										nbboules=3;
									}
								}
								break;
								
							case 4 :
								if(grille[x1][y1-1]==3)
								{
									x2=x1;
									y2=y1-1;
									nbboules=2;
									
									if(grille[x2][y2-1]==3)
									{
										x3=x2;
										y3=y2-1;
										nbboules=3;
									}
								}
								break;
							
							case 5 :
								if(grille[x1-1][y1-1]==3)
								{
									x2=x1-1;
									y2=y1-1;
									nbboules=2;
									
									if(grille[x2-1][y2-1]==3)
									{
										x3=x2-1;
										y3=y2-1;
										nbboules=3;
									}
								}
								break;
								
							case 6 :
								if(grille[x1-1][y1]==3)
								{
									x2=x1-1;
									y2=y1;
									nbboules=2;
									
									if(grille[x2-1][y2]==3)
									{
										x3=x2-1;
										y3=y2;
										nbboules=3;
									}
								}
								break;
								
						}
						
						
						if(nbboules==1)
						{
							x2=y2=x3=y3=0;
						}
						if(nbboules==2)
						{
							x3=y3=0;
						}
						
						senstrain=direction; //On ne se place que dans des cas poussants
						
						//Indication pour savoir ce que joue l'IA
						//printf("L'IA joue : %d %d %d %d %d %d %d %d %d \n", x1, y1, x2, y2, x3, y3, direction, nbboules, senstrain);					
						printf("      résultat :\n\n");
						//printf("         V V V\n");
				
				}//fin tour IA
				
				
				
				
				
				deplace(grille, x1, y1, x2, y2, x3, y3, direction, nbboules, senstrain);
				
				afficheinit(grille);
				
				
				
				
				
				//printf("\n");
				printf("Boules bleues éliminées : ");
				couleur("44");
				printf("%d", boulesperduesbleu);
				couleur("0");
				printf("\n");
				printf("Boules rouges éliminées : ");
				couleur("41");
				printf("%d", boulesperduesrouge);
				couleur("0");
				printf("\n\n");
				
				
				if(tourjoueur%2==0)
				{
					nbdeplacebleu++;
					tourjoueur++;
				}
				else
				{
					nbdeplacerouge++;
					tourjoueur++;
				}
				
				
				if(boulesperduesbleu>=6)
				{
					printf("\n");
					couleur("41");
					printf("VICTOIRE DE L'IA ROUGE");
					couleur("0");
					printf(" (%d coups)", nbdeplacerouge);
					printf("\n\n");
					printf("Appuyez sur 1 pour revenir au menu >>> ");
					scanf("%d", &saveorquit);
				}
				else if(boulesperduesrouge>=6)
				{
					printf("\n");
					couleur("44");
					printf("VICTOIRE DE L'IA BLEUE");
					couleur("0");
					printf(" (%d coups)", nbdeplacebleu);
					printf("\n\n");
					printf("Appuyez sur 1 pour revenir au menu >>> ");
					scanf("%d", &saveorquit);

				}
				else
				{
					printf("Continuer : 0  ou  Quitter et retourner au menu : 1 \n>>> ");
					scanf("%d", &saveorquit);
					
					
					if(tourjoueur>=10000)
					{
						printf("\n\n");
						couleur("7");
						printf("ERREUR : conflit avec l'IA, impossible de terminer la partie");
						couleur("0");
						printf("\n\n");
						printf("Appuyez sur 1 pour revenir au menu >>> ");
						scanf("%d", &saveorquit);
					}
				}
			}
			
			
		}
		
		
		else if(selectionmenu==7)
		{
			resterdansmenu=1;
			printf("\nMerci d'avoir joué à ABALONE (c) \n\n");
		}
		
	
	}
	
	
	

	
	return 0;
}
