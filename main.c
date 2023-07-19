#include "libfila.h"

int main(){
    Fila* f = filaCria();

    filaImprime(f);
    for(int i = 0; i < 10; i++){
        filaQueue(f, i);
        filaImprime(f);
    }

    for(int i = 0; i < 10; i++){
        filaDequeue(f);
        filaImprime(f);
    }

    filaDequeue(f);// Erro fila vazia


    filaLibera(f);

    return 0;
}