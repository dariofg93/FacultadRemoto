#ifndef _LIST_H_
#define _LIST_H_

#define ELEM_TYPE int

struct Node {
    ELEM_TYPE value;
    Node* next;
};

struct List_str;

typedef Node* Iterator;
typedef List_str* List;

/* crea una lista vacia */
List nil();

/* dice si una lista esta vacia */
bool isNil(List l);

/* agrega un elemento x adelante de una lista l */
void cons(ELEM_TYPE x, List& l);

/* agrega un elemento x al final de una lista l */
void snoc(List& l, ELEM_TYPE x);

/* devuelve el primer elemento de una lista
   PRECONDICION: parcial si la lista no tiene elementos */
ELEM_TYPE head(List l);

/* destruye el primer elemento de una lista
   PRECONDICION: parcial si la lista no tiene elementos */
void mktail(List& l);

/* devuelve el primer elemento (por copia) y lo destruye
   PRECONDICION: parcial si la lista no tiene elementos */
ELEM_TYPE splithead(List& l);

/* printea una lista */
void printl(List l);

/* destruye una lista */
void destroyl(List& l);

/* crea un iterador hacia una lista */
Iterator getiterator(List l);

#endif // _LIST_H_
