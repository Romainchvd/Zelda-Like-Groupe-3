# Zelda Like Groupe 3
Zelda Like 2D Groupe 3
Romain, Ethan, Rayen, Liam

INTRODUCTION

Ce projet, effectué dans le cadre de la pédagogie par projet du Gaming Campus, est un jeu à partie rapide, destiné à un public d'au moins 14 ans (en raison de l'écran de victoire
pouvant heurter la sensibilité des plus jeunes). Celui-ci propose une rejouabilité avec un éditeur de fichiers texte.

CONCEPT

Le jeu est un jeu d'aventure en PVE, dans lequel le joueur se rend jusqu'au château du royaume afin d'en déloger le maître. Le gameplay est ouvertement inspiré du jeu vidéo Zelda et se
déroule en 2D avec vue top-down.

GAME DESIGN, SOUND DESIGN & ASPECTS TECHNIQUES
Direction artistique: le jeu utilise des visuels venant ou dérivés du site itch.io . Il propose des visuels colorés en pixel-art.
Le jeu dispose de trois zones: les maisons, la plaine et le château. Il dispose d'animations simples et ne requiert pas un ordinateur puissant pour fonctionner. En fonction de votre
écran, vous n'aurez ainsi aucune difficulté à le faire tourner en 60fps à 144 fps. La musique est issue de jeux nintendo: Zeldae et Lufia, et les effets sonores viennent de minecraft,
Zelda et de bruitages libres de droits. La musique du jeu est gérée par un thread afin de soulager le thread principal. Le jeu est développé en C++ à l'aide du moteur graphique SFML et
utilise des pointeurs intelligents pour éviter les fuites de mémoire.


Histoire:

Synopsis: Le jeu se déroule dans un petit Royaume dont le roi a été assassiné par un tyran avant de se faire renverser par un héros bleu. Le jeu vous propose de vivre cette histoire.
Le seul hic, c'est que le tyran lui aussi, était bleu...

Compétences:
Le joueur dispose d'une attaque excécutée à l'aide du clic droit de la souris. En fonction de son équipement, qu'il améliore au fil de la partie,
il s'agit soit d'un coup de poing, soit d'une épée.

Le joueur dispose de 100 PV qui peuvent être portés à 200 au fil du jeu. Il n'y a pas de regénération de la vie.

L'interface utilisateur est constituée d'un compteur de clé et d'un indicateur de vie.

Difficulté: ce jeu peut être réalisé en contournant les ennemis. Dans ce cas, il s'agit d'un jeu facile. Cependant, choisir de vaincre tous les ennemis est un défi exigeant.

Menu de jeu:
-Bouton Play
-Bouton Editor
-bouton Exit

Lobby:
Maison du joueur et entrée du donjon.

Ennemis:
Il existe quatre types d'ennemis: 
- Le garde à la retraite, très faible, qui occupe une maison et garde le chemin vers le château
- L'ennemi classique qui se bat au corps à corps, de couleur rouge
- L'ennemi renforcé, de couleur verte, est une version améliorée de l'ennemi rouge
- Le roi, qui possède plus de points de vie que les autres. Il s'agit du boss du jeu.


Fin de jeu:
Kinl tue le roi et révèle sa véritable nature.

Comment jouer?

- Déplacements avec ZQSD
- Interactions avec E
- Attaque avec le clic droit
- Récupération du receptacle de coeur au contact de ce dernier

Editeur:
L'éditeur ne permet pas de changer la position des ennemis ou l'endroit d'apparition du joueur, mais vous pouvez placer le décor de sorte à les retrouver.
Les cases du jeu font 96 pixels par 96 pixels.
Coordonnées du garde: 22 * 96, 4 * 96
Coordonnées de l'ennemi 1: 43 * 96, 25 * 96 et 51*96, 31*96
Coordonnées de l'ennemi 2: 48*96, 30*96
Coordonnées du roi: 114*96, 14*96

Comment faire mon propre niveau dans l'éditeur?

Pour faire votre niveau, ouvrez le dossier Assets puis map et ouvrez les fichiers.txt firstLayerEdit et secondLayerEdit.
Vos modifications seront visibles en lançant le jeu via le bouton Editor de l'écran titre.
Les coordonnées du joueur sont : 250, 296
Afin d'éditer le jeu, vous devez mettre des caractères qui correspondent à des props. Attention, l'éditeur est sensible à la casse.
La map prend fin lorsque le programme rencontre le ';' dans le fichier.
ATTENTION: retirer le ';' provoquera un plantage du jeu.

