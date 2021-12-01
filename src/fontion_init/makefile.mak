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

EXEC= test.exe
SRC= test.c
OBJ= $(SRC:.c=.o)

all : $(EXEC)

$(EXEC) : test.c
	$(CC) $(CFLAGS) test.c -o test.exe -I $(INC) -L $(LIB) $(LDFLAGS)

%.o: %.c %.h
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm *.o *.exe            # permet d'automatiser le "nettoyage" 

run:
	./$(EXEC)