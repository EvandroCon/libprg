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

noavl_t* remover_noavl(noavl_t* raiz, int dado) {
    if (raiz == NULL) {
        return NULL;
    }

    // Procurar o valor
    if (dado < raiz->dado) {
        raiz->esquerda = remover_noavl(raiz->esquerda, dado);
    }

    else if (dado > raiz->dado) {
        raiz->direita = remover_noavl(raiz->direita, dado);
    }

    // Encontrou o nó
    else {
        // Caso 1: nó folha
        if ((raiz->esquerda == NULL || raiz->direita == NULL)) {// 1 ou 0 filhos
            noavl_t* temp = raiz->esquerda ? raiz->esquerda : raiz->direita;
            if (temp == NULL) { // 0 filhos
                free(raiz);
                return NULL;
            }
            free(raiz); // 1 filho
            return temp;
        }
        else { // 2 filhos
            // encontra o menor valor da subarvore da direita
            noavl_t* temp = raiz->direita;
            while (temp && temp->esquerda != NULL) {
                temp = temp->esquerda;
            }
            raiz->dado = temp->dado;
            raiz->direita = remover_noavl(raiz->direita, temp->dado);
            }
    }
    if (raiz != NULL) {
        raiz->altura = 1 + max(altura_avl(raiz->esquerda), altura_avl(raiz->direita));
        raiz = balancear(raiz);
    }
    return raiz;
}