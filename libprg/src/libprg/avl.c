//
// Created by aluno on 26/05/2026.
//

#include <stdlib.h>

#include "libprg/libprg.h"

#define max(a, b) (a > b) ? a : b)

typedef struct noavl {
    int dado;
    noavl_t* esquerda;
    noavl_t* direita;
    int altura;
}noavl_t;


noavl_t* criarNoalv_t(int valor){
    noavl_t* no = malloc(sizeof(noavl_t));
    no->dado = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 0;

    return no;
}

int altura_avl(noavl_t* raiz) {
    if (raiz == NULL) return 0;

    return raiz->altura;
}

int fator_balaceamento(noavl_t* raiz) {
    if (raiz == NULL) return 0;

    return altura_avl(raiz->esquerda) - altura_avl(raiz->direita);
}

noavl_t* adicionar_noavl(int dado, noavl_t* raiz) {

    if (raiz == NULL) {
        return criarNoalv_t(dado);
    }

    if (raiz->dado < dado) {
        raiz->direita = adicionar_noavl(dado, raiz->direita);
    }
    if (raiz->dado > dado) {
        raiz->esquerda = adicionar_noavl(dado, raiz->esquerda);
    }
    return raiz;
}

noavl_t* rotacao_dupla_direita(noavl_t* v) {
    v->direita = rotacao_direita(v->direita);
    return rotacao_esquerda(v);
}
//rotacao direita
//rotacao dupla direita
noavl_t* rotacao_esquerda(noavl_t* v) {
    noavl_t* u = v->direita;
    noavl_t* t2 = u->esquerda;

    u->esquerda = v;
    v->direita = t2;

    v->altura = max(altura_avl(v->esquerda), altura_avl(v->direita)) + 1;
    u->altura = max(altura_avl(u->esquerda), altura_avl(u->direita)) + 1;

    return u;
}

noavl_t* rotacao_direita(noavl_t* v) {
    noavl_t* u = v->esquerda;
    noavl_t* t2 = u->direita;

    u->esquerda = v;
    v->direita = t2;

    v->altura = max(altura_avl(v->esquerda), altura_avl(v->direita)) + 1;
    u->altura = max(altura_avl(u->esquerda), altura_avl(u->direita)) + 1;

    return u;
}

noavl_t* balancear(noavl_t* v) {
    int fb = fator_balanceado(v);
}
//rotacao dupla esquerda
//balancear