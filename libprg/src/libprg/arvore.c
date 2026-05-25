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

no_at* remover_no(no_at* raiz, int valor) {

    if (raiz == NULL) {
        return NULL;
    }

    // Procurar o valor
    if (valor < raiz->valor) {
        raiz->esquerda = remover_no(raiz->esquerda, valor);
    }

    else if (valor > raiz->valor) {
        raiz->direita = remover_no(raiz->direita, valor);
    }

    // Encontrou o nó
    else {

        // Caso 1: nó folha
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        }

        // Caso 2: apenas filho direito
        else if (raiz->esquerda == NULL) {
            no_at* temp = raiz->direita;
            free(raiz);
            return temp;
        }

        // Caso 2: apenas filho esquerdo
        else if (raiz->direita == NULL) {
            no_at* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Caso 3: dois filhos
        else {

            // Encontrar menor da direita
            no_at* temp = raiz->direita;

            while (temp->esquerda != NULL) {
                temp = temp->esquerda;
            }

            // Copiar valor
            raiz->valor = temp->valor;

            // Remover nó duplicado
            raiz->direita = remover_no(raiz->direita, temp->valor);
        }
    }

    return raiz;
}

no_at* buscar_no(no_at* raiz, int valor)
{
    // Não encontrou
    if (raiz == NULL) {
        return NULL;
    }

    // Encontrou
    else if (raiz->valor == valor) {
        return raiz;
    }

    // Procurar na esquerda
    else if (valor < raiz->valor) {
        return buscar_no(raiz->esquerda, valor);
    }

    // Procurar na direita
    else {
        return buscar_no(raiz->direita, valor);
    }
}

void destruir_arvore(no_at* raiz) {

    if (raiz != NULL) {

        destruir_arvore(raiz->esquerda);

        destruir_arvore(raiz->direita);

        free(raiz);
    }
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
        travessia_pre_ordem(raiz->esquerda);
        travessia_pre_ordem(raiz->direita);
    }
}

void travessia_pos_ordem(no_at* raiz) {
    if  (raiz != NULL) {
        travessia_pos_ordem(raiz->esquerda);
        travessia_pos_ordem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

