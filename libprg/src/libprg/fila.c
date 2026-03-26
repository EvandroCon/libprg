//
// Created by vando on 26/03/2026.
//

#include <stdlib.h>

typedef struct fila
{
    int* elementos;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
}fila_t;

fila_t* criar_fila(int capacidade)
{
    fila_t* fila = (fila_t*) malloc(sizeof(fila_t));
    fila->elementos = malloc(sizeof(int) * capacidade);
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    fila->capacidade = capacidade;

    return fila;

}
void enfileirar(fila_t* fila, int valor)
{
    if (fila->tamanho >= fila->capacidade) exit(EXIT_FAILURE);

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

// desenfileirar
// inicio
// fim
// vazia
// cheia

int destruir_fila(fila_t* fila)
{
    free(fila->elementos);
    free(fila);
    return 0;
}