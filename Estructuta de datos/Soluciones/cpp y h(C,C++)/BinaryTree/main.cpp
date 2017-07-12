#include <iostream>
#include "Tree.h"
#include "Stack.h"
#include "ArrayList.h"

using namespace std;

///Dado un arbol binario de enteros devuelve la suma entre sus elementos.
int sumarT(Tree t){
    int total = 0;
    Tree actual;
    Stack siguientes = emptyS();
    push(t,siguientes);

    while(not(isEmptyS(siguientes))){
        actual = splitTop(siguientes);

        if(not(isEmptyT(actual))){
            total+= root(actual);
            push(der(actual),siguientes);
            push(izq(actual),siguientes);
        }
    }
    destroyS(siguientes);
    return total;
}

///Dado un arbol binario devuelve su cantidad de elementos, es decir, el tamaño del  ́arbol (size en ingles).
int sizeT(Tree t){
    int total = 0;
    Tree actual;
    Stack siguientes = emptyS();
    push(t,siguientes);

    while(not(isEmptyS(siguientes))){
        actual = splitTop(siguientes);

        if(not(isEmptyT(actual))){
            total++;
            push(der(actual),siguientes);
            push(izq(actual),siguientes);
        }
    }
    destroyS(siguientes);
    return total;
}

///Dado un arbol de enteros devuelve un arbol con el doble de cada numero.
Tree mapDobleT(Tree t){
    if(isEmptyT(t)){
        return EmptyT();
    }else{
        return NodeT((root(t)*2),mapDobleT(izq(t)),mapDobleT(der(t)));
    }
}

///Dados un elemento y un arbol binario devuelve True si existe un elemento igual a ese en el arbol.
bool perteneceT(ELEM_TYPE x, Tree t){
    bool found = false;
    Tree actual;
    Stack siguientes = emptyS();
    push(t,siguientes);

    while(not(isEmptyS(siguientes))){
        actual = splitTop(siguientes);

        if(not(isEmptyT(actual))){
            found = found || root(actual);
            push(der(actual),siguientes);
            push(izq(actual),siguientes);
        }
    }
    destroyS(siguientes);
    return found;
}

int aparicionesT(ET x, Tree t){
    int total = 0;
    Tree actual;
    Stack siguientes = emptyS();
    push(t,siguientes);

    while(not(isEmptyS(siguientes))){
        actual = splitTop(siguientes);

        if(not(isEmptyT(actual))){
            if( x == root(actual))
                total++;
            push(der(actual),siguientes);
            push(izq(actual),siguientes);
        }
    }
    destroyS(siguientes);
    return total;
}

bool esHojaT(Tree t){
    if(not(isEmptyT(t)) && isEmptyT(izq(t)) && isEmptyT(der(t)))
        return true;
    return false;
}

///Dado un arbol devuelve su cantidad de hojas.
///Nota: una hoja (leaf en ingĺes) es un nodo que no tiene hijos.
int leaves(Tree t){
    int total = 0;
    Tree actual;
    Stack siguientes = emptyS();
    push(t,siguientes);

    while(not(isEmptyS(siguientes))){
        actual = splitTop(siguientes);

        if(not(isEmptyT(actual))){
            if(esHojaT(actual))
                total++;
            push(der(actual),siguientes);
            push(izq(actual),siguientes);
        }
    }
    destroyS(siguientes);
    return total;
}

///Dado un arbol devuelve su altura.
///Nota: la altura (height en ingles) de un arbol es la cantidad maxima de nodos entre la raiz
///y alguna de sus hojas. La altura de un arbol vacıo es cero y la de una hoja es 1.
//int heightT(Tree t){
//
//}

///Dado un arbol devuelve el arbol resultante de intercambiar el hijo izquierdo con el derecho,
///en cada nodo del arbol.
Tree espejoT(Tree t){
    if(isEmptyT(t)){
        return EmptyT();
    }else{
        return NodeT(root(t),espejoT(der(t)),espejoT(izq(t)));
    }
}

///Dado un arbol devuelve una lista que representa el resultado de recorrerlo en modo in-order.
///Nota: En el modo in-order primero se procesan los elementos del hijo izquierdo, luego la raiz
///y luego los elementos del hijo derecho.
ArrayList listInOrder(Tree t){
    ArrayList lista = crearArrayList();
    Tree actual;
    Stack siguientes = emptyS();
    push(t,siguientes);

    while(not(isEmptyS(siguientes))){
        actual = splitTop(siguientes);

        if(not(isEmptyT(actual))){
            if(not isEmptyT(izq(actual))){add(lista,root(izq(actual)));}
            add(lista,root(actual));
            if(not isEmptyT(der(actual))) {add(lista,root(der(actual)));}

            push(der(actual),siguientes);
            push(izq(actual),siguientes);
        }
    }
    destroyS(siguientes);
    return lista;
}

///Dados un numero n y un arbol devuelve una lista con los nodos de nivel n.
///Nota: El primer nivel de un arbol (su raız) es 0.
ArrayList levelN(int n, Tree t){
    if()
}

int main()
{
    Tree t = NodeT(5,(NodeT(50,EmptyT(),EmptyT())),
                     (NodeT(25,EmptyT(),EmptyT())));
    int x = sumarT(t);

    cout << x << endl;
    return 0;
}
