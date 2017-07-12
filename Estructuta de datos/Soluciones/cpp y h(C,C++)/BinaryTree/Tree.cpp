#include "Tree.h"

struct TreeNode{
    ET raiz;
    TreeNode* ti;
    TreeNode* td;
};

Tree NodeT(ET root, Tree izq, Tree der){
    TreeNode* newT = new TreeNode;
    newT->raiz = root;
    newT->ti = izq;
    newT->td = der;

    return newT;
}

Tree EmptyT(){
    return NULL;
}

ET root(Tree t){
    return t->raiz;
}

Tree izq(Tree t){
    return t->ti;
}

Tree der(Tree t){
    return t->td;
}

void setRoot(ET root, Tree& t){
    t->raiz = root;
}

bool isEmptyT(Tree t){
    return t == NULL;
}
