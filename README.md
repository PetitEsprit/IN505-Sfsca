
# IN505 - Projet - UVSQ

Simulateur de fonctionnement d'un système carburant d'un avion

# Pré-requis
Pour compiler les fichiers sources sous Linux, le projet utilise les dépendances suivantes :
- **qmake**
- **qt5**

Les paquets peuvent être installés via la commande suivante :
```shell
sudo apt-get install qt5-default
```

# Conseils d'utilisation
Pour compiler le projet, il suffit d'utiliser le Makefile en utilisant la commande :
```shell
make
```

Si le Makefile n'est pas présent :
```shell
qmake sfsca.pro -spec linux-g++
```

Une fois compilé, le programme peut être lancé avec la commande :
```shell
./sfsca
```
