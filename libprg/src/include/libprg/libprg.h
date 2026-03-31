#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H


//PILHA
typedef struct pilha pilha_t;
pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t* pilha, int* valor);
int desempilhar(pilha_t* pilha);
int tamanho(pilha_t* pilha);
bool vazia_p(pilha_t* pilha);
int destruit_pilha(pilha_t* pilha);


//FILA
typedef struct fila fila_t;
bool cheia(fila_t* fila);
bool vazia_f(fila_t* fila);
fila_t* criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);
int destruir_fila(fila_t* fila);
#endif