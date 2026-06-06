//
// Created by aluno on 14/05/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libprg/libprg.h"

typedef struct noh {
    char* chave;
    int valor;
    noh_t* proximo;
}noh_t;

typedef struct dicionario {
    int tamanho;
    noh_t** vetor;

}dicionario_t;

dicionario_t* criar_dicionario(int m) {
    dicionario_t* d;
    if (m < 1) return NULL;

    d = malloc(sizeof(dicionario_t));
    d->vetor = malloc(sizeof(noh_t*) * m);

    for (int i = 0; i < m; i++) {
        d->vetor[i] = NULL;
    }
    d->tamanho = m;

    return d;
}

int hash(char* chave, int m) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += (i + 1) * chave[i];
    }
    return soma % m;
}

int inserir_hash(dicionario_t* d, char* chave, int valor) {
    int indice = hash(chave, d->tamanho);
    noh_t* no = malloc(sizeof(noh_t));
    if (no == NULL) return 1;

    no->chave = strdup(chave);
    if (no->chave == NULL) {
        free(no);
        return 1;
    }
    no->valor = valor;

    // Tratamento de colisões por encadeamento:
    // caso já existam elementos neste índice,
    // o novo nó é inserido no início da lista ligada.
    no->proximo = d->vetor[indice];
    d->vetor[indice] = no;
    return 0;
}

//Busca uma chave na tabela hash e recupera seu valor associado.
int buscar_hash(dicionario_t* d, char* chave, int* valor) {

    int indice = hash(chave, d->tamanho);

    noh_t* aux = d->vetor[indice];

    while (aux != NULL) {

        if (strcmp(aux->chave, chave) == 0) {

            *valor = aux->valor;

            return 0;
        }

        aux = aux->proximo;
    }

    return 1;
}

int remover_hash(dicionario_t* d, char* chave) {

    int indice = hash(chave, d->tamanho);

    noh_t* atual = d->vetor[indice];
    noh_t* anterior = NULL;

    while (atual != NULL) {

        if (strcmp(atual->chave, chave) == 0) {

            // Caso o nó seja o primeiro da lista
            if (anterior == NULL) {
                d->vetor[indice] = atual->proximo;
            }
            // Caso esteja no meio ou no final
            else {
                anterior->proximo = atual->proximo;
            }

            free(atual->chave);
            free(atual);

            return 0; // remoção realizada com sucesso
        }

        anterior = atual;
        atual = atual->proximo;
    }

    return 1; // chave não encontrada
}

void destruir_dicionario(dicionario_t* d) {

    if (d == NULL)
        return;

    for (int i = 0; i < d->tamanho; i++) {

        noh_t* atual = d->vetor[i];

        while (atual != NULL) {

            noh_t* prox = atual->proximo;

            free(atual->chave);
            free(atual);

            atual = prox;
        }
    }

    free(d->vetor);
    free(d);
}

void imprimir_hash(dicionario_t* d) {

    for (int i = 0; i < d->tamanho; i++) {

        noh_t* aux = d->vetor[i];

        while (aux != NULL) {

            printf("Chave: %s | Valor: %d\n",
                   aux->chave,
                   aux->valor);

            aux = aux->proximo;
        }
    }
}