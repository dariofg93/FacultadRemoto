#include <iostream>
#include "Queue.h"

using namespace std;

int largoQ(Queue q1){
    int largo = 0;
    Queue q = q1;
    while(not(isEmptyQ(q))){
        dequeue(q);
        largo++;
    }
    return(largo);
}
/*
Queue listToQueue(int[] numbers){
    int[] ns = numbers;
    Queue q = emptyQ();

    while(not(ns==NULL)){
        queue(q,head(ns));
        tail(ns);
    }
    return(q);
}
                                            VER SINTAXIS LISTAS!
int[] queueToList(Queue q1){
    int[] ns = int[]{};
    Queue q = q1;

    while(not(isEmptyQ(q))){
        add(firstQ(q),ns);
        dequeue(q);
    }
    return(ns);
}
*/
Queue unirQ(Queue q1, Queue q2){
    Queue retorno = q1;
    Queue recorrido = q2;
    while(not(isEmptyQ(recorrido))){
        queue(retorno,firstQ(recorrido));
        dequeue(recorrido);
    }
    return(retorno);
}

int main()
{
    Queue q1 = emptyQ();
    queue(q1,1);
    queue(q1,2);
    queue(q1,3);
    queue(q1,5);

    Queue q2 = emptyQ();
    queue(q2,7);
    queue(q2,9);
    queue(q2,10);

    Queue q3 = unirQ(q1,q2);

    cout << firstQ(q3) << endl;
    return 0;
}
