#include <stdlib.h>
#include <string.h>
#include "team.h"

struct team {

    int id;
    char *name;
    int wins;
    int draws;
    int losses;
    int gols_scored;
    int gols_conceded;


};

Team *team_create(int id, const char *name) {
 Team *team = malloc(sizeof(Team));

    if (team == NULL) 
    
    return NULL;

    if (name == NULL) {

        name = "";

    }

    team->name = malloc(strlen(name) + 1);

    if (team->name == NULL) {

        free(team);

        return NULL;
    }
    
    strcpy(team->name, name);

    team->id = id;
    team->wins = 0;
    team->draws = 0;
    team->losses = 0;
    team->gols_scored = 0;
    team->gols_conceded = 0;

    return team;

}
    int team_get_id(const Team *team) {
        return team-> id;
    }
    const char *team_get_name(const Team *team) {
        return team->name;
    }
    int team_get_wins(const Team *team) {
        return team->wins;
    }
    int team_get_draws(const Team *team) {
        return team->draws;
    }
    int team_get_losses(const Team *team) {
        return team->losses;
    }
    int team_get_gols_scored(const Team *team) {
        return team->gols_scored;
    }
    int team_get_gols_conceded(const Team *team) {
        return team->gols_conceded;
    }

    void team_destroy(Team *team) {

        if (team == NULL) 
        return;
        free(team->name);
        free(team);
    }
