# Definitions des cibles particulieres
.PHONY: clean, remove
# Desactivations des regles implicites
.SUFFIXES:

# Creation executable
all: main.o ShingShang.o utilitaire.o plateau.o case_plateau.o pion.o joueur.o deplacement.o
	gcc bin/*.o -o bin/Shing-Shang
#	gcc bin/main.o bin/ShingShang.o bin/utilitaire.o bin/plateau.o bin/case_plateau.o bin/pion.o bin/joueur.o bin/deplacement.o -o bin/Shing-Shang

# Regles edition des liens
main.o: src/main.c
		gcc -I include/ -c src/main.c -o bin/main.o

ShingShang.o: src/ShingShang.c include/ShingShang.h
	gcc -I include/ -c src/ShingShang.c -o bin/ShingShang.o

utilitaire.o: src/utilitaire.c include/utilitaire.h
	gcc -I include/ -c src/utilitaire.c -o bin/utilitaire.o

plateau.o: src/plateau.c include/plateau.h
	gcc -I include/ -c src/plateau.c -o bin/plateau.o

case_plateau.o: src/case_plateau.c include/case_plateau.h
	gcc -I include/ -c src/case_plateau.c -o bin/case_plateau.o

pion.o: src/pion.c include/pion.h
	gcc -I include/ -c src/pion.c -o bin/pion.o

joueur.o: src/joueur.c include/joueur.h
	gcc -I include/ -c src/joueur.c -o bin/joueur.o

deplacement.o: src/deplacement.c include/deplacement.h
	gcc -I include/ -c src/deplacement.c -o bin/deplacement.o

# Regles de nettoyages
clean:
	rm -rf bin/*.bak rm -rf bin/*.o

remove:
	rm -rf bin/*
