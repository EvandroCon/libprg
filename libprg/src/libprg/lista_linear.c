//
// Created by aluno on 02/04/2026.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE_INICIAL 10

typedef struct lista_linear
{
    int* elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_linear_t;

lista_linear_t* criar_lista(bool ordenada)
{
    lista_linear_t* lista = malloc(sizeof(lista_linear_t));
    lista->elementos = malloc(sizeof(int) * CAPACIDADE_INICIAL);
    lista->tamanho = 0;
    lista->capacidade = CAPACIDADE_INICIAL;
    lista->ordenada = ordenada;

    return lista;
}

bool inserir(lista_linear_t* lista, int valor)
{
    if (lista->tamanho == lista->capacidade)
    {
        return false;
    }
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
    return true;
}

bool remover(lista_linear_t* lista, int valor)
{
    int posicao = -1;
    for (int i = 0; i < lista->tamanho; i++)
    {
        if (lista->elementos[i] == valor)
        {
            posicao = i;
            break;
        }
    }
    if (posicao == -1)
    {
        return false;
    }
    for (int i = posicao; i < lista->tamanho - 1; i++)
    {
        lista->elementos[i] = lista->elementos[i + 1];
    }
    lista->tamanho--;
    return true;
}

int buscar_linear(lista_linear_t* lista, int valor)
{
    for (int i = 0; i < lista->tamanho; i++)
    {
        if (lista->elementos[i] == valor)
        {
            return i;
        }
    }
    return -1;
}

int busca_binaria(lista_linear_t *lista, int valor)
{
    int inicio = 0;
    int fim = lista->tamanho - 1;
    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (lista->elementos[meio] == valor)
        {
            return meio;
        }
        if (valor < lista->elementos[meio])
        {
            fim = meio - 1;
        }
        else
        {
            inicio = meio + 1;
        }
    }
    return -1;
}

int tamanho_lista(lista_linear_t *lista)
{
    return lista->tamanho;
}

bool lista_cheia(lista_linear_t *lista)
{
    return lista->tamanho == lista->capacidade;
}

bool lista_vazia(lista_linear_t *lista)
{
    return lista->tamanho == 0;
}

void destruir_lista(lista_linear_t *lista)
{
    free(lista->elementos);
    free(lista);
}

void imprimir_lista(lista_linear_t *lista)
{
    for (int i = 0; i < lista->tamanho; i++)
    {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}


int primeiro_elemento(lista_linear_t *lista)
{
    if (lista->tamanho == 0)
    {
        return -1;
    }
    return lista->elementos[0];
}
