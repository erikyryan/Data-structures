#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int x;
    struct Node* next;
    struct Node* prev;
}Node;

void deallocate(Node** tail, Node** head){
    if(*tail ==NULL){
        return;
    } 

    Node* curr = *tail;
    while( curr->next != NULL){
        curr = curr->next;
        free(curr->prev);
    }
    free(curr);

    *tail = NULL;
    *head = NULL;
}

void insert_beggining(Node** tail, int value){
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL){
        exit(1);
        return;
    }

    new_node->x = value;
    new_node->prev = NULL;
    new_node->next = *tail;
    (*tail)->prev = new_node;
    *tail = new_node;

}

void insert_end(Node** head, int value){
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL){
        exit(3);
        return;
    }
    new_node->x = value;
    new_node->next = NULL;
    new_node->prev = *head;
    (*head)->next = new_node;
    *head = new_node;
}

void insert_after(Node* node, int value){
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL){
        exit(5);
        return;  
    }  
    new_node->x = value;
    new_node->prev = node;
    new_node->next = node-> next;
    if(node->next != NULL){
        node->next->prev = new_node;
    }
    node->next = new_node; 
}

void remove_node(Node* node){
    if(node->prev != NULL){
        node->prev->next = node->next;        
    }
    if(node->next != NULL){
        node->next->prev = node->prev;
    }

    free(node);
}

void init(Node** tail, Node** head,int value){
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL){
        exit(2);
        return;
    }

    new_node->x = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    *tail = new_node;
    *head = new_node;
}

Node* find_node(Node* tail,int value){
    for(Node* curr = tail; curr != NULL; curr = curr->next){
        if(curr->x ==value){
            return curr;
        }
    }
    return NULL;
}

Node* find_node_recursive(Node* node, int value){
    if(node == NULL){
        return node;
    }
    if(node->x == value){
        return node;
    }
    return find_node_recursive(node->next,value);
}

void reverse(Node** tail,Node** head){
    Node* curr = *tail;

    while(curr != NULL){
        Node* next = curr-> next;
        
        curr->next = curr->prev;
        curr->prev = next;

        curr = next;
    }

    Node* aux = *tail;
    *tail = *head;
    *head = aux;

}

int main(){
    Node* tail = NULL;
    Node* head = tail;
    init(&tail,&head,324);
    for(int i = 1; i <= 10;i++){
        insert_beggining(&tail,i);    
    }
   
    Node* aux = tail->next;
    remove_node(tail);
    tail = aux;

    reverse(&tail,&head);

    for(Node* curr = tail; curr != NULL; curr = curr->next){
        printf("%d\n",curr->x);
    }

    Node* found = find_node_recursive(tail,23); // se o elemento nao existir ele dá  Segmentation fault (core dumped)
    
    if(found == NULL){
        printf("No node was found\n");
    }else{
        printf("value: %d , pointer: %p \n",found->x,found->next);        
    }

    deallocate(&tail,&head);
    return 0;
}