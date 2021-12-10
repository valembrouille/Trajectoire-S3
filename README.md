# projet S1

Rouzade Ambre et Kammoun Meyssem 

Nous avons travaillé presque tout le temps ensemble et souvent sur l'ordinateur de Meyssem.



Le progamme en totalité demande à l'utilisateur de choisir entre différents systèmes de calcul de trajectoire, de rentrer des conditions initiales et les paramètres qui seront vérifiés (format ...).
Il permet de calculer ensuite et grâce à tout ça la trajectoire d'un point dans un espace 3D. Il les met dans un liste dirigée vers un fichier qui peut être lu par gnuplot et tracé à l'aide de set prametric puis splot 'nom_du_fichier.dat' u 2:3:4 .


Plus en détail:

fonction_init: 
Sert à lire des entiers et des décimaux avec des scanf et vérifier si ce sont bien des entiers ou des floats.

parametres: 
Permet de "créer" les paramètres utilisables pour les modules. (a,b,c,T_max)

point: 
Permet de "créer" les conditions initiales de la position du point.(x,y,z)

position: 
Permet de "créer" la position à un instant T d'un point. (x,y,z,t)

Dans les 3 modules précedents il y a des fonctions qui créent, initialisent et modifient les strcutures (set et get).


module_lorenz: 
Utilise le système dynamique de Lorenz. Prends en "entrée" des paramètres et un point. Retourne une liste avec les différentes positions de t=0 à t=T_max.

module_rossler: 
Utilise le système dynamique de Rossler. Prends en "entrée" des paramètres et un point. Retourne une liste avec les différentes positions de t=0 à t=T_max.

module_user: 
Demande à l'utilisateur de rentrer lui même ses coordonnées, conditions, paramètres etc dans un format spécial; celui de la polonaise inversée. Les fonctions ne sont pas finies ici. 

Dans les 3 fonctions précédentes, celles de calcul, il y a les fonctions d'initialisation et de calcul pour chaque module.


module_interface:
c'est le module qui fait le lien entre les modules rossler, user, lorenz et le gnuplot. Il prend en entrée une liste de positions et les mets dans un fichier au format accepté par gnuplot. Ce module n'est pas fini.

Systemes_Dynamiques:
C'est le main. Il lie tous les modules précédents et "c'est ici" que l'utilisateur va choisir entre les différents systèmes possibles (Lorenz,Rossler,User).



Les test.dat et .txt sont des fichiers tests pour le gnuplot.
Il y a une librairie et un fichier.h par module. 
Le gitignore cache le dossier lib.
