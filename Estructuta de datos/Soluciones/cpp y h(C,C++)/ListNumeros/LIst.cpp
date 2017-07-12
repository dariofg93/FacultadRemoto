#include <iostream>
#include "List.h"

using namespace std;

struct Node {
    int value;
    Node* next;
};

List empty(){
    return NULL;
}

void Cons(int x, List& xs){

    List l = new Node;
    l->value=x;
    l->next=xs;
    l = xs;
}

bool isEmpty(List xs){
    return (xs==empty());
}

int head (List xs){
    return xs->value;
}

List tail(List xs){
    return xs->next;
}

int length(List xs){
    List l2 = xs;
    int n = 0;
    while(l2 != NULL){
        n++;
        l2 = tail(l2);
    }
    return n;
}
