#include <iostream>
#include "Tree.h"

using namespace std;

//1. Dado un arbol binario de enteros devuelve la suma entre sus elementos.
int sumarT(Tree t){
    if(isEmptyT(t)){
        return 0;
    }else{
        return (root(t) + sumarT(hijoIzq(t)) + sumarT(hijoDer(t)));
    }
}

//2. Dado un arbol binario devuelve su cantidad de elementos, es decir, el tamaño del  ́arbol (size en ingles).
int sizeT(Tree t){
    if(isEmptyT(t)){
        return 0;
    }else{
        return (1 + sizeT(hijoIzq(t)) + sizeT(hijoDer(t)));
    }
}

//3. Dado un arbol de enteros devuelve un arbol con el doble de cada numero.
Tree mapDobleT(Tree t){
    if(isEmptyT(t)){
        return emptyT();
    }else{
        return armarT(root(t)*2,mapDobleT(hijoIzq(t)),mapDobleT(hijoDer(t)));
    }
}

//4. Dado un arbol de direcciones t devuelve un arbol con la direccion opuesta para cada elemento de t.
//Nota: Utilizar el tipo Dir ya definido.
//mapOpuestoT :: Tree Dir -> Tree Dir

//5. Dado un arbol de palabras devuelve un arbol con la longitud de cada palabra.
//mapLongitudT :: Tree String -> Tree Int

//6. Dados un elemento y un arbol binario devuelve True si existe un elemento igual a ese en el arbol.
bool perteneceT(Tree t, int n){
    if(isEmptyT(t)){
        return false;
    }else{
        return (root(t)==n || perteneceT(hijoIzq(t),n) || perteneceT(hijoDer(t),n));
    }
}

//7. Dados un elemento e y un arbol binario devuelve la cantidad de elementos del arbol que son iguales a e.
int aparicionesT(Tree t, int n){
    if(isEmptyT(t)){
        return 0;
    }else{
        if(root(t)==n){
            return (1 + aparicionesT(hijoIzq(t),n) + aparicionesT(hijoIzq(t),n));
    }   else{                                                   //CUENTA MAL
            return (aparicionesT(hijoIzq(t),n) + aparicionesT(hijoIzq(t),n));
        }
    }
}

int main()
{
    Tree t1 = emptyT();
    Tree t2 = armarT(1,t1,t1);
    Tree t3 = armarT(5,t1,t2);
    Tree t4 = armarT(10,armarT(2,t1,armarT(3,t1,t1)),t2);

    cout << aparicionesT(t4,3) << endl;
    return 0;
}
