#include <stdlib.h>

#include "tree.h"
extern const ElemType* BstTreeMin(const Node* n);
extern const ElemType* TreeMin(const Node* n);
// Per ogni nodo (elemento `i`-esimo del vettore) considero come figlio sinistro
// l'elemento del vettore di indice `i * 2 + 1`, e come figlio destro l'elemento
// di indice `i * 2 + 2`.
Node* TreeCreateFromVectorRec(const int* v, size_t v_size, int i) {
    if (i >= (int)v_size) {
        return NULL;
    }

    Node* l = TreeCreateFromVectorRec(v, v_size, i * 2 + 1);
    Node* r = TreeCreateFromVectorRec(v, v_size, i * 2 + 2);

    return TreeCreateRoot(&v[i], l, r);
}

Node* TreeCreateFromVector(const int* v, size_t v_size) {
    return TreeCreateFromVectorRec(v, v_size, 0);
}

int main(void) {
    int v[] = {73,24,12,3,-4,3,81};
    size_t v_size = sizeof(v) / sizeof(int);
    Node* tree = TreeCreateEmpty();

    TreeWriteStdoutPreOrder(tree);
    TreeWriteStdoutInOrder(tree);
    TreeWriteStdoutPostOrder(tree);

    tree = TreeCreateFromVector(v, v_size);
    ElemType a[] = { 5,-4 };
    tree->left->left->left = TreeCreateRoot(&a[0], NULL, NULL);
    tree->left->left->right = TreeCreateRoot(&a[1], NULL, NULL);
    TreeWriteStdoutPreOrder(tree);
    TreeWriteStdoutInOrder(tree);
    TreeWriteStdoutPostOrder(tree);
    ElemType* should_be_res = &tree->left->right->value;
    ElemType* res = TreeMin(tree);
    printf("MIN: %d\n", *res);
    TreeDelete(tree);

    return EXIT_SUCCESS;
}