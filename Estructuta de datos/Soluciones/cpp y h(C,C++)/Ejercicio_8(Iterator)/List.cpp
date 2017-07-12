#include <stdlib.h>
#include <iostream>
#include "List.h"

using namespace std;

/* INVARIANTES:
    + una lista nunca es NULL
    + length = 1 sii first = last */

struct List_str {
    Node* first;
    Node* last;
    int lenght;
};

List nil() {
    List_str* l = new List_str;
    l->first = NULL;
    l->last = NULL;
    l->lenght = 0;
    return l;
}

bool isNil(List l) {
    return l->first == NULL;
}

void cons(ELEM_TYPE x, List& l) {
    Node* n = new Node;
    n->value = x;

    if (l->first == NULL) {
        n->next = NULL;
        l->last = n;
    }
    else {
        n->next = l->first;
    }

    l->lenght++;
    l->first = n;
}

void snoc(List& l, ELEM_TYPE x) {
    Node* n = new Node;
    n->value = x;
    n->next = NULL;

    if (l->first == NULL) {
        l->first = n;
    }
    else {
        l->last->next = n;
    }

    l->lenght++;
    l->last = n;
}

ELEM_TYPE head(List l) {
    return l->first->value;
}

void mktail(List& l) {
    Node* tmp = l->first;
    l->first = l->first->next;
    delete tmp;
}

ELEM_TYPE splithead(List& l) {
    ELEM_TYPE e_tmp = l->first->value;
    Node* n_tmp = l->first;
    l->first = l->first->next;
    delete n_tmp;
    return e_tmp;
}

void printl(List l) {
    Node* tmp = l->first;
    cout << "[";

    while (tmp != NULL) {
        cout << tmp->value;

        if (tmp->next != NULL)
            cout << ",";

        tmp = tmp->next;
    }

    cout << "]" << endl;
}

void destroyl(List& l) {
    Node* curr = l->first;

    while (curr != NULL) {
        Node* curraux = curr;
        curr = curr->next;
        delete curraux;
    }

    delete l;
    l = NULL;
}

Iterator getiterator(List l) {
    return l->first;
}

