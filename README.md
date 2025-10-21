# 🎮 So Long

**Projet 42 - Cursus 42 Lyon**  
Création d’un petit jeu 2D en C utilisant la bibliothèque graphique **MiniLibX**.

---

## 🧩 Description

Le but du projet est de concevoir un jeu minimaliste en 2D où le joueur doit collecter des objets, éviter les obstacles et atteindre la sortie.  
Ce projet introduit la **programmation graphique**, la **gestion d’événements** et la **manipulation d’images en mémoire**.

---

## 🚀 Fonctionnalités principales

- Lecture et validation d’une carte `.ber` à partir d’un fichier texte  
- Gestion des collisions et des déplacements du joueur  
- Chargement et affichage de textures avec **MiniLibX**  
- Gestion des entrées clavier et de la boucle d’événements  
- Fermeture propre du programme et libération de la mémoire  

---

## 🧠 Compétences développées

- Programmation en C  
- Manipulation mémoire et pointeurs  
- Gestion d’événements et boucle graphique  
- Utilisation de la **MiniLibX**  
- Organisation du code et débogage  

---

## ⚙️ Compilation

Utilisez le **Makefile** fourni :
```bash
make
```

L’exécutable `so_long` sera généré.  
Lancez le jeu avec une carte :
```bash
./so_long maps/map.ber
```

---

## 🗺️ Exemple de carte

```
1111111
1P0C0E1
1111111
```
- `1` : mur  
- `0` : espace vide  
- `P` : joueur  
- `C` : collectible  
- `E` : sortie  

---

## 🖼️ Aperçu visuel
<img width="1912" height="1045" alt="image" src="https://github.com/user-attachments/assets/f9570d51-eaa3-4c40-af75-f59d7b9793e9" />
