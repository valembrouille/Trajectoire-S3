# commande de compilation 
CC=gcc

# options de compilation 
CFLAGS=  -Wextra -Wall -pedantic -g 

# options d'édition de liens : librairies utilisées 
LDFLAGS=  -lm

# emplacement des .a (librairies) du TP (à adapter à votre organisation) 
LIB= ../../lib

# emplacement des .h du TP (à adapter à votre organisation) 
INC= ../../include

EXEC= libpoint.a
# cible 

SRC=point.c

OBJ= $(SRC:.c=.o)
# génère les .o correspondant aux .c de SRC 

all : $(EXEC)

# compilation et génération de la librairie 

$(EXEC) : $(OBJ)
# indique la dépendance de fichiers pour produire la lib (commenter si pb) 
# $(CC) -o $(OBJ) -c $(SRC) $(CFLAGS)
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