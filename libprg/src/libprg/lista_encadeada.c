//
// Created by aluno on 28/04/2026.
//

#include <stdlib.h>
struct no_t;

typedef struct no {
    int dado;
    struct no_t* proximo;
}no_t;

no_t* criar_lista_encadeada(int dado) {
    no_t* no = malloc(sizeof(no_t));
    no->dado = (int) NULL;
    no->proximo = NULL;

    return no;
}


void inserir_encadeada(no_t* inicio, int dado) {

    no_t* novo = criar_lista_encadeada(dado);
    novo->proximo = *inicio;
    *inicio = novo;
}



// remover
// buscar
// destruir