# CaCassePasTroisPattesAUnCanard

Enoncé :

Les fonctionnalités suivantes doivent être implémentées dans le projet : 
• Déplacement du palet commandé par le déplacement de la main du joueur à partir de la WebCam. 
• Rebond de la boule sur les murs, sur le palet et sur les briques. 
• Destruction des briques (disparition) lorsqu’elles sont touchées par la boule. 
• Rebondissement sur le palet et contrôle de la direction de la boule en fonction du point d’impact sur le palet. 
• Décompte des boules utilisées et contrôle de la fin de partie. 

Les fonctionnalités suivantes constitueront un bonus sur la notation du projet : 
• Génération aléatoire d’un nouveau niveau avec une vitesse supérieure de la boule par rapport au niveau précédent. 
• Calcul des points. 
• Choix de la taille du palet par le joueur 
• Sauvegarde du score/nom de joueur et affichage du classement 


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
 - Résolution bug rebond sur le coté la balle change de direction en Y aussi.
 - trop facile de casser deux briques en meme temps, mettre plus de précision sur les rebonds.
 - erreur sur l'enoncé : c'est pas trois boules que l'on veux, mais 3 "vie" donc quand un boule perd, incrémenter le nombre de vie et display une autre boule.
 - Résolution du bug qui fait que la balle ne disparaît pas quand elle touche le mur du bas. En fait il faudrait que si la balle touche le palet elle doit être renvoyée, SINON SI la balle touche le mur du bas elle disparaît (le sinon si est important). On peut pour ça regrouper les murs et le palet (avec les briques) dans un vector<Bloc *> puisque Palet, Brique et Mur sont des classes héritant de Bloc qui est une classe abstraite virtuelle.
 - Création d'une classe Niveau pour gérer : nombre de balles, de briques, tracé des balles et briques automatique, lecture et écriture des infos dans un fichier, niveau terminé ou pas
 - Création d'une classe Personnage pour gérer : lvl max, nom, score total, score pour le niveau actuel
 - Création d'une classe Jeu pour gérer : couleur de fond, espace entre les murs, liste de niveaux, liste de joueurs, tracé des murs automatique, changement des niveaux quand un est fini
```
