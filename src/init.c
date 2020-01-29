//Dans cette fonction on ne fait que remplir la grille
//avec 0, 1, 2 et 3, on n'affiche rien.
// donc pas besoin de la modifier pour afficher des trucs
//supplémentaires à l'écran

void initialisegrille(int grille[11][11])
{

/*

00000000000
03333300000
03333330000
01133311000
01111111100
01111111110
00111111110
00011222110
00002222220
00000222220
00000000000

*/

	int i = 0;
	int j = 0;
	
	//remplissage grille avec des 0
	for(i=0; i<11; i++){
		for(j=0;j<11;j++){
			
			grille[i][j]=0;
			
		}
	}
	
	
	
	//remplissage grille
	for(i=0;i<11;i++){
		for(j=0;j<11;j++){
			
			//ligne 1
			if(i==1 && j>0 && j<6){grille[i][j]=3;}
			
			//ligne 2
			if(i==2 && j>0 && j<7){grille[i][j]=3;}
			
			//ligne 3
			if(i==3 && j>0 && j<3){grille[i][j]=1;}
			if(i==3 && j>2 && j<6){grille[i][j]=3;}
			if(i==3 && j>5 && j<8){grille[i][j]=1;}
			
			//ligne 4
			if(i==4 && j>0 && j<9){grille[i][j]=1;}
			
			//ligne 5
			if(i==5 && j>0 && j<10){grille[i][j]=1;}
			
			//ligne 6
			if(i==6 && j>1 && j<10){grille[i][j]=1;}
			
			//ligne 7
			if(i==7 && j>2 && j<5){grille[i][j]=1;}
			if(i==7 && j>4 && j<8){grille[i][j]=2;}
			if(i==7 && j>7 && j<10){grille[i][j]=1;}
			
			//ligne 8
			if(i==8 && j>3 && j<10){grille[i][j]=2;}
			
			//ligne 9
			if(i==9 && j>4 && j<10){grille[i][j]=2;}
			
			
		}
	}
	//Pour faire un test
	//grille[5][5]=3;
}




void initialisegrillediag(int grille[11][11])
{
	/*

0000000
0333330
03333330
011333110
0111111110
01111111110
0111111110
011222110
02222220
0222220
0000000

*/

	int i = 0;
	int j = 0;
	
	//remplissage grille avec des 0
	for(i=0; i<11; i++){
		for(j=0;j<11;j++){
			
			if(j==0 && i<6){grille[i][j]=0;}
			if(j==1 && i<7){grille[i][j]=0;}
			if(j==2 && i<8){grille[i][j]=0;}
			if(j==3 && i<9){grille[i][j]=0;}
			if(j==4 && i<10){grille[i][j]=0;}
			if(j==6 && i<2){grille[i][j]=0;}
			if(j==7 && i<3){grille[i][j]=0;}
			if(j==8 && i<4){grille[i][j]=0;}
			if(j==9 && i<5){grille[i][j]=0;}
		}
		
	}
	
	//remplissage grille
	for(i=0;i<11;i++){
		for(j=0;j<11;j++){
			
			//ligne 1
			if(i==1 && j>0 && j<6){grille[i][j]=3;}
			
			//ligne 2
			if(i==2 && j>0 && j<7){grille[i][j]=3;}
			
			//ligne 3
			if(i==3 && j>0 && j<3){grille[i][j]=1;}
			if(i==3 && j>2 && j<6){grille[i][j]=3;}
			if(i==3 && j>5 && j<8){grille[i][j]=1;}
			
			//ligne 4
			if(i==4 && j>0 && j<9){grille[i][j]=1;}
			
			//ligne 5
			if(i==5 && j>0 && j<10){grille[i][j]=1;}
			
			//ligne 6
			if(i==6 && j>1 && j<10){grille[i][j]=1;}
			
			//ligne 7
			if(i==7 && j>2 && j<5){grille[i][j]=1;}
			if(i==7 && j>4 && j<8){grille[i][j]=2;}
			if(i==7 && j>7 && j<10){grille[i][j]=1;}
			
			//ligne 8
			if(i==8 && j>3 && j<10){grille[i][j]=2;}
			
			//ligne 9
			if(i==9 && j>4 && j<10){grille[i][j]=2;}
			
		}
	}
}
