
HOME = .
BIN = $(HOME)/bin
SRC = $(HOME)/src

PROG = $(BIN)/abalone


  ## Definition des flags de compilation
CC = gcc
LD = gcc

LDFLAGS =    
CFLAGS = -g -Wall -ansi -pedantic -std=c99

RM = rm


 ## Liste et generation des binaires, generation de l'executable
OBJS = $(BIN)/abalone.o $(BIN)/init.o $(BIN)/affiche.o $(BIN)/menu.o $(BIN)/deplace.o $(BIN)/outils.o $(BIN)/intelligence.o $(BIN)/sauvegardecontexte.o


 ## Compilation & edition des liens pour la génération de l'executable
$(PROG): $(OBJS)
	@echo -- Edition des liens du programme abalone --
	$(LD) $(LDFLAGS) $(OBJS) -o $(PROG)

$(BIN)/%.o: $(SRC)/%.c
	@echo -- Compilation des fichiers sources --
	$(CC) -o $@ -c $< $(CFLAGS)

 ## Clean
clean:
	@echo -- Nettoyage des fichiers temporaires --
	@-$(RM) -rf $(BIN)/*
