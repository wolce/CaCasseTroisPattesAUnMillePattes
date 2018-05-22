Le rendu du projet est composé de :

 - Ce fichier README.txt
 - Le rapport aux formats .docx et .pdf
 - Un dossier src qui contient les sources (.cpp, .hpp et .pro)
 - Le diagramme de classe

REMARQUE IMPORTANTE :

Ce programme contient un créateur de niveaux. Au premier démarrage, un fichier niveaux.txt est créé dans
le répertoire personnel de l'utilisateur et contient les données de plusieurs configurations de niveaux
possibles. Le programme en choisit un aléatoirement à chaque début de niveau. Il est possible de créer
soi-même des niveaux en modifiant niveaux.txt, selon la syntaxe de l'exemple suivant :

*		// Indique un nouveau niveau
12		// Nombre de briques par ligne
10		// Nombre de briques par colonne
111111111111	// Inscrire 1 pour déposer une brique
000000000000	// Inscrire 0 pour laisser un trou
111111111111	//
000000000000	// Jouer !
111111111111
000000000000
111111111111
000000000000
111111111111
000000000000