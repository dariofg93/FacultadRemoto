#include <iostream>

using namespace std;

struct TNode;
typedef TNode* Tree;

//Crea un arbol vacio.
Tree emptyT();

//Devuelve true si el arbol del parametro es vacio.
bool isEmptyT(Tree t);

//Devuelve el valor de la raiz del arbol.
int root(Tree t);

//Devuelve el hijo izquierdo del arbol del parametro.
Tree hijoIzq(Tree t);

//Devuelve el hijo derecho del arbol del parametro.
Tree hijoDer(Tree t);

//Devuelve un arbol con los datos pasados por parametro.
Tree armarT(int root, Tree l, Tree r);

