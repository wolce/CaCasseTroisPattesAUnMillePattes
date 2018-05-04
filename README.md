# CaCassePasTroisPattesAUnCanard

Enonc� :

Les fonctionnalit�s suivantes doivent �tre impl�ment�es dans le projet : 
� D�placement du palet command� par le d�placement de la main du joueur � partir de la WebCam. 
� Rebond de la boule sur les murs, sur le palet et sur les briques. 
� Destruction des briques (disparition) lorsqu�elles sont touch�es par la boule. 
� Rebondissement sur le palet et contr�le de la direction de la boule en fonction du point d�impact sur le palet. 
� D�compte des boules utilis�es et contr�le de la fin de partie. 

Les fonctionnalit�s suivantes constitueront un bonus sur la notation du projet : 
� G�n�ration al�atoire d�un nouveau niveau avec une vitesse sup�rieure de la boule par rapport au niveau pr�c�dent. 
� Calcul des points. 
� Choix de la taille du palet par le joueur 
� Sauvegarde du score/nom de joueur et affichage du classement 


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
 - R�solution bug rebond sur le cot� la balle change de direction en Y aussi.
 - trop facile de casser deux briques en meme temps, mettre plus de pr�cision sur les rebonds.
 - erreur sur l'enonc� : c'est pas trois boules que l'on veux, mais 3 "vie" donc quand un boule perd, incr�menter le nombre de vie et display une autre boule.
 - R�solution du bug qui fait que la balle ne dispara�t pas quand elle touche le mur du bas. En fait il faudrait que si la balle touche le palet elle doit �tre renvoy�e, SINON SI la balle touche le mur du bas elle dispara�t (le sinon si est important). On peut pour �a regrouper les murs et le palet (avec les briques) dans un vector<Bloc *> puisque Palet, Brique et Mur sont des classes h�ritant de Bloc qui est une classe abstraite virtuelle.
 - Cr�ation d'une classe Niveau pour g�rer : nombre de balles, de briques, trac� des balles et briques automatique, lecture et �criture des infos dans un fichier, niveau termin� ou pas
 - Cr�ation d'une classe Personnage pour g�rer : lvl max, nom, score total, score pour le niveau actuel
 - Cr�ation d'une classe Jeu pour g�rer : couleur de fond, espace entre les murs, liste de niveaux, liste de joueurs, trac� des murs automatique, changement des niveaux quand un est fini
```
