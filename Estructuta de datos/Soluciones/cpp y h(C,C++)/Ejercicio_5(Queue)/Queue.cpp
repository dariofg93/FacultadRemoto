#include "Queue.h"

struct Node {
    int value;
    Node* next;
};

struct QueueNode{
    Node* first;         //nodos, lista, cadena de ints....
    Node* last;         //
};

Queue emptyQ(){
    Queue newQ = new QueueNode;
    newQ->first = NULL;
    newQ->last = NULL;

    return (newQ);
}

bool isEmptyQ(Queue q){
    return (q->first == NULL);
}

void queue(Queue& q, int x){
    Node* newN = new Node;
    newN->value = x;
    newN->next = NULL;

    if (q->first == NULL) {
        q->first = newN;
    }
    else {
        q->last->next = newN;
    }

    q->last = newN;
}

int firstQ(Queue q){
    return (q->first->value);
}

void dequeue(Queue& q){
    Queue newQ = new QueueNode;
    newQ->first = q->first->next;
    newQ->last = q->last;
    delete q;
    q = newQ;
}

void destroyQ(Queue& q){
    while(not(isEmptyQ(q))){
        dequeue(q);
    }
}
