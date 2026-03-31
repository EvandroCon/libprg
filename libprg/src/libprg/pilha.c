//
// Created by aluno on 17/03/2026.
//

#include <stdbool.h>
#include <stdlib.h>

typedef struct pilha {
    int* elementos;
    int topo;
    int capacidade;
} pilha_t;

pilha_t* criar_pilha(int capacidade) {
    pilha_t* pilha = malloc(sizeof(pilha_t));
    pilha->elementos = malloc(sizeof(int) * capacidade);
    pilha->topo = -1;
    pilha->capacidade = capacidade;

    return pilha;
}

int empilhar(pilha_t* pilha, int valor) {

    if (pilha->topo + 1>= pilha->capacidade) {
        pilha->capacidade *= 2;
        pilha->elementos = realloc(pilha->elementos, pilha->capacidade * sizeof(int));
    }

    pilha->topo++;
    pilha->elementos[pilha->topo] = valor;



    return 0;
}

int desempilhar(pilha_t* pilha) {

    if (pilha->topo < 0) {
        exit(EXIT_FAILURE);
    }
    int valor = pilha->elementos[pilha->topo];
    pilha->topo--;

    return valor;
}

int tamanho(pilha_t* pilha) {
    return pilha->topo + 1;
}

bool vazia(pilha_t* pilha) {
    return pilha->topo < 0;
}

int destruit_pilha(pilha_t* pilha) {
    free(pilha->elementos);
    free(pilha);
    return 0;
}