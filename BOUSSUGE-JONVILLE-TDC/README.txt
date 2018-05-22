Le rendu du projet est compos� de :

 - Ce fichier README.txt
 - Le rapport aux formats .docx et .pdf
 - Un dossier src qui contient les sources (.cpp, .hpp et .pro)
 - Le diagramme de classe

REMARQUE IMPORTANTE :

Ce programme contient un cr�ateur de niveaux. Au premier d�marrage, un fichier niveaux.txt est cr�� dans
le r�pertoire personnel de l'utilisateur et contient les donn�es de plusieurs configurations de niveaux
possibles. Le programme en choisit un al�atoirement � chaque d�but de niveau. Il est possible de cr�er
soi-m�me des niveaux en modifiant niveaux.txt, selon la syntaxe de l'exemple suivant :

*		// Indique un nouveau niveau
12		// Nombre de briques par ligne
10		// Nombre de briques par colonne
111111111111	// Inscrire 1 pour d�poser une brique
000000000000	// Inscrire 0 pour laisser un trou
111111111111	//
000000000000	// Jouer !
111111111111
000000000000
111111111111
000000000000
111111111111
000000000000