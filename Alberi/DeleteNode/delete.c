#include "tree.h"

Node* DeleteBstNode(Node* n, const ElemType* key) {
    if (n == NULL) {
        // Albero vuoto o nodo non trovato
        return NULL;
    }

    int cmp = ElemCompare(key, &(n->value));

    if (cmp < 0) {
        // La chiave è minore del valore del nodo corrente, ricorsione sulla sottoalbero sinistro
        n->left = DeleteBstNode(n->left, key);
    }
    else if (cmp > 0) {
        // La chiave è maggiore del valore del nodo corrente, ricorsione sulla sottoalbero destro
        n->right = DeleteBstNode(n->right, key);
    }
    else {
        // La chiave corrisponde al valore del nodo corrente, procediamo alla rimozione
        if (TreeIsLeaf(n)) {
            // Nodo foglia, eliminazione diretta
            TreeDelete(n);
            n = NULL;
        }
        else if (n->left == NULL) {
            // Il nodo ha solo un sottoalbero destro, sostituzione con il suo sottoalbero destro
            Node* temp = n;
            n = n->right;
            TreeDelete(temp);
        }
        else if (n->right == NULL) {
            // Il nodo ha solo un sottoalbero sinistro, sostituzione con il suo sottoalbero sinistro
            Node* temp = n;
            n = n->left;
            TreeDelete(temp);
        }
        else {
            // Il nodo ha entrambi i sottoalberi, troviamo il successore in-order
            Node* successor = n->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }

            // Copiamo il valore del successore nel nodo corrente
            n->value = ElemCopy(&(successor->value));

            // Eliminiamo il successore
            n->right = DeleteBstNode(n->right, &(successor->value));
        }
    }

    return n;
}