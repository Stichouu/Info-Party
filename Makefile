include Makefile.compilation

fich_test_joueur = obj/test_joueur.o obj/joueur.o obj/plateau.o
fich_test_plateau = obj/test_plateau.o obj/plateau.o

BIN = bin/main bin/test_joueur bin/test_plateau
OBJ = obj/plateau.o obj/joueur.o obj/partie.o obj/main.o

SDL = -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows



#executables
bin/main: $(OBJ)
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(OBJ) -o bin/main

bin/test_joueur: $(fich_test_joueur)
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_test_joueur) -o bin/test_joueur

obj/test_joueur.o: src/test/test_joueur.c
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/test/test_joueur.c -o obj/test_joueur.o $(SDL)

bin/test_plateau: $(fich_test_plateau)
	$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_test_plateau) -o bin/test_plateau

obj/test_plateau.o: src/test/test_plateau.c
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/test/test_plateau.c -o obj/test_plateau.o $(SDL)



#objets
obj/main.o: src/main.c
		$(CCOBJ) $(CFLAGS) $(LIBMATH) src/main.c -o obj/main.o $(SDL)

obj/joueur.o: src/joueur.c lib/joueur.h lib/plateau.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/joueur.c -o obj/joueur.o $(SDL)

obj/plateau.o: src/plateau.c lib/plateau.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/plateau.c -o obj/plateau.o $(SDL)

obj/partie.o: src/partie.c lib/partie.h lib/joueur.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) src/partie.c -o obj/partie.o $(SDL)


all : $(BIN)

clean :
	- rm  obj/*.o
	- rm bin/main
	- rm bin/test_joueur
	- rm bin/test_plateau

main :
	./bin/main

tests :
	./bin/test_joueur
	./bin/test_plateau
