CC = g++
CFLAGS = -Wall -g
EXEC_NAME = jeu
INCLUDES =-I/.
PUISSANCE = puissance/Puissance.o puissance/Joueur_puissance.o puissance/Plateau_puissance.o
FIVEORMORE = fiveormore/FiveOrMore.o fiveormore/Plateau_five.o
OTHELLO = othello/Othello.o othello/Plateau_Othello.o othello/Joueur_Othello.o
DAME = dame/Dame.o dame/Joueur_dame.o dame/Plateau_dame.o
OBJ_FILES = base/Joueur.o base/Plateau.o base/Partie.o 

MAIN_FILE = main.o

INSTALL_DIR = /usr/bin

all : $(EXEC_NAME)

clean :
	rm -f *~ \#*\#
	rm -f $(EXEC_NAME) $(OBJ_FILES) $(PUISSANCE) $(OTHELLO) $(DAME) $(FIVEORMORE) $(MAIN_FILE)

$(EXEC_NAME) : $(OBJ_FILES) $(PUISSANCE) $(DAME) $(FIVEORMORE) $(OTHELLO) $(MAIN_FILE)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(PUISSANCE) $(DAME) $(OTHELLO) $(FIVEORMORE) $(MAIN_FILE) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
