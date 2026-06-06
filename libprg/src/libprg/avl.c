//
// Created by aluno on 26/05/2026.
//

#include <stdio.h>
#include <stdlib.h>

#include "libprg/libprg.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct noavl {
    int dado;
    noavl_t* esquerda;
    noavl_t* direita;
    int altura;
}noavl_t;

noavl_t* criarNoavl_t(int valor){
    noavl_t* no = malloc(sizeof(noavl_t));
    no->dado = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 0;

    return no;
}

int altura_avl(noavl_t* raiz) {
    if (raiz == NULL) return -1;  // NULL = -1, folha = 0
    return raiz->altura;
}

int fator_balanceamento(noavl_t* raiz) {
    if (raiz == NULL) return 0;

    return altura_avl(raiz->esquerda) - altura_avl(raiz->direita);
}

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

    u->direita = v;
    v->esquerda = t2;

    v->altura = 1 + max(
        altura_avl(v->esquerda),
        altura_avl(v->direita)
    );

    u->altura = 1 + max(
        altura_avl(u->esquerda),
        altura_avl(u->direita)
    );

    return u;
}

noavl_t* rotacao_dupla_esquerda(noavl_t* v) {
    v->esquerda = rotacao_esquerda(v->esquerda);
    return rotacao_direita(v);
}

noavl_t* rotacao_dupla_direita(noavl_t* v) {
    v->direita = rotacao_direita(v->direita);
    return rotacao_esquerda(v);
}

noavl_t* balancear(noavl_t* v) {
    int fb = fator_balanceamento(v);

    if (fb > 1) {  // Pesado à esquerda
        if (fator_balanceamento(v->esquerda) >= 0)
            return rotacao_direita(v);          // Caso Esquerda-Esquerda
        else
            return rotacao_dupla_esquerda(v);   // Caso Esquerda-Direita
    } else if (fb < -1) {  // Pesado à direita
        if (fator_balanceamento(v->direita) <= 0)
            return rotacao_esquerda(v);         // Caso Direita-Direita
        else
            return rotacao_dupla_direita(v);    // Caso Direita-Esquerda
    }
    return v;
}

//inserir
noavl_t* adicionar_noavl(int dado, noavl_t* raiz) {

    if (raiz == NULL) {
        return criarNoavl_t(dado);
    }

    if (raiz->dado < dado) {
        raiz->direita = adicionar_noavl(dado, raiz->direita);
    }
    else if (raiz->dado > dado) {
        raiz->esquerda = adicionar_noavl(dado, raiz->esquerda);
    }
    raiz->altura = 1 + max(
        altura_avl(raiz->esquerda),
        altura_avl(raiz->direita)
    );

    return balancear(raiz);
}

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

// Pré-ordem: raiz → esquerda → direita
void preordem(noavl_t* raiz) {
    if (raiz == NULL) return;

    printf("%d ", raiz->dado);
    preordem(raiz->esquerda);
    preordem(raiz->direita);
}

// Em-ordem: esquerda → raiz → direita (resulta em ordem crescente)
void emordem(noavl_t* raiz) {
    if (raiz == NULL) return;

    emordem(raiz->esquerda);
    printf("%d ", raiz->dado);
    emordem(raiz->direita);
}

// Pós-ordem: esquerda → direita → raiz
void posordem(noavl_t* raiz) {
    if (raiz == NULL) return;

    posordem(raiz->esquerda);
    posordem(raiz->direita);
    printf("%d ", raiz->dado);
}