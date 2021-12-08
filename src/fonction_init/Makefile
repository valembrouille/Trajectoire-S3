# commande de compilation 
CC=gcc

# options de compilation 
CFLAGS=  -Wextra -Wall -pedantic -g

# options d'édition de liens : librairies utilisées 
LDFLAGS=  -lm

# emplacement des .a (librairies) du TP 
LIB= ../../lib

# emplacement des .h du TP 
INC= ../../include
# permet d'exécuter en mode debug (génère les informations nécessaires au debugger) 
EXEC= libentrees.a
SRC= common.c entrees.c diff_syst.c

OBJ= $(SRC:.c=.o)
# génère les .o correspondant aux .c de SRC 

all : $(EXEC)

# compilation et génération de la librairie 

$(EXEC) : $(OBJ)
# indique la dépendance de fichiers pour produire la lib (commenter si pb) 
	ar rcs $(LIB)/$(EXEC) $(OBJ)
    # les deux commandes suivantes créent la librairie  
	ranlib $(LIB)/$(EXEC)
    # dans le répertoire donné par LIB 

 

# génère les .o  
%.o: %.c %.h
	@$(CC) -o $*.o -c $*.c $(CFLAGS)

 

# permet de supprimer tous les binaires 

clean:
	rm -f $(LIB)/$(EXEC)  *.o
