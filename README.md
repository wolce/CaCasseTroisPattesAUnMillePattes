# CaCassePasTroisPattesAUnCanard



## Fait

Class Balle

```
 - Affichage de la balle
```

Class Bloc
```
 - Classe abstraite pour g�rer plus facilement les murs, palet et briques
```

Class Brique : public Bloc
```
 - D�tection des collisions entre une brique et une balle
 - Traitement de la collision : indique � une balle dans quel sens repartir
 - Affichage d'une balle
```

Class Mur : public Bloc
```
 - Affichage d'un mur
 - Peut consid�rer quatre types de murs diff�rents : gauche, droite, haut, bas
 - D�tecte et traite les collisions entre un mur et une balle
```

Class Palet : public Bloc
```
 - Affichage, d�tection et traitement des collisions entre le palet et une balle
 - G�re le mouvement du palet
```

Class MyGLWidget
```
 - G�re une liste de briques, de murs et de balles
 - Poss�de un palet
 - Organisation des diff�rentes collisions
```

## Reste � faire

```
 - Cr�ation d'une classe Niveau pour g�rer : nombre de balles, de briques, trac� des balles et briques automatique, lecture et �criture des infos dans un fichier, niveau termin� ou pas
 - Cr�ation d'une classe Personnage pour g�rer : lvl max, nom, score total, score pour le niveau actuel
 - Cr�ation d'une classe Jeu pour g�rer : couleur de fond, espace entre les murs, liste de niveaux, liste de joueurs, trac� des murs automatique, changement des niveaux quand un est fini
```
