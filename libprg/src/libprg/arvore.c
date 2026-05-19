//
// Created by aluno on 19/05/2026.
//

// no
//
// criar_no
// adicionar
// remover
// destruir
#include "libprg/libprg.h"
#include <stdlib.h>

typedef struct no_a {
    int valor;
    no_at *esquerda;
    no_at *direita;
}no_at;

no_at* criarNo_at(int valor){
    no_at *no = malloc(sizeof(no_at));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;

    return no;
}

no_at* adicionar_no_at(int valor, no_at* raiz) {

    if (raiz == NULL) {
        return criarNo_at(valor);
    }

    if (raiz->valor < valor) {
        raiz->direita = adicionar_no_at(valor, raiz->direita);
    }
    if (raiz->valor > valor) {
        raiz->esquerda = adicionar_no_at(valor, raiz->esquerda);
    }
    return raiz;
}