# L3 Informatique - Informatique graphique, traitement et analyse d'images
# Bases du traitement et de l'analyse d'images
#
# Dans ce qui suit, remplacez monprog par le nom de votre programme
#
# Pour lancer les compilations, tapez :
# make
# Pour effacer tous les fichiers objets et executables, tapez :
# make clean
#
# Pour prendre en compte un nouveau programme, ajoutez-le a tous endroits designes par -->
# ci-dessous.

# Ne modifiez pas cette partie 
# Exception : en cas de refus de l'option -Wpedantic, la remplacer par -pedantic
CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c90 -Wpedantic
LDFLAGS= $(CFLAGS)
LDLIBS=-lm
RM=rm -f

# --> ci-dessous, ajoutez a la suite les noms des fichiers objets 
# separes par un espace
OBJECTS=limace.o exo1.o exo2.o exo3.o exo4.o

# --> ci-dessous, ajoutez a la suite les noms des fichiers executables 
# separes par un espace
EXE=exo1 exo2 exo3 exo4

# Ne modifiez pas cette partie
.PHONY: all
all: $(EXE)

# Dependances non implicites des executables
OBJ=limace.o
exo1: $(OBJ) exo1.o 
exo2: $(OBJ) exo2.o
exo3: $(OBJ) exo3.o
exo4: $(OBJ) exo4.o
# --> ajoutez ici une ligne par programme selon le meme modele


# Dependances non implicites des objets
HEAD=limace.h
limace.o: $(HEAD)
exo1.o: $(HEAD)
exo2.o: $(HEAD)
exo3.o: $(HEAD)
exo4.o: $(HEAD)
# --> ajoutez ici une ligne par programme selon le meme modele


# Ne modifiez pas cette partie
clean:
	$(RM) $(OBJECTS) $(EXE)
