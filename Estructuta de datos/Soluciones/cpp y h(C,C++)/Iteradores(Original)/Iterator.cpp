#include <stdlib.h>
#include "Iterator.h"

Iterator createiterator(List l) {
/* NOTA: solo llama a getiterator de la interfaz de list, se agrego aca para que este en la interfaz */
    return getiterator(l);
}

bool atend(Iterator it) {
    return it == NULL;
}

ELEM_TYPE getelem(Iterator it) {
    return it->value;
}

void setelem(ELEM_TYPE x, Iterator& it) {
    it->value = x;
}

void iterate(Iterator& it) {
    it = it->next;
}

void destriyit(Iterator& it) {
    it = NULL;
}
