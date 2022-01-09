# Réseau algorithme de Prim

## Présentation

Ce projet a été fait dans le cadre du cours [INF3105 - Structures de données et algorithmes](https://etudier.uqam.ca/cours?sigle=INF3105) du Baccalauréat en informatique et génie logiciel de l'UQAM en 2018. Ler but du travail était de trouver chercher un arbre de recouvrement à coût maximum (MST) d'un graphe en se basant sur [l'algorithme de Prim](https://en.wikipedia.org/wiki/Prim%27s_algorithm) et en utilisant la librairie standard de C++ (STL). L'énoncé détaillé du projet est dans le fichier [enonce.pdf](enonce.pdf).

## Contexte

La mairie d’une ville a décidé d’installer des terminaux publicitaires dans un quartier. Elle veut relier tous les sites (places publiques) du quartier entre eux via un réseau filaire. Elle vous a fourni les donnéessuivantes:

- La liste des rues les plus visitées du quartier; chaque rue est identifiée par un ensemble de sites.
- La position géographique des sites.
- Le flux d’achalandage associé à chaque rue, il est défini par la moyenne du nombre de personnes qui circulent quotidiennement sur cette rue.

Les sites du quartier sont reliés entre eux en formant un graphe connexe étiqueté où les noeuds représentent les sites du quartier, les arêtes sont les rues qui relient les sites entre eux et les poids sont le flux des personnes sur chaque rue. La ville veut relier, de façon optimale, tous les sites du cartier par un réseau publicitaire en favorisant les rues les plus achalandées. Dans le processus du choix des arêtes dans l’algorithme Prim, si plusieurs arêtes ont le même poids vous devez choisir celle qui est la plus proche en distance.

## Utilisation

Pour compiler le projet, se déplacer dans le dossier `reseau-prim-algorithme/src` et taper la commande `make`. Ensuite faire par exemple la commande `/.tp3 exemple1.txt` à la racine du dossier `reseau-prim-algorithme/src` pour lancer l'application. Ce travail a été testé recemment sur [Ubuntu](https://ubuntu.com/) 20.04.3 LST.

## Exemple

Voici le contenu de l'exemple `exemple2.txt` dans le dossier `reseau-prim-algorithme/src`:
```
n1 (45.509128,-73.570289)
n2 (45.509331,-73.570793)
n3 (45.511113,-73.570010)
n4 (45.510579,-73.568894)
n5 (45.509910,-73.567435)
---
Rue1 : n1 n2 15 ;
Rue2 : n2 n3 15 ;
Rue3 : n3 n4 n5 20 ;
Rue4 : n1 n4 15 ;
Rue5 : n1 n5 3 ;
```

Voici la sortie sur la console pour cet exemple:
```
n1 n2
Rue1
15
n1 n4
Rue4
15
n3 n4
Rue3
20
n4 n5
Rue3
20
---
70
```
