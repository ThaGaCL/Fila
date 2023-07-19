#ifndef LIBFILA_H
#define LIBFILA_H

#include <stdio.h>
#include <stdlib.h>
#include "aux.h"

typedef struct nodo{
    int chave;
    struct nodo *prox;
}Nodo;

typedef struct fila{
    Nodo *ini;
    Nodo *fim;
    int tam;
}Fila;


//Cria uma fila vazia e a retorna, se falhar retorna NULL.
Fila* filaCria();

// Limpa a fila e libera a memória
void filaLibera(Fila* f);

// Retorna 1 se estiver vazia e 0 caso contrario
int filaVazia (Fila* f);

// Retorna a quantidade de elementos na fila
// Precisa? Talvez não já que o campo f->tam existe
int filaTamanho (Fila* f);

// Insere o elemento no tail
// Retorna 1 se tiver sucesso e 0 caso contrario
int filaQueue (Fila* f, int elem);

// Remove o head da fila e o retorna
// Retorna -1 caso contrario
int filaDequeue (Fila* f);

// FUNÇÃO DE TESTE
// APAGAR
void filaImprime (Fila* f);


#endif