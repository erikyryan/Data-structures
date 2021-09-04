#include <stdio.h>
#include <stdlib.h>

typedef struct tree Tree;

typedef struct node Node;

Node* initialize(); //inicializar 

Node* insert_tree(Node* root, int e); // inserir 

void print_tree(Node* root); // printar 

void free_tree(Node* root); // liberar da memoria

Node* search_tree(Node* root,int e); // buscar um elemento

Node* minor_tree(Node* root); // pegar o menor a esquerda na folha da arvore

Node* delete_tree(Node* root, int e); //remover o elemento