//
// Created by aluno on 19/05/2026.
//


#include <stdio.h>

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

void travessia_em_ordem(no_at* raiz) {
    if  (raiz != NULL) {
        travessia_em_ordem(raiz->esquerda);
        printf("%d ", raiz->valor);
        travessia_em_ordem(raiz->direita);
    }
}

void travessia_pre_ordem(no_at* raiz) {
    if  (raiz != NULL) {
        printf("%d ", raiz->valor);
        travessia_em_ordem(raiz->esquerda);
        travessia_em_ordem(raiz->direita);
    }
}

void travessia_pos_ordem(no_at* raiz) {
    if  (raiz != NULL) {
        travessia_em_ordem(raiz->esquerda);
        travessia_em_ordem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

// remover
// destruir
// travessia pre ordem
// travessia em ordem
// travessia pos ordem