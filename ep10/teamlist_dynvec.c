#include <stdio.h>
#include <stdlib.h>
#include "team.h"
#include "teamlist.h"

#define INITIAL_CAPACITY 4

struct teamList {

    Team **data;
    int size;
    int capacity;

};

TeamList *tl_create(void) {

    TeamList *tl = malloc(sizeof(TeamList));

    if (tl == NULL)

        return NULL;

    tl->data = malloc(INITIAL_CAPACITY * sizeof(Time *));

    if (tl->data == NULL) {
        
        free(tl);
        return NULL;
    
        }
        tl->size = 0;
        tl->capacity = INITIAL_CAPACITY;
        return tl;

    }

    void tl_append(TeamList *tl, Time *t) {
    
        if (tl->size == tl->capacity) {
            
            int new_cap = tl->capacity * 2;
            Team **tmp = realloc(tl->data, new_cap * sizeof(Team *));
            if (tmp == NULL) {
            
                fprintf(stderr, "erro ao alocar memoria\n");
                exit(1);

            }

            tl->data = tmp;
            tl->capacity = new_cap;

            }
        
            tl->data[tl->size++] = t;

        
        }
    
    int tl_size(const TeamList *tl) {
    
        return tl->size;

    
    }

    Team *tl_get(const TeamList *tl, int i) {
    
        if (i < 0 || i >= tl->size)
            
            return NULL;
        
        return tl->data[i];
    
    
    }

    void tl_free(TeamList *tl) {
    
        if (tl == NULL)

            return;

        for (int i = 0; i < tl->size; i++)

            team_destroy(tl->data[i]);
        
        free(tl->data);
        free(tl);
        
        
    }