# Informatique graphique, traitement et analyse d'images
## TP1 - Bases du traitement et de l'analyse d'images

En utilisant la bibliothèque LIMACE, écrivez un programme C que vous compléterez au fur et à mesure des exercices décrits ci-dessous.

![platypus.ppm](https://ups.clementbosc.fr/tp1-igtai/platypus.jpg)

### Exercice 1 - De 16 777 216 couleurs à 256 niveaux de gris

À partir de l'image couleur `platypus.ppm` créez une nouvelle image, en niveau de gris, `gray_platypus.pgm`.
Le calcul du niveau de gris I d'un pixel à partir de ses composantes rouge R, verte G et bleue B peut être obtenu de la manière suivante :
I = [(R+G+B)/3] où \[ x \] est l’entier le plus proche de x.

![gray_platypus.pgm](https://ups.clementbosc.fr/tp1-igtai/gray_platypus.jpg)

### Exercice 2 - De 256 niveaux de gris à 2 niveaux de gris : binarisation par seuillage global

À partir de l'image en niveau de gris `gray_platypus.pgm`, créez une image noir et blanc (binaire) `bw_platypus.pbm`. Pour ce faire, transformez en noir (0) tous les niveaux de gris inférieurs à 128 et en blanc (1) tous ceux qui sont supérieurs ou égaux à 128. 

![bw_platypus.pbm](https://ups.clementbosc.fr/tp1-igtai/bw_platypus.jpg)

### Exercice 3 : Histogramme des niveaux de gris et seuil pour la binarisation

* Calculez l'histogramme des niveaux de gris de l'image `gray_platypus.pgm`.
* Affichez cet histogramme dans la console.
* Analysez cet histogramme et trouvez un seuil permettant de distinguer l'ornithorynque de l'arrière plan mieux que dans l'image en noir et blanc produite à l'exercice 2. 
* Créez une nouvelle image `bw_platypus2.pbm` en utilisant ce seuil.

![bw_platypus2.pbm](https://ups.clementbosc.fr/tp1-igtai/bw_platypus2.jpg)

### Exercice 4 - Manipulation des composantes couleur 

* Calculer l'histogramme de chaque composante (rouge, verte et bleue) de l'image `platypus.ppm`. 
* Affichez les trois histogrammes dans la console.
* Créez une image `lsd_platypus.ppm` en
    * mettant à 0 les valeurs de la composante rouge inférieures à 128 et à 255 celles qui sont supérieures ou égales ;
    * mettant à 0 les valeurs de la composante verte inférieures à 128 et à 255 celles qui sont supérieures ou égales ;
    * mettant à 0 les valeurs de la composante bleue inférieures à 128 et à 255 celles qui sont supérieures ou égales.

![lsd_platypus.ppm](https://ups.clementbosc.fr/tp1-igtai/lsd_platypus.jpg)
