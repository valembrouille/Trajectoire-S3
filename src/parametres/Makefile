# le fichier param.c est dans le répertoire module_param ainsi que ce Makefile 
# pour générer la bibliothèque dans le répertoire lib : 
# > make 
# pour supprimer les binaires 
# > make clean 

# commande de compilation 
CC=gcc

# options de compilation 
CFLAGS=  -Wextra -Wall -pedantic -g
# l'option -g peut être conditionnelle 

# options d'édition de liens : librairies utilisées 
LDFLAGS=  -lm

# emplacement des .a (librairies) du TP (à adapter à votre organisation) 
LIB= ../../lib

# emplacement des .h du TP (à adapter à votre organisation) 

INC= ../../include

 

EXEC= libparam.a
# cible 

SRC=param.c

OBJ= $(SRC:.c=.o)
# génère les .o correspondant aux .c de SRC 

all : $(EXEC)

# compilation et génération de la librairie 
#$(EXEC) : param.c $(INC)/param.h
$(EXEC) :$(OBJ)
# indique la dépendance de fichiers pour produire la lib (commenter si pb) 
#	$(CC) -o $(OBJ) -c $(SRC) $(CFLAGS)
	ar rcs $(LIB)/libparam.a $(OBJ)
    # les deux commandes suivantes créent la librairie  
	ranlib $(LIB)/libparam.a
    # dans le répertoire donné par LIB 

 

# génère les .o  
%.o: %.c %.h
	@$(CC) -I $(INC) -o $*.o -c $*.c $(CFLAGS)

 

# permet de supprimer tous les binaires 

clean:
	rm $(LIB)/$(EXEC)  *.o
