#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>


//PILHA
typedef struct pilha pilha_t;
pilha_t* criar_pilha(int capacidade);
int ler_topo(pilha_t* pilha);
int empilhar(pilha_t* pilha, int valor);
int desempilhar(pilha_t* pilha);
int tamanho(pilha_t* pilha);
bool vazia_p(pilha_t* pilha);
int destruir_pilha(pilha_t* pilha);


//FILA
typedef struct fila fila_t;
int ler_tamanho(fila_t* fila);
bool cheia(fila_t* fila);
bool vazia_f(fila_t* fila);
fila_t* criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);
int desenfileirar(fila_t* fila);
int destruir_fila(fila_t* fila);
int fim(fila_t* fila);
int inicio(fila_t* fila);

//LISTA
typedef struct lista_linear lista_linear_t;
lista_linear_t* criar_lista(bool ordenada);
#endif


//LISTA ENCADEADA
typedef struct no no_t;
typedef struct lista_encadeada lista_encadeada_t;
lista_encadeada_t* criar_lista_encadeada(bool ordenada);
void inserir_encadeada(lista_encadeada_t* lista, int dado);
bool remover_encadeada(lista_encadeada_t* lista, int dado);
no_t* buscar (lista_encadeada_t* lista, int dado);
void destruir_encadeada(lista_encadeada_t* lista);
int inicio_lista_encadeada(lista_encadeada_t* lista);
int tamanho_lista_encadeada(lista_encadeada_t* lista);
void imprimir_lista_encadeada(lista_encadeada_t* lista);

//Lista encadeada dupla
typedef struct nod nod_t;
nod_t* criar_lista_encadeada_dupla(int dado);
void inserir_encadeada_dupla(nod_t** inicio, int dado);
nod_t *buscar_encadeada_dupla(nod_t **inicio, int dado);
void destruir_encadeada_dupla(nod_t** inicio);
bool remover_encadeada_dupla(nod_t** inicio, int dado);

//ALGORITMOS DE ORDENAÇÃO
int* bubble_sort(int* vetor, int tamanho);
void insertion_sort(int* vetor, int tamanho);
void selection_sort(int* vetor, int tamanho);
int* merge_sort(int* vetor, int esquerda, int direita);
int* quick_sort (int* vetor, int inicio, int fim);

//TABELA DE DISPERSAO
typedef struct noh noh_t;
dicionario_t* criar_dicionario(int m);