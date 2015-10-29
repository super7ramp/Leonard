INSTALLATION DE L'ENVIRONNEMENT DE TRAVAIL
=========================================

## SDK

Le SDK fourni par Parrot permet de créer des applications de bureau/Android/iOS pouvant communiquer avec le drone en Wifi et le contrôler.
Dans notre cas, cela nous sera utile pour notre application Android et de manière générale pour communiquer avec le drone et avec notre programme embarqué sur le drone.

### Téléchargement

Ici : <http://developer.parrot.com/docs/ardrone/ARDrone_SDK_2_0_1.zip>

### Installation/compilation exemples

Voir chapitre 10 du guide utilisateur. Il y a pas mal de dépendances, normalement les scripts devraient vous dire ce qu'il vous manque.

La compilation des exemples clochent chez moi, vous devrez sans doute appliquer le patch que j'ai créé :

```bash
$ cd chemin/vers/archive/sdk/décompressé/ARDrone_SDK_2_0_1
$ patch -p1 < fix-sdk-examples-build.patch
$ cd Examples/Linux
```

### Lancer les exemples clients

Se connecter en Wifi au réseau « ardrone2\_010851 ». Vérifier la connexion avec :
```bash
$ ping 192.168.1.1
```

Si ça marche (le drone répond bien) :
```bash
$ cd Build/Release
$ ./ardrone_navigation # par exemple
```

## Mettre un programme embarqué sur le drone

### Installer un compilateur ARM

Le drone tourne sur une architecture ARM v7, ce qui n'est pas la même architecture que votre pc. Donc pour pouvoir compiler un programme sur votre machine pour le drone, il vous faut un cross-compilateur ARM v7.

Voir aussi : https://sites.google.com/site/projetsecinsa/documents-techniques/outils-et-methodes/cross-compilation-ar-drone-2-0

#### Cross-compilateur issu des dépôts

Il y a un cross-compilateur ARM dans les dépôts d'Ubuntu qui _pourraient_ fonctionner pour nous :
```bash
 $ sudo apt-get install gcc-arm-linux-gnueabi
```

En tout cas, le résultat a l'air de marcher sur un programme simple.

#### Autre cross-compilateur

Si on se rend compte que le cross-compilateur des dépôts ne fonctionne pas, il y a possibilité de récupérer [celui de Mentor Graphics](http://taghof.github.io/Navigation-for-Robots-with-WIFI-and-CV/downloads/codesetup.sh). Lancez le script :
```bash
$ chmod +x codesetup.sh
$ sudo codesetup.sh
```

Puis ajuster le PATH:
```bash
$ echo "PATH=$PATH:/usr/local/codesourcery/arm-2009q3/bin" >> ~/.bashrc
$ source ~/.bashrc
```

#### Cross-compilateur Parrot

Tout le code source de Parrot est disponible sur https://devzone.parrot.com/. Une inscription est nécessaire mais ensuite on peut récupérer, entre autre, toute la chaîne de cross-compilation.

Je me suis inscrit et récupéré la chaîne mais je ne l'ai pas testée.

### Compiler

Tout simplement, avec le compilateur des dépôts :
```bash
$ arm-linux-gnueabi-gcc4.7 -march=armv7-a source.c -o leonard.elf
```

Ou bien, avec le compilateur codesourcery :
```bash
$ arm-none-linux-gnueabi-gcc source.c -o leonard.elf
```

### Mettre le programme sur le drone

Se connecter en Wifi au drone puis :
```bash
$ ftp 192.168.1.1
$ put leonard.elf
```

Le fichier sera dans `/data/video`. On peut ensuite le lancer normalement :
```bash
$ telnet 192.168.1.1
$ chmod +x leonard.elf
$ ./leonard.elf
```

Note : l'idée est d'appeler ce programme embarqué sur le drone depuis notre appli Android.

## Liens utiles

La partie outil et méthodes du site du projet : https://sites.google.com/site/projetsecinsa/documents-techniques/outils-et-methodes.
