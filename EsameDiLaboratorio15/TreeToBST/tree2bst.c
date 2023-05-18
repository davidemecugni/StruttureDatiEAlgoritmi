//Time 32m
#include "tree.h"

//Insert ordered from the examples page
Node* TreeInsertBinOrd(const ElemType* e, Node* n) {
    if (TreeIsEmpty(n)) {
        return TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
    }
    Node* root = n;

    while (true) {
        if (ElemCompare(e, TreeGetRootValue(n)) <= 0) {
            if (TreeIsEmpty(TreeLeft(n))) {
                n->left = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
                break;
            }
            else {
                n = TreeLeft(n);
            }
        }
        else {
            if (TreeIsEmpty(TreeRight(n))) {
                n->right = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
                break;
            }
            else {
                n = TreeRight(n);
            }
        }
    }

    return root;
}
Node* Tree2BstRec(const Node* t, Node* res_tree) {
    //If the node is empty, we just return the past result
    if (TreeIsEmpty(t)) {
        return res_tree;
    }
    //If it's a leaf, we insert the node and return the tree
    if (TreeIsLeaf(t)) {
        res_tree = TreeInsertBinOrd(&t->value, res_tree);
        return res_tree;
    }
    //In order visit
    res_tree = Tree2BstRec(t->left, res_tree);
    res_tree = TreeInsertBinOrd(&t->value, res_tree);
    res_tree = Tree2BstRec(t->right, res_tree);
    return res_tree;

}
Node* Tree2Bst(const Node* t) {
    Node* res = TreeCreateEmpty();
    if (!TreeIsEmpty(t)) {
        res = Tree2BstRec(t, res);
    }
    return res;
}