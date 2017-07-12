#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "List.h"

/* crea un iterador hacia una lista */
Iterator createiterator(List l);

/* dice si el iterador esta iterando el ultimo elemento (el siguiente es NULL) */
bool atend(Iterator it);

/* obtiene el elemento que esta siendo iterado
   PRECONDICION: parcial si termino el recorrido */
ELEM_TYPE getelem(Iterator it);

/* cambia el valor del elemento que esta siendo iterado
   PRECONDICION: parcial si termino el recorrido */
void setelem(ELEM_TYPE x, Iterator& it);

/* avanza hacia el proximo elemento a iterar
   PRECONDICION: parcial en atend = true */
void iterate(Iterator& it);

/* destruye un iterador */
void destriyit(Iterator& it);

#endif // _ITERATOR_H_


