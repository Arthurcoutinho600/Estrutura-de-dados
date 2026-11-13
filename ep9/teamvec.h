#ifndef TEAMVEC_H
#define TEAMVEC_H

#include "team.h"

typedef struct teamvec TeamVec;

TeamVec *tv_create(void);

void tv_insert(TeamVec *tv, Team *team);

int tv_size(const TeamVec *tv);

Team *tv_get(const TeamVec *tv, int index);

void tv_free(TeamVec *tv);

#endif