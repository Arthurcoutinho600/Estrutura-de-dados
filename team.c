#include <stdlib.h>
#include <string.h>
#include "team.h"

struct time {

    int id;
    char *nome;
    int vitorias;
    int empates;
    int derrotas;
    int gols_marcados;
    int gols_sofridos;


}

Time *criar_time(int id, const char, *nome) {

    Time *t = malloc(sizeof(Time));

    if (t == NULL) return NULL;

    t->name = malloc(strlen(nome) + 1);

    if (t->name == NULL) {

        free(t);
        return NULL;
    }
    
    strcpy(t->nome, nome);

    t->id = id;
    t->vitorias = 0;
    t->empates = 0;
    t->derrotas = 0;
    t->gols_marcados = 0;
    t->gols_sofridos = 0;

    return t;
}
    int time_get_id(const Time *t) {
        return t-> id;
    }
    const char *time_get_nome(const Time *t) {
        return t->nome;
    }
    int time_get_vitorias(const Time *t) {
        return t->vitorias;
    }
    int time_get_empates(const Time *t) {
        return t->empates;
    }
    int time_get_derrotas(const Time *t) {
        return t->derrotas;
    }
    int time_get_gols_marcados(const Time *t) {
        return t->gols_marcados;
    }
    int time_get_gols_sofridos(const Time *t) {
        return t->gols_sofridos;
    }

    void time_destruir(Time *t) {

        if (t == NULL) return;
        free(t->nome);
        free(t);
    }
