#include "Tree.h"

struct TNode {
    int raiz;
    TNode* left;
    TNode* right;
};

//Crea un arbol vacio.
Tree emptyT(){
    return NULL;
}

//Devuelve true si el arbol del parametro es vacio.
bool isEmptyT(Tree t){
    return (t==NULL);
}

//Devuelve el valor de la raiz del arbol.
int root(Tree t){
    return (t->raiz);
}

//Devuelve el hijo izquierdo del arbol del parametro.
Tree hijoIzq(Tree t){
    return (t->left);
}

//Devuelve el hijo derecho del arbol del parametro.
Tree hijoDer(Tree t){
    return (t->right);
}

//Devuelve un arbol con los datos pasados por parametro.
Tree armarT(int root, Tree l, Tree r){
    Tree newT = new TNode;
    newT->raiz = root;
    newT->left = l;
    newT->right = r;

    return newT;
}
