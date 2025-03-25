# TP2 — Calcul de l’entropie

## Partie 1 - Notion d’entropie

#### Q1.1:
La **valeur maximale de l’entropie** pour un fichier est de **8 bits par octet**, cette valeur maximale est atteinte lorsque les 256 octets possibles ont tous exactement la même probabilité d'apparition.

#### Q1.2:

Pour vérifier que **l’entropie** d’un fichier f est donnée par la formule suivante:

```math
H(f) = \log_2 N - \frac{\sum_{s=0}^{255} n_s\log_2 n_s}{N}
```
On sait que la formule de l’entropie est:

```math
H(f) = -\sum_{s=0}^{255} p_s \log_2 p_s
```
Avec:
```math
p_s = \frac{n_s}{N}
```
Ce qui nous donne la formule suivante:

```math
H(f) = -\sum_{s=0}^{255} \frac{n_s}{N} \log_2 \left( \frac{n_s}{N} \right)
```
Et comme:
```math
\log_2 \left( \frac{n_s}{N} \right) = \log_2 n_s - \log_2
```
Donc:
```math
H(f) = -\sum_{s=0}^{255} \left( \frac{n_s}{N} \log_2 n_s - \frac{n_s}{N} \log_2 N \right)
```
```math
H(f) = -\sum_{s=0}^{255} \frac{n_s}{N} \log_2 n_s + \log_2 N \sum_{s=0}^{255} \frac{n_s}{N}
```
Et comme:

```math
\sum_{s=0}^{255} \frac{n_s}{N} = 1
```
Ce qui devient:

```math
H(f) = \log_2 N - \frac{\sum_{s=0}^{255} n_s \log_2 n_s}{N}
```


## Partie2 - Mise en œuvre du calcul de l’entropie

#### Q2.2:
Après avoir implémenter la fonction `count_occurrences`, dans un nouveau fichier `lib/entropy.c`, et en compilant dans le répertoire des tests `make` lançant le programme de test de cette fonction`./test_entropy`, on s'aperçoit que tout les assertions du test se sont executées avec succès.

```bash
ALL TESTS PASSED
Tests run: 2 (including 5 assertions)
```

#### Q2.3:
Après avoir ajouter un test `test_entropy_occurrences_abc`, qui permet de verifier **les comptes d’occurrences**, et en compilant dans le répertoire des tests `make` lançant le programme de test de cette fonction`./test_entropy`, on s'aperçoit que tout les assertions du test se sont executées avec succès.

```bash
ALL TESTS PASSED
Tests run: 3 (including 10 assertions)
```

#### Q2.5:
Après avoir implémenter la fonction de test `test_entropy_function`, et en compilant dans le répertoire des tests `make` lançant le programme de test de cette fonction`./test_entropy`, on s'aperçoit que tout les assertions du test se sont executées avec succès.

```bash
ALL TESTS PASSED
Tests run: 3 (including 12 assertions)
```

#### Q2.6:

Après avoir implémenter la fonction `main` dans le fichier `filentropy.c` et en lançant `./filentropy lib/entropy.h`, j'au eu comme résultat:

```bash
Le fichier fait 1156 octets et a une entropie de 4.54 bits par octet
```

#### Q2.7:

Selon le **théorème du codage sans bruit**, la taille optimale d'un fichier codé est déterminée par son **entropie** divisée par le logarithme en base 2 de la taille de l'alphabet utilisé pour représenter ses symboles. 

Pour la plupart des cas, avec un alphabet de **8** bits par symbole, la **taille minimale** du fichier codé serait d'environ **l'entropie** du fichier divisée par 8 bits par symbole. Ainsi, la taille optimale du fichier codé serait donc **H(S)/8 bits**.

#### Q2.8:

La formule du pourcentage de réduction de la taille du fichier initial que permettrait un tel codage idéal est:

```math
res = 100 - \left( \frac{\text{entropy}}{8} \times 100 \right)
```
Et après avoir compiler avec `make`, et éxecuter avec `./filentropy lib/entropy.h`, j'ai eu comme résultat:

```bash
Le fichier fait 1156 octets et a une entropie de 4.54 bits par octet
Au mieux un codage optimal améliorerait le stockage de ce fichier de 43 %
```

## Partie3 - Expériences:


### Q3.1:

|type       | adresse  |   nom    | taille ( octets)  |  entropie (bits / octet) |
|---        | ---      | ---      | ---      |---        |
|archive.tar    |   [ source archive tar ]("https://gitlab.com/bnb2002436/gitlab")     |     archive_tar.tar     |   4 208 640       |       4.93   |
|archive.zip    |   [ source archive zip ]("https://gitlab.com/mrymakr/doxy-runner")  |  archive_zip.zip      |  170 358     |   7.99       |
|  archive.zip  |  [ source archive zip2 ]("https://github.com/nashsu/FreeAskInternet")  |  archive_zip2.zip  |  28 070  |  7.95  |
| image.jpg  |  [source image jpg ]("https://commons.wikimedia.org/wiki/Main_Page#/media/File:Eucomis_kuiflelie._07-06-2023._(d.j.b).jpg")  |  image1.jpg  | 7 375 183 | 7.98 |
| image.png  |  [source image png ]("https://icon-icons.com/fr/icone/fichier-extension-png/78612")  |  image2.png  |  5 846  |  7.55  |
| image.bmp  |  [source image bmp ]("https://commons.wikimedia.org/wiki/Main_Page#/media/File:Eucomis_kuiflelie._07-06-2023._(d.j.b).jpg")  |  image3.bmp  |  33 253 336  |  7.35  |
|  audio.mp3  |  [source audio mp3 ]("https://commons.wikimedia.org/wiki/File:An_audio_recording_of_an_Australian_Raven_(Corvus_coronoides).wav")  | audio1.mp3  |136 121  |  7.96  |
|  audio.ogg  |  [source audio ogg ]("https://commons.wikimedia.org/wiki/File:Audio_H%C3%B6rbild_Grillenzirpen_-_nachts_um_3_im_F%C3%B6hrenwald_M%C3%B6dling.ogg")  |audio2.ogg  |  387 342  |  7.95  |
|  audio.wav  |  [source audio wav ]("https://commons.wikimedia.org/wiki/File:An_audio_recording_of_an_Australian_Raven_(Corvus_coronoides).wav")  |  audio3.wav  |  1 076 188  |  6.90  |

### Q3.2:

Les différences d’entropie s’expliquent par la nature des fichiers et leur niveau de compression. Les fichiers déjà compressés (comme .zip, .jpg, .mp3, .ogg) ont une entropie élevée, proche de 8 bits par octet, car ils contiennent peu de redondance. En revanche, les formats non compressés (comme .tar, .bmp, .wav) ont une entropie plus faible, ce qui les rend plus compressibles. Ainsi, plus un fichier est compressé, plus son entropie est élevée.
