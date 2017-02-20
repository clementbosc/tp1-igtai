#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "limace.h"


int main()
{
	Image imageSource, ImRes;
	int i, j, NbLig,NbCol;
	unsigned char **I1,**IRes;

	imageSource = ImRead("gray_platypus.pgm");

	/*Si erreur lecture image*/
	if (imageSource == NULL) return 1;

	NbLig=ImNbRow(imageSource); 
	NbCol=ImNbCol(imageSource);

	I1=ImGetI(imageSource);

	ImRes=ImAlloc(BitMap,NbLig,NbCol); /* creation de l’image resultat */
	IRes=ImGetI(ImRes); /* recuperation d’un acces aux pixels de ImRes */

	for (i=0;i<NbLig;i++){
		for (j=0;j<NbCol;j++){
			if(I1[i][j] < 128){
				IRes[i][j] = 0;
			}else{
				IRes[i][j] = 1;
			}
  		}
	}


	ImWrite(ImRes,"bw_platypus.pbm"); /* ecriture de l’image resultat dans eiloj.pgm */
	ImFree(&imageSource); ImFree(&ImRes); /* liberation memoire (voir ci -dessous) */

	return 0;
}

