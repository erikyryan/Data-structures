#include "funcoes.h"

int main(){
    fila* f = malloc(sizeof(fila));
    inicializar(f);
    adicionar(f,3);
    adicionar(f,5);
    adicionar(f,32);
    adicionar(f,7);
    remover(f);
    adicionar(f,12);
    adicionar(f,51);
    adicionar(f,16);
    remover(f);
    imprimir(f->inicio);
    printf("O primeiro da fila: %d (inicio)\n",f->inicio->valor);
    printf("O ultimo da fila: %d (fim)\n",f->fim->valor);  

    return 0;
}