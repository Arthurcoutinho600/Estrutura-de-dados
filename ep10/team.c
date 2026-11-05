#include <stdlib.h>
#include <string.h>
#include "team.h"

struct time {

    int id;
    char *name;
    int wins;
    int draws;
    int losses;
    int gols_scored;
    int gols_conceded;


}

Time *team_create(int id, const char, *nome) {

    Time *t = malloc(sizeof(Time));

    if (t == NULL) return NULL;

    t->name = malloc(strlen(name) + 1);

    if (t->name == NULL) {

        free(t);
        return NULL;
    }
    
    strcpy(t->name, name);

    t->id = id;
    t->wins = 0;
    t->draws = 0;
    t->losses = 0;
    t->gols_scored = 0;
    t->gols_conceded = 0;

    return t;
}
    int team_get_id(const Time *t) {
        return t-> id;
    }
    const char *team_get_name(const Time *t) {
        return t->name;
    }
    int team_get_wins(const Time *t) {
        return t->wins;
    }
    int team_get_draws(const Time *t) {
        return t->draws;
    }
    int team_get_losses(const Time *t) {
        return t->losses;
    }
    int team_get_gols_scored(const Time *t) {
        return t->gols_scored;
    }
    int team_get_gols_conceded(const Time *t) {
        return t->gols_conceded;
    }

    void team_destroy(Time *t) {

        if (t == NULL) 
        return;
        free(t->name);
        free(t);
    }
