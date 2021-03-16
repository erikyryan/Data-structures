#include "tree.h"

struct tree{
    int value;
};

struct node{
    Tree tree;
    struct node* left;
    struct node* right;
};

Node* initialize(){
    return NULL;
}

Node* insert_tree(Node* root, int e){
    Tree tree_new;
    tree_new.value = e;

    if(root == NULL){
        Node* aux = malloc(sizeof(Node));
        aux->tree.value = e;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
    } else {
        if(tree_new.value > root->tree.value){
            root->right = insert_tree(root->right, e);
        } else if(tree_new.value< root->tree.value){
            root->left = insert_tree(root->left, e);
        }  
    }
    return root;
}

void print_tree(Node* root){
    if(root != NULL){
        printf("%d ",root->tree.value);
        print_tree(root->right);
        print_tree(root->left);
    }
}

void free_tree(Node* root){
    if(root != NULL){
        free_tree(root->right);
        free_tree(root->left);
        free(root);
    }
}

Node* search_tree(Node* root,int e){
    if(root != NULL){
        if(root->tree.value == e){ 
            return root;
        } else {
            if(e > root->tree.value){
                return search_tree(root->right, e);
            }else {
                return search_tree(root->left,e);
            }
        }
    }
    return NULL;
}

Node* minor_tree(Node* root){
    
    if(root != NULL){
        Node* aux = root;
        while(aux->left != NULL){
            aux = aux->left;
        }
        return aux;
    }
    return NULL;
}

Node* delete_tree(Node* root, int e){
    if(root != NULL){
        if(e > root->tree.value ){
            root->right = delete_tree(root->right,e);
        } else if(e < root->tree.value){
            root->left = delete_tree(root->left,e);

        }else { // quando o elemento for encontrado
            if(root->left == NULL && root->right == NULL){ // elemento é a folha
                free(root);
                return NULL;
            }else if(root->right != NULL && root->left == NULL){ // apenas um filho a direita
                Node* aux = root->right;
                free(root);
                return aux;
            }else if(root->left != NULL && root->right == NULL ){ // apenas um filho a esquerda
                Node* aux = root->left;
                free(root);
                return aux;
            }else { 
                Node* aux = minor_tree(root->right);
                Tree treeAux = aux->tree;
                root = delete_tree(root,treeAux.value); 
                root->tree = treeAux; 
                
            }    
        } 
        return root;
    }else return NULL;
}
