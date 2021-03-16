#include "tree.h"

int main(){
    Node* root = initialize();
    root = insert_tree(root, 10);
    root = insert_tree(root, 4);
    root = insert_tree(root, 3);
    root = insert_tree(root, 2);
    root = insert_tree(root, 6);
    root = insert_tree(root, 8);
    root = insert_tree(root, 10);
    root = insert_tree(root, 23);
    root = insert_tree(root, 93);
    root = insert_tree(root, 81);
    root = insert_tree(root, 32);
    printf("Antes de remover: ");
    print_tree(root);

    root = delete_tree(root,10);
    printf("\nDepois de remover: ");
    print_tree(root);

    root = search_tree(root,32);
    if(root == NULL) printf("\no elemento nao encontrado\n");
    else printf("\nelemento encontrado!!\n");

    free_tree(root);
    return 0;
}