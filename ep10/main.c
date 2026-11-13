#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "team.h"
#include "teamlist.h"

int main(void) {

    FILE *arquivo;
    TeamList *lista;
    Team *team;

    char linha[512];
    char *virgula;

    int id;
    int i;
    int saldo;
    int pontos;
    
    arquivo = fopen("teans.csv", "r");

    
lista = tl_create();

if (lista == NULL) {

    fclose(arquivo);
    printf("Erro ao criar a lista\n");

    return 1;

}

while (fgets(linha, sizeof(linha), arquivo) != NULL) {

    linha[strcspn(linha, "\r\n")] = '\0';

    if (linha[0] == '\0') {

        continue;

    }

    virgula = strchr(linha, ',');


    if(virgula == NULL) {

        continue;

    }

    *virgula = '\0';

    id = atoi(linha);

    team = team_create(id, virgula + 1);

    if (team == NULL) {

        fclose(arquivo);
        tl_free(lista);
        printf("Erro ao criar um time\n");
        return 1;


    }

    tl_append(lista, team);

}

fclose(arquivo);

printf("ID Time        V  E  D   GM  GS  S   PG\n");

for (i = 0; i < tl_size(lista); i++) {

    team = tl_get(lista, i);

    saldo = team_get_goals_scored(team) - team_get_goals_conceded(team);

    pontos = 3 * team_get_wins(team) + team_get_draws(team);


    printf("%-3d %-15s %d  %d  %d  %d  %d  %d  %d\n",
        team_get_id(team), 
        team_get_name(team),
        team_get_wins(team),
        team_get_draws(team),
        team_get_losses(team),
        team_get_goals_scored(team),
        team_get_goals_conceded(team),
        saldo,
        pontos);


}

tl_free(lista);

return 0;

}