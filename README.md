# CaCassePasTroisPattesAUnCanard



## Fait

Class Balle

```
 - Affichage de la balle
```

Class Bloc
```
 - Classe abstraite pour gérer plus facilement les murs, palet et briques
```

Class Brique : public Bloc
```
 - Détection des collisions entre une brique et une balle
 - Traitement de la collision : indique à une balle dans quel sens repartir
 - Affichage d'une balle
```

Class Mur : public Bloc
```
 - Affichage d'un mur
 - Peut considérer quatre types de murs différents : gauche, droite, haut, bas
 - Détecte et traite les collisions entre un mur et une balle
```

Class Palet : public Bloc
```
 - Affichage, détection et traitement des collisions entre le palet et une balle
 - Gère le mouvement du palet
```

Class MyGLWidget
```
 - Gère une liste de briques, de murs et de balles
 - Possède un palet
 - Organisation des différentes collisions
```

## Reste à faire

```
 - Création d'une classe Niveau pour gérer : nombre de balles, de briques, tracé des balles et briques automatique, lecture et écriture des infos dans un fichier, niveau terminé ou pas
 - Création d'une classe Personnage pour gérer : lvl max, nom, score total, score pour le niveau actuel
 - Création d'une classe Jeu pour gérer : couleur de fond, espace entre les murs, liste de niveaux, liste de joueurs, tracé des murs automatique, changement des niveaux quand un est fini
```
