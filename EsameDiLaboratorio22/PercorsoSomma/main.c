
#include <stdlib.h>
#include "tree.h"
extern bool PercorsoSomma(Node* t, const ElemType* target);

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
    int v[] = { 1,2,2};
    size_t v_size = sizeof(v) / sizeof(int);
    Node* tree = TreeCreateEmpty();

    TreeWriteStdoutPreOrder(tree);
    TreeWriteStdoutInOrder(tree);
    TreeWriteStdoutPostOrder(tree);

    tree = TreeCreateFromVector(v, v_size);
    ElemType val = 2;
    printf("\n\nPossible route with sum %d: %s\n\n", val, (PercorsoSomma(tree, &val) ? "true" : "false"));

    TreeWriteStdoutPreOrder(tree);
    TreeWriteStdoutInOrder(tree);
    TreeWriteStdoutPostOrder(tree);

    TreeDelete(tree);

    return EXIT_SUCCESS;
}