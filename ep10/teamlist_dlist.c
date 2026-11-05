#include <stdio.h>
#include <stdlib.h>
#include "team.h"
#include "teamlist.h"

typedef struct node {

    Time *time;
    struct node *next;
    struct node *prev;

} Node;

struct teamlist {

    Node *first;
    Node *last;
    int size;
}

TeamList *tl_create(void) {

    TeamList *tl = malloc(sizeof(TeamList));

    if (tl == NULL) 
    
    return NULL;

    tl->first = NULL;
    tl->last = NULL;
    tl->size = 0;

    return tl;
}

void tl_append(TeamList *tl, Time *t) {

    Node *n = malloc(sizeof(Node));

    if (n == NULL) {

        fprintf(stderr, "erro ao alocar memoria\n");
        exit(1);
    }
        n->team = t;
        n->next = NULL;
        n->prev = tl->last;

        if (tl->last == NULL) {

            tl->first = n;
        } else {
            tl->last->next = n;
        }
        tl->last = n;
        tl->size++;
    }
    int tl_size(const TeamList  *tl) {
        return tl->size;
    }

    Team *tl_get(const TeamList *tl, int i) {

        if (i < 0 || i >= tl->size)
            return NULL;

            Node *cur = tl->first;
            for (int j = 0; j < i; j++)
                cur = cur->next;
            return cur->time;
    }

    void tl_free(TeamList *tl) {

        if (tl == NULL)

            return;

            Node *cur = tl->first;
            while (cur != NULL) {

                Node *next = cur->next;
                team_destroy(cur->team);
                free(cur);
                cur = next;

            }

        free(tl);
    }

    
