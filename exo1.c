#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "limace.h"


int main()
{
	Image imageSource, ImRes;
	int i, j, NbLig,NbCol;
	unsigned char **R, **G, **B ,**IRes;

	imageSource = ImRead("platypus.ppm");

	/*Si erreur lecture image*/
	if (imageSource == NULL) return 1;

	NbLig=ImNbRow(imageSource); 
	NbCol=ImNbCol(imageSource);
	R=ImGetR(imageSource);
	G=ImGetG(imageSource);
	B=ImGetB(imageSource);

	ImRes=ImAlloc(GrayLevel,NbLig,NbCol); /* creation de l’image resultat */
	IRes=ImGetI(ImRes); /* recuperation d’un acces aux pixels de ImRes */

	for (i=0;i<NbLig;i++){
		for (j=0;j<NbCol;j++){
			IRes[i][j] = round((R[i][j]+G[i][j]+B[i][j])/3);
  		}
	}


	ImWrite(ImRes,"gray_platypus.pgm"); /* ecriture de l’image resultat dans eiloj.pgm */
	ImFree(&imageSource); ImFree(&ImRes); /* liberation memoire (voir ci -dessous) */

	return 0;
}

