#include <iostream>
#include "Tree.h"
#define ELEM_TYPE Tree

using namespace std;

struct StackNode;
typedef StackNode* Stack;

Stack emptyS(); // crea una pila vacia, retorna NULL.

bool isEmptyS (Stack p); // indica con un booleano si el stack esta vacio.

// las funciones void le dan permiso al implementador de modificar el puntero.

void push (ELEM_TYPE e,Stack& s); // mete un elemento nuevo al tope de pila.

void pop (Stack& s); // saca un elemento de la pila.

ELEM_TYPE top (Stack s); //devuelve el elemento del tope de pila.

int lenS (Stack s); // devuelve un entero que indica el tamaño de la pila.

void printS (Stack s); //imprime un stack s.

Stack copyS (Stack s); //copia un stack s.

ELEM_TYPE splitTop(Stack& s);

void destroyS(Stack& s);

// el stack va a ser representado por un stackNode con dos campos, elemtype y next.




