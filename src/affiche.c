#include <stdio.h>
#include <stdlib.h>
#define couleur(param) printf("\033[%sm",param)





void affichesimple(int grille[11][11])
{
	int i = 0;
	int j = 0;
	
		//affichage grille version legere
		printf("\n");
		for(i=0;i<11;i++){
			for(j=0;j<11;j++){
				
				if(grille[i][j]==0){
					//printf("  ");
					couleur("40");
					printf("%3d", grille[i][j]);
					couleur("0");
				}
				
				if(grille[i][j]==1){
					printf("  ");
					couleur("0");
					printf("%d", grille[i][j]);
					couleur("0");
				}
				
				if(grille[i][j]==2){
					printf("  ");
					couleur("44");
					printf("%d", grille[i][j]);
					couleur("0");
				}
				
				if(grille[i][j]==3){
					printf("  ");
					couleur("41");
					printf("%d", grille[i][j]);
					couleur("0");
				}
				
			}
			printf("\n");
		}
		printf("\n");
		
		couleur("0");
	
}



void affiche(int grille[11][11])
{		
	int i = 0;
	int j = 0;
		
		//affichage grille normale
		//avec coordonnées sur le côté et en bas
		printf("\n");
		for(i=0;i<11;i++){
			
			if(i==0){printf("   ");}
			if(i==1){printf(" I ");}
			if(i==2){printf(" H ");}
			if(i==3){printf(" G ");}
			if(i==4){printf(" F ");}
			if(i==5){printf(" E ");}
			if(i==6){printf(" D ");}
			if(i==7){printf(" C ");}
			if(i==8){printf(" B ");}
			if(i==9){printf(" A ");}
			if(i==10){printf("   ");}

			for(j=0;j<11;j++){
				
				if(grille[i][j]==0){
					couleur("40");
					printf("%2d ", grille[i][j]);
					couleur("0");
				}
				
				if(grille[i][j]==1){
					couleur("0");
					printf("%2d ", grille[i][j]);
					couleur("0");
				}
				
				if(grille[i][j]==2){
					couleur("44");
					printf("%2d ", grille[i][j]);
					couleur("0");
				}
				
				if(grille[i][j]==3){
					couleur("41");
					printf("%2d ", grille[i][j]);
					couleur("0");
				}
				
					
			}
			printf("\n");
		}
		//printf("\n");
		
		couleur("0");

		printf("       1  2  3  4  5  6  7  8  9    ");
		printf("\n");

		
}


void affichediag(int grille[11][11])
{		
	int i = 0;
	int j = 0;
		
		//affichage grille normale
		//avec coordonnées sur le côté et en bas
		printf("\n");
		for(i=0;i<11;i++){
			
			if(i==0){printf("                  ");}
			if(i==1){printf("             I ");}
			if(i==2){printf("          H ");}
			if(i==3){printf("       G ");}
			if(i==4){printf("    F ");}
			if(i==5){printf(" E ");}
			if(i==6){printf("    D ");}
			if(i==7){printf("       C ");}
			if(i==8){printf("          B ");}
			if(i==9){printf("             A ");}
			if(i==10){printf("                  ");}

			for(j=0;j<11;j++){
				
				if(grille[i][j]==0){
					couleur("40");
					printf("%2d ", grille[i][j]);
					couleur("0");
				}
				
				if(grille[i][j]==1){
					couleur("0");
					printf("%2d ", grille[i][j]);
					couleur("0");
				}
				
				if(grille[i][j]==2){
					couleur("44");
					printf("%2d ", grille[i][j]);
					couleur("0");
				}
				
				if(grille[i][j]==3){
					couleur("41");
					printf("%2d ", grille[i][j]);
					couleur("0");
				}
				
					
			}
			printf("\n");
		}
		//printf("\n");
		
		couleur("0");

		printf("       1  2  3  4  5  6  7  8  9    ");
		printf("\n");


/*		
		if(j==0){printf("   ");}
		if(j==1){printf(" I ");}
		if(j==2){printf(" H ");}
		if(j==3){printf(" G ");}
		if(j==4){printf(" F ");}
		if(j==5){printf(" E ");}
		if(j==6){printf(" D ");}
		if(j==7){printf(" C ");}
		if(j==8){printf(" B ");}
		if(j==9){printf(" A ");}
		if(j==10){printf("   ");}
*/
		
}








