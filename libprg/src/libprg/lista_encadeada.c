//
// Created by aluno on 28/04/2026.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "libprg/libprg.h"
struct no_t;

typedef struct no {
    int dado;
    struct no* proximo;
}no_t;

typedef struct lista_encadeada {
    no_t* inicio;
    bool ordenada;
}lista_encadeada_t;

no_t* criar_no(int dado) {
    no_t* no = malloc(sizeof(no_t));
    if (no == NULL)
    {
        return NULL;
    }
    no->dado = dado;
    no->proximo = NULL;

    return no;
}

lista_encadeada_t* criar_lista_encadeada(bool ordenada) {
    lista_encadeada_t* lista = malloc(sizeof(lista_encadeada_t));
    lista->inicio = NULL;
    lista->ordenada = ordenada;

    return lista;
}

void inserir_encadeada(lista_encadeada_t* lista, int dado) {

    no_t* novo = criar_no(dado);

    novo->proximo = lista->inicio;
    lista->inicio = novo;
}


no_t* buscar (lista_encadeada_t* lista, int dado) {
    no_t* atual = lista->inicio;

    while (atual != NULL) {
        if (atual->dado == dado) return atual;
        atual = atual->proximo;
    }

    return NULL;
}


bool remover_encadeada(lista_encadeada_t* lista, int dado) {

    no_t* atual = lista->inicio;
    no_t* anterior = NULL;

    while (atual != NULL) {
        if (atual->dado == dado) {
            if (anterior == NULL) lista->inicio = atual->proximo;
            else anterior->proximo = atual->proximo;

            free(atual);
            return true;

        }

        anterior = atual;
        atual = atual->proximo;
    }
    return false;

}

void destruir_encadeada(lista_encadeada_t* lista) {

    no_t* atual = lista->inicio;

    while (atual != NULL) {

        no_t* proximo = atual->proximo;

        free(atual);

        atual = proximo;
    }

    free(lista);
}

int inicio_lista_encadeada(lista_encadeada_t* lista) {
    if (lista == NULL) {
        printf("Lista inexistente\n");
        return -1;
    }

    if (lista->inicio == NULL) {
        printf("Lista vazia\n");
        return -1;
    }

    return lista->inicio->dado;

}

int tamanho_lista_encadeada(lista_encadeada_t* lista) {

    if (lista == NULL)
        return 0;

    int tamanho = 0;

    no_t* atual = lista->inicio;

    while (atual != NULL) {

        tamanho++;

        atual = atual->proximo;
    }

    return tamanho;
}