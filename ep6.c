#include <stdio.h>
#include <string.h>

int split_texto(char *texto, char *part1, char *part2) {

    int i = 0;

    while (texto[i] != '\0' && texto[i] != ' ') {

        i++;
    }

    if (texto[i] == '\0') {

        return 0;
    }

    int j;


    for (j = 0; j < i; j++) {

        part1[j] = texto[j];
    }

    part1[j] = '\0';


    int k = 0;

    for (j = i + 1; texto[j] != '\0'; j++){


        part2[k] = texto[j];

        k++;

    }
    part2[k] = '\0';

    return 1;
}

int main() {

    char texto[] = "Bom dia";
    char part1[20], part2[20];


    if (split_texto(texto, part1, part2)) {

        printf("Parte 1: %s\nParte 2: %s\n", part1, part2);
        
    } else {

        printf("Nenhum espaço encontrado.\n");

    }

    return 0;

}