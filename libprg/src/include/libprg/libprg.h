#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H



typedef struct pilha pilha_t;
pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t* pilha, int* valor);
int desempilhar(pilha_t* pilha);
int tamanho(pilha_t* pilha);
bool vazia(pilha_t* pilha);
int destruit_pilha(pilha_t* pilha);
#endif