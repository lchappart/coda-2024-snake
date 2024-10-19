Voici un modèle de README pour le jeu Snake qui accélère après 50 boucles :

---

# Snake Game

## Description

Ce projet est une implémentation classique du jeu Snake en utilisant la bibliothèque SDL2. Le jeu comporte une fonctionnalité spéciale : après chaque 50 boucles de jeu, la vitesse du serpent augmente, rendant le jeu plus difficile et excitant.

## Installation

1. Cloner le dépôt :
    ```sh
    git clone https://github.com/lchappart/coda-2024-snake.git
    cd coda-2024-snake
    ```

2. Installer les dépendances : Assurez-vous d'avoir installé SDL2 et SDL2_image. Pour les utilisateurs de Debian/Ubuntu :
    ```sh
    sudo apt-get install libsdl2-dev libsdl2-image-dev
    ```

3. Compiler le jeu :
    ```sh
    make
    ```

## Utilisation

Lancer le jeu :
```sh
./snake
```

### Commandes :
- Utilisez les touches fléchées pour déplacer le serpent.
- Appuyez sur `ESC` pour quitter le jeu.

## Fonctionnalités

- **Mouvement du serpent** : Utilisez les touches fléchées pour diriger le serpent.
- **Boucles d'accélération** : Après chaque 50 boucles, la vitesse du serpent augmente, ajoutant un défi supplémentaire.

## Code principal

```c
// Exemple de fonction principale
int main() {
    // Initialisation du jeu et des composants SDL2
    // Création de la liste du serpent et de la carte
    // Boucle principale du jeu avec gestion des événements
    // Gestion de l'accélération toutes les 50 boucles
    // Nettoyage et sortie du jeu
    return 0;
}
```

## Auteurs

- Laurent Chappart - [lchappart](https://github.com/lchappart)

## Licence

Ce projet est sous licence MIT. Voir le fichier [LICENSE](./LICENSE) pour plus de détails.

---

Vous pouvez copier et ajuster ce README selon vos besoins.
