//
// Created by aluno on 07/05/2026.
//
#include "libprg/libprg.h"

int* bubble_sort(int* vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    return vetor;
}

void insertion_sort(int* vetor, int tamanho)
{
    for (int i = 1; i < tamanho - 1; i++)
    {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave)
        {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

void selection_sort(int* vetor, int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            if (vetor[j] < vetor[min])
            {
                min = j;
            }
        }

        if (i != min)
        {
            int aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
}

int* merge(int* vetor, int esquerda, int meio, int direita) {
    int aux[direita - esquerda + 1];
    int i = esquerda, j = meio + 1, k = 0;
    while (i <= meio && j <= direita) {
        if (vetor[i] <= vetor[j]) {
            aux[k] = vetor[i];
            i = i + 1;
        }else {
            aux[k] = vetor[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i <= meio) {
        aux[k] = vetor[i];
        i = i + 1, k = k + 1;

    }
    while (j <= direita) {
        aux[k] = vetor[j];
        j = j + 1, k = k + 1;
    }
    for (i = esquerda; i <= direita; i++) {
        vetor[i] = aux[i - esquerda];
    }
    return vetor;
}

int* merge_sort(int* vetor, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        merge_sort(vetor, esquerda, meio);
        merge_sort(vetor, meio + 1, direita);
        merge(vetor, esquerda, meio, direita);
    }
    return vetor;
}


void trocar_posicao(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void particiona(int* vetor, int inicio, int fim)
{
    int pivo = vetor[fim];
    int i = inicio - 1;
    for (int j = inicio; j <= fim - 1; j++)
    {
        if (vetor[j] <= pivo)
        {
            i = i + 1;
            trocar_posicao(&vetor[i], &vetor[j]);
        }
    }
    i = i + 1;
    trocar_posicao(&vetor[i], &vetor[fim]);

}

void quick_sort (int* vetor, int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo = particiona(vetor, inicio, fim);
        quick_sort(vetor, inicio, pivo - 1);
        quick_sort(vetor, pivo + 1, fim);
    }

}