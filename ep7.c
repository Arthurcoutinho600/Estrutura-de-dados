#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQ "time.txt"

void write_time_to_file(const char *filename, int id, const char *nome, int pontos) {

    FILE *arquivo = fopen(filename, "w");

    if (arquivo == NULL) {

        perror("Erro ao abrir o arquivo para escrita");
        exit(1);
    }

    fprintf(arquivo, "%d\n%s\n%d\n", id, nome, pontos);
    fclose(arquivo);


}

int read_time_from_file(const char *filename, int *id, char *nome, int *pontos) {

    FILE *arquivo = fopen(filename, "r");

    if (arquivo == NULL) {

        perror("Erro ao abrir o arquivo para leitura");

        return 0;

    }

    int ok = (fscanf(arquivo, "%d %49[^\n] %d", id, nome, pontos) == 3);

    fclose(arquivo);
    return ok;
}

typedef struct {
    int id;
    char nome[50];
    int pontos;
} 

Time;

int main() {

    Time *time1 = malloc(sizeof(Time));

    if (time1 == NULL) {

        printf("Erro ao alocar memória.\n");
        exit(1);

    }

    printf("Cadastro de um novo time\n");
    printf("-------------------------\n");

    printf("ID do time: ");
    scanf("%d", &time1 -> id);

    getchar();

    printf("Nome do time: ");

    fgets(time1 -> nome, sizeof(time1 -> nome), stdin);

    time1 -> nome[strcspn(time1 -> nome, "\n")] = '\0';

    printf("Pontos: ");
    scanf("%d", &time1 -> pontos);

    printf("\n");

    write_time_to_file(ARQ, time1 -> id, time1 -> nome, time1 -> pontos);
    printf("Time salvo em %s.\n\n", ARQ);

    free(time1);

    printf("Lendo os dados gravados em %s...\n\n", ARQ);
    
    Time *time2 = malloc(sizeof(Time));
    

    if (time2 == NULL) {

        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    if (read_time_from_file(ARQ, &time2 -> id, time2 -> nome, &time2 -> pontos)) {

        printf("Time carregado do arquivo:\n");
        printf("ID: %d\n", time2 -> id);
        printf("Nome: %s\n", time2 -> nome);
        printf("Pontos: %d\n", time2 -> pontos);
    } else {

        printf("Não foi possivel ler o arquivo.\n");
    }


    free(time2);

    return 0;
    
}