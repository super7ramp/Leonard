INSTALLATION DE L'ENVIRONNEMENT DE TRAVAIL
=========================================

# SDK

Le SDK fourni par Parrot permet de créer des applications de bureau/Android/iOS pouvant communiquer avec le drone en Wifi et le contrôler.
Dans notre cas, cela nous sera utile pour notre application Android et de manière générale pour communiquer avec le drone et avec notre programme embarqué sur le drone.

## Téléchargement

Ici : <http://developer.parrot.com/docs/ardrone/ARDrone_SDK_2_0_1.zip>

## Installation/compilation exemples

Voir chapitre 10 du guide utilisateur. Il y a pas mal de dépendances, normalement les scripts devraient vous dire ce qu'il vous manque.

La compilation des exemples clochent chez moi, vous devrez sans doute appliquer le patch que j'ai créé :

```
$ cd chemin/vers/archive/sdk/décompressé/ARDrone_SDK_2_0_1
$ patch -p1 < fix-sdk-examples-build.patch
$ cd Examples/Linux
```

## Lancer les exemples clients

Se connecter en Wifi au réseau « ardrone2\_010851 ». Vérifier la connexion avec :
 $ ping 192.168.1.1

Si ça marche (le drone répond bien) :
```
$ cd Build/Release
$ ./ardrone_navigation # par exemple
```

# Mettre un programme embarqué sur le drone

## Installer un compilateur ARM

Le drone tourne sur une architecture ARM v7, ce qui n'est pas la même architecture que votre pc. Donc pour pouvoir compiler un programme sur votre machine pour le drone, il vous faut un cross-compilateur ARM v7.

TODO

Voir aussi : https://sites.google.com/site/projetsecinsa/documents-techniques/outils-et-methodes/cross-compilation-ar-drone-2-0

## Compiler

```
$ $(chemin\_vers\_compilo)/$(nom\_compilo) -march=armv7-a source.c -o leonard.elf
```

## Mettre le programme sur le drone

Se connecter en Wifi au drone puis :
```
$ ftp 192.168.1.1
$ put leonard.elf
```

Le fichier sera dans /data/video. On peut ensuite le lancer normalement :
```
$ chmod +x leonard.elf
$ ./leonard.elf
```

Note : l'idée est d'appeler ce programme embarqué sur le drone depuis notre appli Android.

# Liens utiles
https://sites.google.com/site/projetsecinsa/documents-techniques/outils-et-methodes
