Snake Game
Description
Ce projet est une implémentation classique du jeu Snake en utilisant la bibliothèque SDL2. Le jeu comporte une fonctionnalité spéciale : après chaque 50 boucles de jeu, la vitesse du serpent augmente, rendant le jeu plus difficile et excitant.

Installation
Cloner le dépôt :

sh

Copier
git clone https://github.com/ton-utilisateur/snake-game.git
cd snake-game
Installer les dépendances : Assurez-vous d'avoir installé SDL2 et SDL2_image. Pour les utilisateurs de Debian/Ubuntu :

sh

Copier
sudo apt-get install libsdl2-dev libsdl2-image-dev
Compiler le jeu :

sh

Copier
make
Utilisation
Lancer le jeu :

sh

Copier
./snake
Commandes :

Utilisez les touches fléchées pour déplacer le serpent.

ESC pour quitter le jeu.

Fonctionnalités
Mouvement du serpent : Utilisez les touches fléchées pour diriger le serpent.

Boucles d'accélération : Après chaque 50 boucles, la vitesse du serpent augmente, ajoutant un défi supplémentaire.

Code principal
c

Copier
// Exemple de fonction principale
int main() {
    // Initialisation du jeu et des composants SDL2
    // Création de la liste du serpent et de la carte
    // Boucle principale du jeu avec gestion des événements
    // Gestion de l'accélération toutes les 50 boucles
    // Nettoyage et sortie du jeu
    return 0;
}
Auteurs
Ton Nom - ton-utilisateur

Licence
Ce projet est sous licence MIT. Voir le fichier LICENSE pour plus de détails.
