#include <stdio.h>
#include "entropy.h"

void count_occurrences(FILE *file, int counts[]){
    int c;
    for(int i = 0;i<256;i++){
        counts[i] = 0;
    }
    if (file == NULL){
        printf("Erreur lors de l'ouverture du fichier");
    }
    else{
        while((c = fgetc(file)) != EOF){
                counts[c]++;       
        }
    }
}
