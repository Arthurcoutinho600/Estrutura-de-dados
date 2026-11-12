#include <stdio.h>
#include <string.h>

#define NUM_CIDADES 5
#define MAX_CIRCUITOS 100

int main() {

    int distancias[NUM_CIDADES][NUM_CIDADES] = {

    {0, 10, 7, 15, 50},
    {10, 0, 15, 8, 45},
    {7, 15, 0, 20, 55},
    {15, 8, 20, 0, 40},
    {50, 45, 55, 40, 0}

    };

    char *cidades[NUM_CIDADES] = {

        "Vitória",
        "Vila Velha",
        "Cariacica",
        "Serra",
        "Guarapari"
    };

    int n;

    printf("Digite o número de cidades no circuito: ");
    scanf("%d", &n);
    int circuito[MAX_CIRCUITOS];
    printf("Digite o circuito como uma sequencia de indices: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &circuito[i]);
    }

    int total = 0;

    for (int k = 0; k < n - 1; k++) {
        total += distancias[circuito[k]][circuito[k + 1]];
    }

    printf("\nCircuito: ");

    for (int i = 0; i < n; i++) {

        printf("%s", cidades[circuito[i]]);

        if (i < n - 1) {
            
            printf("->");
        }

    }

    printf("\nDistância toal percorrida: %d km\n", total);

    return 0;
}