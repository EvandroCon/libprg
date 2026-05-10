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
