#include <stdio.h>
#include <stdlib.h>
#include "limace.h"


int main()
{
	Image imageSource, ImRes;
	int i,j, NbLig,NbCol;

	unsigned char **R, **G, **B, **IResR, **IResB, **IResG;

	Matrix MatR, MatG, MatB; /* declare la matrice Mat */
	int **Mr, **Mg, **Mb; /* declare un acces aux éléments d’une matrice de int */



	imageSource = ImRead("platypus.ppm");

	/*Si erreur lecture image*/
	if (imageSource == NULL) return 1;

	NbLig=ImNbRow(imageSource); 
	NbCol=ImNbCol(imageSource);


	R=ImGetR(imageSource);
	G=ImGetG(imageSource);
	B=ImGetB(imageSource);


	MatR=MatAlloc(Int,1,256);
	MatG=MatAlloc(Int,1,256);
	MatB=MatAlloc(Int,1,256);

	Mr=MatGetInt(MatR);
	Mg=MatGetInt(MatG);
	Mb=MatGetInt(MatB);

	for (i=0;i<256;i++){
		Mr[0][i] = 0;
  	}
  	for (i=0;i<256;i++){
		Mg[0][i] = 0;
  	}
  	for (i=0;i<256;i++){
		Mb[0][i] = 0;
  	}

	for (i=0;i<NbLig;i++){
		for (j=0;j<NbCol;j++){
			Mr[0][R[i][j]]++;
			Mg[0][G[i][j]]++;
			Mb[0][B[i][j]]++;
	  	}
	}
  

	MatWriteAsc(MatR, "");
	MatWriteAsc(MatG, "");
	MatWriteAsc(MatB, "");

	ImRes=ImAlloc(Color,NbLig,NbCol); /* creation de l’image resultat */
	IResR=ImGetR(ImRes);
	IResG=ImGetG(ImRes);
	IResB=ImGetB(ImRes);

	for (i=0;i<NbLig;i++){
		for (j=0;j<NbCol;j++){
			if(R[i][j] < 128){
				IResR[i][j] = 0;
			}else{
				IResR[i][j] = 255;
			}
			if(G[i][j] < 128){
				IResG[i][j] = 0;
			}else{
				IResG[i][j] = 255;
			}
			if(B[i][j] < 128){
				IResB[i][j] = 0;
			}else{
				IResB[i][j] = 255;
			}
  		}
	}



	ImWrite(ImRes,"lsd_platypus.ppm");


	ImFree(&imageSource); ImFree(&ImRes);
	MatFree(&MatR); MatFree(&MatG); MatFree(&MatB);

	return 0;
}

