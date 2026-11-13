#ifndef TEAMLIST_H
#define TEAMLIST_H

#include "team.h"

// Opaque dynamic vector type: a growable array of Team pointers.
typedef struct teamlist TeamList;

// TODO: implemente tv_create -- aloca o TAD e um vetor inicial pequeno (ex.: 4 times)
TeamList *tl_create(void);

// TODO: implemente tv_insert -- se o vetor estiver cheio, dobre a capacidade
// (realloc) antes de inserir o novo time
void tl_insert(TeamList *tl, Team *t);

// TODO: implemente tv_size -- retorna o número de times atualmente guardados
int tl_size(TeamList *tl);

// TODO: implemente tv_get -- retorna o time na posição i
Team *tl_get(TeamList *tl, int i);

// TODO: implemente tv_free -- libera cada time guardado, o vetor interno e depois o TAD
void tl_free(TeamList *tl);

#endif

