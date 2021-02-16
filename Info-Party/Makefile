include Makefile.compilation

fich_test_plateau= test_plateau.o

BIN=test_plateau
OBJ=liste.o


test_plateau: $(fich_test_plateau) $(OBJ)
		$(CCLNK) $(CFLAGS) $(LIBMATH) $(fich_test_plateau) $(OBJ)  -o testplateau

test_plateau.o: test_plateau.c
		$(CCOBJ) $(CFLAGS) $(LIBMATH) test_plateau.c -o test_plateau.o -I./





liste.o: liste.c liste.h
	$(CCOBJ) $(CFLAGS) $(LIBMATH) liste.c -o liste.o -I./

all : $(BIN) $(OBJ)

clean :
	- rm  *.o
	- rm test_plateau



tests :
	./test_plateau
