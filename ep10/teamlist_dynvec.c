#include <stdlib.h>
#include "teamlist.h"


struct teamlist {

    Team **teams;
    int size;
    int capacity;

};

TeamList *tl_create(void) {

    TeamList *tl = malloc(sizeof(TeamList));

    if (tl == NULL) {

        return NULL;

    }

    tl->size = 0;
    tl->capacity = 2;

    tl->teams = malloc(tl->capacity * sizeof(Team *));

    if (tl->teams == NULL) {
        
        free(tl);
        return NULL;
    
        }
        return tl;

    }

    void tl_append(TeamList *tl, Team *team) {

        Team **aux;
        int new_capacity;
    
        if (tl == NULL || team == NULL) {
            
            return;

        }
    
        if (tl->size == tl->capacity) {

        new_capacity = tl->capacity * 2;

        aux = realloc(tl->teams, new_capacity * sizeof(Team *));

        if (aux == NULL) {

            return;
        }

        tl->teams = aux;
        tl->capacity = new_capacity;

        }

        tl->teams[tl->size] = team;

        tl->size++;


    }

    int tl_size(const TeamList *tl) {

        if (tl == NULL) {

            return 0;

        }

        return tl->size;

    }

Team *tl_get(const TeamList *tl, int index) {


    if (tl == NULL || index < 0 || index >= tl->size) {

        return NULL;

    }

    return tl->teams[index];


}

void tl_free(TeamList *tl) {

    int i;

    if (tl != NULL) {

        for (i = 0; i < tl->size; i++ ) {

            team_free(tl->teams[i]);

        }

        free(tl->teams);
        free(tl);

    }

}