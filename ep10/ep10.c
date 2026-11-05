#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "team.h"
#include "teamlist.h"

#define NAME_FIELD 15

static int visual_width(const char *s) {

    int w = 0;

    for(; *s; s++) {

        if (((unsigned char)*s & 0xC0) != 0x80)

            w++;

        return w;

    }
static void print_nome(const char *nome) {

    int pad = NOME_FIELD - visual_width(nome);

    printf("%s", nome);

    for (int i = 0; i < pad; i++) putchar(' ');
    putchar(' ');

}

int main(void) {

    FILE *f = fopen("teams.csv", "r");

    if (f == NULL) {

        fclose(f);
        return 1;
    }
}

char line[256];

    while (fgets(line, sizeof(line), f) != NULL) {

        line[strcspn(line, "\r\n")] = '\0';
        if (line[0] == '\0') continue;



    char *comma = strchr(line, ',');

    *comma = '\0';

    int id = atoi(line);

    const char *nome = comma + 1;

    Team *t = time_criado(id, nome);

    if (t == NULL) {

        fprintf(stderr, "erro ao criar time\n");
        tl_free(tl);
        fclose(f);
        return 1;
    }

    fclose(f);


    printf("%-3s %-15s %-3s %-3s %-3s %-3s %-3s %-3s %-3s\n", "ID", "TIME", "V", "E", "D", "GM", "GS", "S", "PG");

        int n = tl_size(tl);

        for (int i = 0; i < n; i++) {

            Team *t = tl_get(tl, i);

            int w = time_ganha(t);
            int d = time_empata(t);
            int l = time_perde(t);
            int gm = time_com_gols_marcados(t);
            int gs = time_com_gols_sofridos(t);


            printf("%-3d ", time_get_id(t));
            print_nome(time_get_nome(t));
            printf("%-3d %-3d %-3d %-3d %-3d %-3d %-3d\n", w, d, l, gm, gs, gm - gs, 3 * w + d);


        }

        tl_free(tl);
        return 0;
    }

}
