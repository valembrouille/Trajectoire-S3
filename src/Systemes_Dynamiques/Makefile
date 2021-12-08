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
EXEC= SystemesDynamiques
SRC= main.c
LIBS=  $(LIB)/liblorenz.a $(LIB)/librossler.a  $(LIB)/libentrees.a $(LIB)/libparam.a $(LIB)/libpoint.a $(LIB)/libposition.a 
OBJ= $(SRC:.c=.o)
# génère les .o correspondant aux .c de SRC 

all : $(EXEC)

# compilation et génération de la librairie 

$(EXEC) : $(SRC)
	$(CC) $(SRC) -o $(EXEC) -L. $(LIBS)
 



 

# permet de supprimer tous les binaires 

clean:
	rm -f $(EXEC)  
