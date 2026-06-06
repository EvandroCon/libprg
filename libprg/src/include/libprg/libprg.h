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

//LISTA LINEAR
typedef struct lista_linear lista_linear_t;
lista_linear_t* criar_lista(bool ordenada);
bool inserir(lista_linear_t* lista, int valor);
bool remover(lista_linear_t* lista, int valor);
int buscar_linear(lista_linear_t* lista, int valor);
int busca_binaria(lista_linear_t *lista, int valor);
int tamanho_lista(lista_linear_t *lista);
bool lista_cheia(lista_linear_t *lista);
bool lista_vazia(lista_linear_t *lista);
void destruir_lista(lista_linear_t *lista);
void imprimir_lista(lista_linear_t *lista);
int primeiro_elemento(lista_linear_t *lista);



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

//LISTA ENCADEADA DUPLA
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
typedef struct dicionario dicionario_t;
dicionario_t* criar_dicionario(int m);
int buscar_hash(dicionario_t* d, char* chave, int* valor);
int remover_hash(dicionario_t* d, char* chave);
int inserir_hash(dicionario_t* d, char* chave, int valor);
void imprimir_hash(dicionario_t* d);
void destruir_dicionario(dicionario_t* d);



//ARVORE
typedef struct no_a no_at;
no_at* criarNo_at(int valor);
no_at* adicionar_no_at(int valor, no_at* raiz);
no_at* remover_no(no_at* raiz, int valor);
no_at* buscar_no(no_at* raiz, int valor);
void destruir_arvore(no_at* raiz);
void travessia_em_ordem(no_at* raiz);
void travessia_pre_ordem(no_at* raiz);
void travessia_pos_ordem(no_at* raiz);
int maior_valor(no_at *raiz);
int menor_valor(no_at *raiz);
int altura(no_at *raiz);
#endif

//ARVORE AVL
typedef struct noavl noavl_t;
noavl_t* criarNoavl_t(int valor);
int altura_avl(noavl_t* raiz);
noavl_t* balancear(noavl_t* v);
int fator_balaceamento(noavl_t* raiz);
noavl_t* rotacao_esquerda(noavl_t* v);
noavl_t* rotacao_direita(noavl_t* v);
noavl_t* rotacao_dupla_direita(noavl_t* v);
noavl_t* rotacao_dupla_esquerda(noavl_t* v);
noavl_t* adicionar_noavl(int dado, noavl_t* raiz);
noavl_t* remover_noavl(noavl_t* raiz, int dado);