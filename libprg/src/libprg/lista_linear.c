//
// Created by aluno on 02/04/2026.
//

#include <stdbool.h>
#include <stdlib.h>

typedef struct lista_linear {
    int* elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_linear_t;

lista_linear_t* criar_lista(int capacidade) {
    lista_linear_t* lista = malloc(sizeof(lista_linear_t));
    lista->elementos = malloc(sizeof(int) * capacidade);
    lista->tamanho = 0;
    lista->ordenada = false;
    lista->capacidade = capacidade;
}
//criar_lista
//vazia_l
//inserir//
//remover//
//buscar//
//acessar//
//tamanho
//exibir
//ordenar//
