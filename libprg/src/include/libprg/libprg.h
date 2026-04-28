#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H


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
no_t* criar_lista_encadeada(int dado){
    int dado;
    no_t* proximo;
};
void inserir_encadeada(no_t* inicio, int dado);
