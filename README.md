# TP-Armadeus-CryptoMorse
This repository contains a Embedded System group project. 

The goal of the project is to create a software for the Armadeus board that receives messages, crypt them, convert them to morse, and send them through GPIOs.

## Architecture du repository:

### Dossier sprint

Ce dossier contient les codes de chaque sous-partie du projet:
 - cryptage
 - conversion morse
 - controle du gpio
 - client-serveur

__NB__: _Tout ces codes (sauf gpio) compilent individuellement **correctement** avec le cross-compilateur_

### Dossier main

Ce dossier contient un fichier main qui regroupe les sous-partie du programme en un seul.
Il contient également un `makefile` qui compile le code à l'aide du cross-compilateur (remplacer `CC` par le bon)
Le `makefile` se charge également d'envoyer par scp le binaire directement à la carte (changer l'adresse IP si nécessaire).

Il faut également compiler le `client.c` en local.

## Utilisation du code:

1. Compiler le `main.c` à l'aide du cross-compilateur et envoyer le binaire sur la carte
2. Compiler le `client.c` à l'aide d'un compilateur de la machine hôte.
3. Exécuter le binaire sur la carte. (il s'agit d'un serveur)
4. Exécuter le client compilé sur la machine hôte et suivre les instructions.

## Que fais le code ?

Pour l'instant le client sert à emettre le message désiré.
Le serveur sur la carte, récupère le message, le crypte et le convertit en Morse.

__NB:__ _la partie contrôle de la LED par GPIO n'a pas été encore testé. Donc n'est pas dans le main._