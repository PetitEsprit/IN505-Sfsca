# Projet IN505 - Compte rendu

Comtpe rendu du projet d'IN505 de l'UVSQ

### Auteurs :

- **DANKOU Mathis**
- **SOURSOU Adrien**

# Informations techniques

## Structure du projet

```shell
.
├── Makefile
├── README.md
├── data
├── doc
├── inc
└── src
```

Les fichiers sources sont situés dans src, les headers dans inc et la documentation relative au projet dans doc.

Le dossier data est l'emplacement où les différents fichiers des utilisateurs sont stockés.

## Système d'authentification

Les données des utilisateurs sont stockées dans des fichiers individuels. Le système d'authentification vise à protéger leurs données. Par conséquent, les mots de passe ne sont jamais écrits en clair dans les fichiers, afin d'éviter l'usurpation d'identité.

On a choisi d'utiliser le SHA-512 comme fonction de hachage.

## Format de fichier utilisateur

Chaque utilisateur possède un fichier *[username].dat* où *[username]* est remplacé par le nom de l'utilisateur.
```shell
[sha512(username + password)] # hash d'identification
[sha512(hash + sha512(historique))] # empreinte de l'historique
[timestamp],[grade] # une entrée de l'historique (date + note)
# ...
# 0 à n entrées possibles dans l'historique
```

Lors de la création d'un utilisateur, l'historique est vide. Le format à donc cette forme :
```
[sha512 hash]
[sha512 foothprint]
```

### Exemple de fichier :

Contenu de *user.dat* :
```
d6bfd9699e316894027d7dcc3a52a9c385031b0e822d8faa3fc856fe677962a2843825e1818d72fe32ee6bd02a4e065cbdbbb5a318dc02db873d6e8a5a0c0934
c62017b4193a376ab834e6c0c65ff6c12a630dd19663a31daf2ad4cecc1ca310c2a967f37ccad58da28ac8d25ef3b9aa0a98fc48a99c088b5b5977fcd2e14884
1578206720,5.27
1578206728,9.69
1578206746,2.42
```

Les notes ne sont pas chiffrées, mais elles ne sont pas modifiables.
Toute altération malveillante du fichier est détectée par le système d'authentification.
L'empreinte de l'historique (la deuxième ligne) permet d'éviter la triche.
Cette sécurité n'est pas infaillible, cependant elle est suffisament performante pour le projet.


# Remerciements

Merci à *Olivier Gay* pour son implémentation du SHA-512
