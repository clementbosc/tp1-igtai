#include <stdio.h>
#include <stdlib.h>
#include "limace.h"


int main()
{
	Image imageSource, ImRes;
	int i,j, NbLig,NbCol;

	unsigned char **I1,**IRes;

	Matrix Mat; /* declare la matrice Mat */
	int **M; /* declare un acces aux éléments d’une matrice de int */



	imageSource = ImRead("gray_platypus.pgm");

	/*Si erreur lecture image*/
	if (imageSource == NULL) return 1;

	NbLig=ImNbRow(imageSource); 
	NbCol=ImNbCol(imageSource);


	I1=ImGetI(imageSource);


	Mat=MatAlloc(Int,1,256); /* cree une matrice de int comportant */
	                         /* 1 lignes et 256 colonnes           */

	M=MatGetInt(Mat); /* recupere l’acces aux elements de la matrice de int */

	for (i=0;i<256;i++){
		M[0][i] = 0;
  	}

	for (i=0;i<NbLig;i++){
		for (j=0;j<NbCol;j++){
			M[0][I1[i][j]]++;
	  	}
	}


	for (j=0;j<256;j++){
		printf("%d : %d\n", j, M[0][j]);
  	}

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

	/*MatWriteAsc(Mat, "");*/

	ImWrite(ImRes,"bw_platypus2.pbm"); /* ecriture de l’image resultat dans eiloj.pgm */

	ImFree(&imageSource); ImFree(&ImRes);
	MatFree(&Mat);

	return 0;
}

