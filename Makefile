# Inclure Makefile.compilation pour gérer les dépendances en fonction du système
include Makefile.compilation

# Paramètres pour SDL
SDL = -I include -L lib -lSDL2main -lSDL2 -lSDL2_image $(LDFLAGS)

# Fichiers binaires et objets
fich_test_joueur = obj/test_joueur.o obj/joueur.o obj/plateau.o obj/petite_fonction.o
fich_test_plateau = obj/test_plateau.o obj/plateau.o obj/petite_fonction.o
fich_test_creer_partie = obj/test_creer_partie.o obj/creer_partie.o obj/petite_fonction.o obj/menu.o

BIN = bin/main bin/test_joueur bin/test_plateau bin/test_creer_partie
OBJ = obj/menu.o obj/creer_partie.o obj/petite_fonction.o obj/joueur.o obj/plateau.o obj/partie.o obj/main.o

# Raccourcis pour la compilation
CFLAGS = -Wall
CCLNK = gcc
CCOBJ = gcc -c
LIBMATH = -lm

# Compilation des exécutables principaux
all: $(BIN)

bin/main: $(OBJ)
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(OBJ) -o bin/main $(SDL)

bin/test_joueur: $(fich_test_joueur)
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_test_joueur) -o bin/test_joueur $(SDL)

bin/test_plateau: $(fich_test_plateau)
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_test_plateau) -o bin/test_plateau $(SDL)

bin/test_creer_partie: $(fich_test_creer_partie)
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_test_creer_partie) -o bin/test_creer_partie $(SDL)

# Compilation des fichiers de test
obj/test_joueur.o: src/test/test_joueur.c
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/test/test_joueur.c -o obj/test_joueur.o $(SDL)

obj/test_plateau.o: src/test/test_plateau.c
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/test/test_plateau.c -o obj/test_plateau.o $(SDL)

obj/test_creer_partie.o: src/test/test_creer_partie.c
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/test/test_creer_partie.c -o obj/test_creer_partie.o $(SDL)

# Compilation des fichiers objets
obj/main.o: src/main.c
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/main.c -o obj/main.o $(SDL)

obj/joueur.o: src/joueur.c lib/joueur.h lib/plateau.h lib/petite_fonction.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/joueur.c -o obj/joueur.o $(SDL)

obj/plateau.o: src/plateau.c lib/plateau.h lib/petite_fonction.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/plateau.c -o obj/plateau.o $(SDL)

obj/partie.o: src/partie.c lib/partie.h lib/joueur.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/partie.c -o obj/partie.o $(SDL)

obj/creer_partie.o: src/creer_partie.c lib/petite_fonction.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/creer_partie.c -o obj/creer_partie.o $(SDL)

obj/menu.o: src/menu.c lib/petite_fonction.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/menu.c -o obj/menu.o $(SDL)

obj/petite_fonction.o: src/petite_fonction.c lib/petite_fonction.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/petite_fonction.c -o obj/petite_fonction.o $(SDL)

# Commandes de nettoyage
clean:
	- rm obj/*.o
	- rm bin/main bin/test_joueur bin/test_plateau bin/test_creer_partie
	@echo "Nettoyage terminé."

# Commandes pour exécuter les programmes
main:
	./bin/main

tests:
	./bin/test_joueur
	./bin/test_plateau
	./bin/test_creer_partie
