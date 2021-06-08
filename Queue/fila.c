#include "funcoes.h"

void inicializar( fila *f){
    f->tam = 0;
    f->inicio = NULL;
    f->fim = NULL;
}

int estarVazia(fila* f){
    if(f->inicio == NULL){
        return true;     
    }else{
        return false;
    }  
}

int adicionar(fila* f,int valor){
    NO* novo = malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;
          
    if(estarVazia(f) == true){
        f->inicio = novo;
    }else{
        f->fim->prox = novo;
    }  
    f->fim = novo;
    f->tam++;
}

void remover(fila* f){
    NO* lixo;
    lixo = f->inicio;
    f->inicio = f->inicio->prox;
    f->tam--;    
    free(lixo);
}

void imprimir(NO* inicio){
    if(inicio == NULL){
       printf("NULL\n");
    }else{
        printf("%d\n",inicio->valor);
        imprimir(inicio->prox);
    }
    
}