Certains caractères ne génèrent aucun props, il ne s'agit pas d'un oubli dans le présent document.

Le code des props est défini comme suit:

- firstLayerEditor.txt:

0: Planches en bois (sol)  
1: Mur bas de maison  
5: Texture d'herbe  
6: Sol en pierre  
7: Porte de château  
8: Mur de château  
9: Fenêtre de château  
A: Mur de château bas-gauche  
B: Mur de château bas-droit  
C: Mur de château haut-gauche  
D: Mur de château haut-droit  
E: Carré-mur de château haut-droit (utile pour les coins exterieurs)  
F: Carré-mur de château haut-gauche  
G: Mur de maison (planches de bois)  
H: Mur haut de maison  
I: Mur gauche de maison  
J: Mur droit de maison  
W: Mur droit de château  
X: Mur gauche de château  
Y: Sol de château  
Z: Mur haut de château  
a: Mur bas de château  
b: Mur bas gauche de château (un coin situé au nord d'un sol de château)  
c: Mur bas droite de château (idem)  

- secondLayer.txt:  

0: Texture haute du lit  
1: Evier  
2: Comptoir  
3: Plaques de cuisson  
4: Commode  
5: Tapis  
6: Texture basse du lit  
7: Texture basse de tour de château  
8: Texture du milieu de tour de château  
9: Toit de tour de château  
A: Muraille horizontale  
B: Muraille verticale  
C: Maison rouge haut gauche  
D: Maison rouge haut droit  
E: Maison rouge bas gauche  
F: Maison rouge bas droit  
G: Tronc d'arbre  
H: Feuilles d'arbre  
I: Maison bleue haut gauche  
J: Maison bleue haut droit  
K: Maison bleue bas gauche  
L: Maison bleue bas droit  
M: Pics rétractés (Note: cette texture n'est pas utilisée dans le mode normal)  
N: Pics sortis (idem)  
O: Porte (se déverouille avec une clé)  
P: Clé (Peut être récupérée)  
Q: Barrière horizontale (Cette texture n'est pas utilisée dans le mode normal)  
R: Barrière verticale  
S: Tapis rectangulaire  
T: Bannière  
U: Portail de château (se dévérouille avec une clé)  
V: Muraille de château verticale  
W: Coffre contenant une clé  
X: Epée (se ramasse)  
Y: Receptacle de coeur (double vos PV, se ramasse. Ne peut pas être cumulé)  

REPARTITION DES ROLES

Joueur, animations et ennemis : Ethan, Rayen  
Déplacements, collisions et interactions: Liam  
Menu, direction artistique: Rayen, Romain  
Carte du jeu et éditeur: Romain  
Musiques et sons: Romain  
Présentation PowerPoint: Liam  
Doc: Liam, Romain  

PLANNING ET ECHEANCES

Jour 1: Bases du projet et structuration  
Jour 2: Lobby, Plaine, consolidation de la structure  
Jour 3: Joueur, poursuite de la carte
Jour 4: mécanismes interactifs pour le donjon, finalisation du joueur
Jour 5: Ennemis, musique, sons
Jour 6: Donjon
Jour 7: Menus, interface, boss
Jour 8: Crédits, scénario

CONCLUSIONS ET PERSPECTIVES

Le projet s'est révélé être trop ambitieux. Le jeu est jouable mais n'est clairement pas terminé. Plusieurs raisons sont à soulever: le début du projet a été marqué par une stricte
répartition des rôles et à une spécialisation dans les tâches, mais également par une désorganisation dans le code, rapidement résolue. L'un des membres du projet étant tombé malade (grippe), le jeu a accumulé un retard considérable au niveau des ennemis et les autres développeurs ont dû interrompre leurs tâches afin de soulager la personne concernée, ce qui a provoqué à la fois un jeu final avec des ennemis non finalisés et plusieurs fonctionnalités manquantes. Le jeu possède néanmoins du potentiel et gagnerait à évoluer, avec une meilleure communication et explication du code (Nottamment par le moyen de commentaires). L'ajout d'une régénération de vie était prêt mais n'a pas pu être livré à temps. Pourraient être ajoutés un gameplay à distance et une amélioration du donjon et du boss final pour compléter le projet.
