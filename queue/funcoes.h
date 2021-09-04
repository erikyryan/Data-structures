#include <stdlib.h>
#include <stdio.h>

#define true 1
#define false 0

struct no{
    int valor;
    struct no* prox;
};
typedef struct no NO;

struct fila{
    int tam;
    NO* inicio;
    NO* fim;
};
typedef struct fila fila;

void inicializar( fila* f); // função para iniciar uma fila

int estarVazia(fila* f); // verifica a lista

int adicionar(fila* f,int valor); //adicionar um novo nó na fila

void remover(fila* f); // remover um nó da fila( sempre do inicio)

void imprimir(NO* inicio);