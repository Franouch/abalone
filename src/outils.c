#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void viderbuffer()
{
	int c=0;
	while(c!='\n' && c!=EOF)
	c=getchar();
}


//Fonction volée sur internet car trop de problemes pour lire
//et vider le buffer (openclassrooms)

//Fonction qui lit une chaine de caracteres et gere bien le vidage du buffer
int lire(char *chaine, int longueur)
{
	viderbuffer();
    char *positionEntree = NULL;
    // On lit le texte saisi au clavier
    if (fgets(chaine, longueur, stdin) != NULL)  // Pas d'erreur de saisie ?
    {
        positionEntree = strchr(chaine, '\n'); // On recherche l'"Entrée"
        if (positionEntree != NULL) // Si on a trouvé le retour à la ligne
        {
            *positionEntree = '\0'; // On remplace ce caractère par \0
        }
        return 1; // On renvoie 1 si la fonction s'est déroulée sans erreur
    }
    else
    {
        return 0; // On renvoie 0 s'il y a eu une erreur
    }
}


int aleatoireint(int _iMin, int _iMax)
{
	return (_iMin + (rand () % (_iMax-_iMin+1)));
}


int directionaleatoire()
{
	return aleatoireint(1,6);
}