void afficheinit(int grille[11][11])
{
	int i = 0;
	int j = 0;
	
	while(i<10){	

//ligne 0
			if(i==0){
				j=1;
				printf("     ");
				couleur("40");
				printf("            ");
				couleur("0");
				printf("\n");
			}


//ligne 1
			if(i==1){
				j=1;
				printf("    ");
				couleur("40");
				printf(" I");
				couleur("0");
				while(j<6){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf("  ");
				couleur("0");
				printf("\n");
				
			}
			

//ligne 2
			if(i==2){
				j=1;
				printf("   ");
				couleur("40");
				printf(" H");
				couleur("0");
				while(j<7){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf("  ");
				couleur("0");
				printf("\n");
			}
			

//ligne 3
			if(i==3){
				j=1;
				printf("  ");
				couleur("40");
				printf(" G");
				couleur("0");
				while(j<8){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf("  ");
				couleur("0");
				printf("\n");
			}
			

//ligne 4
			if(i==4){
				j=1;
				printf(" ");
				couleur("40");
				printf(" F");
				couleur("0");
				while(j<9){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf("  ");
				couleur("0");
				printf("\n");
			}


//ligne 5
			if(i==5){
				j=1;
				couleur("40");
				printf(" E");
				couleur("0");
				while(j<10){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf("  ");
				couleur("0");
				printf("\n");
			}


//ligne 6
			if(i==6){
				printf(" ");
				couleur("40");
				printf(" D");
				couleur("0");
				j=2;
				while(j<10){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf(" 9");
				couleur("0");
				printf("\n");
			}


//ligne 7
			if(i==7){
				printf("  ");
				couleur("40");
				printf(" C");
				couleur("0");
				j=3;
				while(j<10){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf(" 8");
				couleur("0");
				printf("\n");
			}
			

//ligne 8
			if(i==8){
				printf("   ");
				couleur("40");
				printf(" B");
				couleur("0");
				j=4;
				while(j<10){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf(" 7");
				couleur("0");
				printf("\n");
			}


//ligne 9
			if(i==9){
				printf("    ");
				couleur("40");
				printf(" A");
				couleur("0");
				j=5;
				while(j<10){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf(" 6");
				couleur("0");
				printf("\n");
			}


		i=i+1;
	
	}

	printf("      ");
	couleur("40");
	printf("  1 2 3 4 5");
	couleur("0");
	printf("\n");
	printf("\n");


}


























void affichedeplace(int grille[11][11])
{

	
	int i = 0;
	int j = 0;
	

	while(i<10){
		
		

//ligne 0
			if(i==0){
				j=1;
				printf("     ");
				couleur("40");
				printf("            ");
				couleur("0");
				printf("\n");
			}


//ligne 1
			if(i==1){
				j=1;
				printf("    ");
				couleur("40");
				printf(" I");
				couleur("0");
				while(j<6){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf("  ");
				couleur("0");
				printf("\n");
				
			}
			

//ligne 2
			if(i==2){
				j=1;
				printf("   ");
				couleur("40");
				printf(" H");
				couleur("0");
				while(j<7){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf("  ");
				couleur("0");
				printf("\n");
			}
			

//ligne 3
			if(i==3){
				j=1;
				printf("  ");
				couleur("40");
				printf(" G");
				couleur("0");
				while(j<8){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf("  ");
				couleur("0");
				printf("\n");
			}
			

//ligne 4
			if(i==4){
				j=1;
				printf(" ");
				couleur("40");
				printf(" F");
				couleur("0");
				while(j<9){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf("  ");
				couleur("0");
				printf("\n");
			}


//ligne 5
			if(i==5){
				j=1;
				couleur("40");
				printf(" E");
				couleur("0");
				while(j<10){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf("  ");
				couleur("0");
				printf("\n");
			}


//ligne 6
			if(i==6){
				printf(" ");
				couleur("40");
				printf(" D");
				couleur("0");
				j=2;
				while(j<10){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf(" 9");
				couleur("0");
				printf("\n");
			}


//ligne 7
			if(i==7){
				printf("  ");
				couleur("40");
				printf(" C");
				couleur("0");
				j=3;
				while(j<10){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf(" 8");
				couleur("0");
				printf("\n");
			}
			

//ligne 8
			if(i==8){
				printf("   ");
				couleur("40");
				printf(" B");
				couleur("0");
				j=4;
				while(j<10){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf(" 7");
				couleur("0");
				printf("\n");
			}


//ligne 9
			if(i==9){
				printf("    ");
				couleur("40");
				printf(" A");
				couleur("0");
				j=5;
				while(j<10){
					if(grille[i][j]==1){
						couleur("0");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					
					if(grille[i][j]==2){
						couleur("44");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
				
					if(grille[i][j]==3){
						couleur("41");
						printf("%2d", grille[i][j]);
						couleur("0");
					}
					j=j+1;
				}
				couleur("40");
				printf(" 6");
				couleur("0");
				printf("\n");
			}


		i=i+1;
	
	}

	printf("      ");
	couleur("40");
	printf("  1 2 3 4 5");
	couleur("0");
	printf("\n");
	printf("\n");




//il va falloir intégrer la valeur clignotante à la fonction
//d'affichage, et pas uniquement le mettre à la fin

/*
param : grille, case select et deplacement
	
	//test
	if(val==95)
	{
		couleur("5");
		printf("%2d" , grille[9][5]);
		couleur("0");
		printf("\n");
	}
	//fin test

*/


}






















