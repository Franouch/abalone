#include <stdio.h>
#include <stdlib.h>
#include <string.h>


////Liste des coups et leurs valeurs :
////+1 : éliminer une boule ennemie (3vs2)
////+2 : éliminer une boule ennemie (3vs1 ou 2vs1)
////+3 : éloigner une de mes boules de la bordure immédiate
////+4 : coller une bille seule à une autre ou à un groupe
////+5 : se rapprocher du centre
////+6 : pousser vers la bordure (3vs2 ou 3vs1 ou 2vs1)



////Stratégie :
////pour les 5 premiers tours : rush le centre
////apres stratégie défensive puis offensive

// Strat générale :
// On récupère le rouge le plus bas dans le tableau
// On se déplace en direction des bleus







//Fonctions pour L'IA ROUGE
int recuplignerougebasse(int grille[11][11])
{
	int i,j;
	int trouve = 0;
	
	//on choisit la bille la plus en bas
	for (i=10;i>0;i--)
	{
		for (j=0;j<11;j++)
		{
			if (grille[i][j] == 3) trouve = 1;
		}
		if (trouve==1) break;
	}
	
	return i;
}

int recuplignerougehaute(int grille[11][11])
{
	int i,j;
	int trouve = 0;
	
	//on choisit la bille la plus en haut
	for (i=0;i<11;i++)
	{
		for (j=0;j<11;j++)
		{
			if (grille[i][j] == 3) trouve = 1;
		}
		if (trouve==1) break;
	}
	
	return i;
}



int recupcolrougebasse(int grille[11][11], int lrb)
{
	//lrb = ligne rouge basse
	int j;
	for (j=0;j<11;j++) // on choisit la bille la plus à gauche
	{
		if (grille[lrb][j]==3) break;
	}
	return j;
}

int recupcolrougebassegauche(int grille[11][11], int lrb)
{
	//lrb = ligne rouge basse
	int j;
	for (j=0;j<11;j++) // on choisit la bille la plus à gauche
	{
		if (grille[lrb][j]==3) break;
	}
	return j;
}

int recupcolrougebassedroite(int grille[11][11], int lrb)
{
	//lrb = ligne rouge basse
	int j;
	for (j=11;j>0;j--) // on choisit la bille la plus à droite
	{
		if (grille[lrb][j]==3) break;
	}
	return j;
}
//Fin fonctions pour L'IA ROUGE









//Fonctions pour L'IA BLEUE
//EN HAUT A DROITE
int recuplignebleuehaute(int grille[11][11])
{
	int i,j;
	int trouve = 0;
	
	//on choisit la bille la plus en haut
	for (i=0;i<11;i++)
	{
		for (j=0;j<11;j++)
		{
			if (grille[i][j] == 2) trouve = 1;
		}
		if (trouve==1) break;
	}
	
	return i;
}

int recuplignebleuebasse(int grille[11][11])
{
	int i,j;
	int trouve = 0;
	
	//on choisit la bille la plus en bas
	for (i=10;i>0;i--)
	{
		for (j=0;j<11;j++)
		{
			if (grille[i][j] == 2) trouve = 1;
		}
		if (trouve==1) break;
	}
	
	return i;
}


int recupcolbleuehautedroite(int grille[11][11], int lbh)
{
	//lbh = ligne bleue haute
	int j;
	for (j=11;j>0;j--) // on choisit la bille la plus à droite
	{
		if (grille[lbh][j]==2) break;
	}
	return j;
}
//Fin fonctions pour L'IA BLEUE



//Fonctions pour L'IA BLEUE
//EN HAUT A GAUCHE

int recupcolbleuehautegauche(int grille[11][11], int lbh)
{
	//lbh = ligne bleue haute
	int j;
	for (j=0;j<11;j++) // on choisit la bille la plus à gauche
	{
		if (grille[lbh][j]==2) break;
	}
	return j;
}
//Fin fonctions pour L'IA BLEUE








////int deplace(int grille[11][11], int x1, int y1, int x2, int y2, int x3, int y3, int direction, int nbboule, int senstrain);


///*
//21
//3X4
 //65
//*/

///*
 //Le tableau est le suivant

  //0 0 0 0 0 0 0 0 0 0 0
//I 0 3 3 3 3 3 0 0 0 0 0
//H 0 3 3 3 3 3 3 0 0 0 0
//G 0 1 1 3 3 3 1 1 0 0 0
//F 0 1 1 1 1 1 1 1 1 0 0
//E 0 1 1 1 1 1 1 1 1 1 0
//D 0 0 1 1 1 1 1 1 1 1 9
//C 0 0 0 1 1 2 2 2 1 1 8
//B 0 0 0 0 2 2 2 2 2 2 7
//A 0 0 0 0 0 2 2 2 2 2 6
  //0 0 0 0 0 1 2 3 4 5 6
//*/


//int selectboules(int grille[11][11])
//{
	//int x1, x2, x3;
	//int y1, y2, y3;
	//int temp;
	
	//if(nbboules==1)
	//{
		//if(grille[x1-1][y1]==0)//Si on est collé à la bordure
		//{
			//if(grille[x1+1][y1]==1)//Si la place à l'opposé est libre
			//{	
				//grille[x1+1][y1]=grille[x1][y1]
				//grille[x1][y1]=1;
			//}
			////traiter les autres cas ici, si disponibles
		//}
		//else if(grille[x1-1][y1-1]==0)
		//{
			//if(grille[x1+1][y1+1]==1)
			//{	
				//grille[x1+1][y1+1]=grille[x1][y1];
				//grille[x1][y1]=1;
			//}
		//}
		//else if(grille[x1][y1-1]==0)
		//{
			//if(grille[x1][y1+1]==1)
			//{	
				//grille[x1][y1+1]=grille[x1][y1];
				//grille[x1][y1]=1;
			//}
		//}
		//else if(grille[x1][y1+1]==0)
		//{
			//if(grille[x1][y1-1]==1)
			//{	
				//grille[x1][y1-1]=grille[x1][y1];
				//grille[x1][y1]=1;
			//}
		//}
		//else if(grille[x1+1][y1+1]==0)
		//{
			//if(grille[x1-1][y1-1]==1)
			//{	
				//grille[x1-1][y1-1]=grille[x1][y1];
				//grille[x1][y1]=1;
			//}
		//}
		//else if(grille[x1+1][y1]==0)
		//{
			//if(grille[x1-1][y1]==1)
			//{	
				//grille[x1-1][y1]=grille[x1][y1];
				//grille[x1][y1]=1;
			//}
		//}
	//}
	
	//return 0;
//}


//int choixcoup(int x1, int y1, int x2, int y2, int x3, int y3, int direction, int nbboules, int senstrain)
//{
	//if(nbboules==1)
	//{
		///* if possible coup3
		 //* else coup4
		 //* else coup5
		 //*/
	//}
	//if(nbboules==2)
	//{
		///* if possible coup2
		 //* else coup3
		 //* else coup5
		 //* else coup6
		 //*/
	//}
	//if(nbboules==3)
	//{
		///* if possible coup1
		 //* else coup2
		 //* else coup3
		 //* else coup5
		 //* else coup6
		 //*/
	//}
	
	//return 0;
//}

//int coup1()
//{
	
	
	//return 0;
//}


//int coup2()
//{
	
	
	//return 0;
//}


//int coup3()
//{
	
	
	//return 0;
//}


//int coup4()
//{
	
	
	//return 0;
//}


//int coup5()
//{
	
	
	//return 0;
//}


//int coup6()
//{
	
	
	//return 0;
//}
//*/
