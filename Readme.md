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
H(f) = -\sum_{s=0}^{255} \frac{n_s}{N} \log_2 \left( \frac{n_s}{N} \right)\n

\log_2 \left( \frac{n_s}{N} \right) = \log_2 n_s - \log_2 \n

H(f) = -\sum_{s=0}^{255} \left( \frac{n_s}{N} \log_2 n_s - \frac{n_s}{N} \log_2 N \right)\n

H(f) = -\sum_{s=0}^{255} \frac{n_s}{N} \log_2 n_s + \log_2 N \sum_{s=0}^{255} \frac{n_s}{N}\n

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

#### Q2.1:
Après avoir implémenter la fonction `count_occurrences`, dans un nouveau fichier `lib/entropy.c`, et en compilant dans le répertoire des tests `make` lançant le programme de test de cette fonction`./test_entropy`, on s'aperçoit que tout les assertions du test se sont executées avec succès.

```bash
ALL TESTS PASSED
Tests run: 2 (including 5 assertions)
```