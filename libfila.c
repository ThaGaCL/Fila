#include "libfila.h"


Fila* filaCria(){
    Fila* f = malloc(sizeof(Fila));

    if(!f){
        printError("Erro! A fila não foi criada.");
        return NULL;
    }

    f->ini = NULL;
    f->fim = NULL;
    f->tam = 0;

    return f;
}

void filaLibera(Fila* f){
    Nodo* aux = f->ini;

    // Conditional jump or move depends on uninitialised value(s)
    // TODO: Descobrir o porque disso já que o aux é inicializado
    while(aux){
        Nodo* aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }

    free(f);
}

int filaVazia(Fila* f){
    return f->tam == 0;
}

int filaTamanho(Fila* f){
    return f->tam;
}

int filaQueue(Fila* f, int elem){
    if(!f){
        printError("Erro! A fila não existe.");
        return 0;
    }
    Nodo *novo = malloc(sizeof(Nodo));
    if(!novo){
        printError("Erro! O nodo não foi criado.");
        return 0;
    }
    novo->chave = elem;

    if(filaVazia(f)){
        f->ini = novo;
        f->fim = novo;
    }else{
        f->fim->prox = novo;
        f->fim = novo;
    }

    f->tam++;
    return 1;
}

int filaDequeue(Fila* f){
    if(!f){
        return printError("Erro! A fila não existe.");
    }
    if(filaVazia(f)){
        return printError("Erro! A fila está vazia.");
    }

    Nodo* aux = f->ini;

    f->ini = aux->prox;
    free(aux);
    f->tam--;

    return 1;
}

void filaImprime(Fila* f){
    Nodo* aux = f->ini;

    printf("Fila atual: ");
    for(int i = 0; i < f->tam; i++){
        printf("|");
        printf(" %d ", aux->chave);
        printf("|");
        aux = aux->prox;
    }
    printf("\n");

}