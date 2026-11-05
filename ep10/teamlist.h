#ifndef TEAMLIST_H
#define TEAMLIST_H

#include "team.h"

// Opaque dynamic vector type: a growable array of Team pointers.
typedef struct teamlist TeamList;

// TODO: implemente tv_create -- aloca o TAD e um vetor inicial pequeno (ex.: 4 times)
TeamList *tv_create(void);

// TODO: implemente tv_insert -- se o vetor estiver cheio, dobre a capacidade
// (realloc) antes de inserir o novo time
void tv_insert(TeamList *tv, Team *t);

// TODO: implemente tv_size -- retorna o número de times atualmente guardados
int tv_size(TeamList *tv);

// TODO: implemente tv_get -- retorna o time na posição i
Team *tv_get(TeamList *tv, int i);

// TODO: implemente tv_free -- libera cada time guardado, o vetor interno e depois o TAD
void tv_free(TeamList *tv);

#endif

