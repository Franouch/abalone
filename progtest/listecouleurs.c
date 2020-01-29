#include <stdio.h>
#include <stdlib.h>
#define couleur(param) printf("\033[%sm",param)

/*
http://sdz.tdct.org/sdz/des-couleurs-dans-la-console-linux.html
*/

int main()
{
	int i=10;
	char s[2]="";

	

	for(i=0;i<110;i++){
		//comme le printf mis ecrit dans s et pas sur l'ecran
		sprintf(s,"%d",i);
		couleur(s);
		printf("Test couleur %d \n",i);
		couleur("0");
	}
	
	
	
	//couleur("5"); fait clignoter
	
	//test
	couleur("5");
	couleur("44");
	printf("test");
	couleur("0");

	//il est posible de combiner les couleurs
	
	return 0;
}
