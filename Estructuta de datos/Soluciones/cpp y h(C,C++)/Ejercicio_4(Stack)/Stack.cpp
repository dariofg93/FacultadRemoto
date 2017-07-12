#include "Stack.h"

struct StackSt{
    int value;
    StackSt* next;
};

Stack emptyS(){
    return(NULL);
}

bool isEmptyS(Stack s){
    return (s==NULL);
}

void push(int x, Stack& s){

    Stack s2 = new StackSt;
    s2->value = x;
    s2->next = s;
    s = s2;
}

int top(Stack s){
    return (s->value);
}

void pop(Stack& s){
    Stack s2 = new StackSt;
    s2 = s->next;
    delete s;
    s = s2;
}

int size(Stack s){
    int cantidad = 0;
    Stack s2 = s;
    while(not(isEmptyS(s2))){
        s2 = s2->next;
        cantidad++;
    }
     return(cantidad);
}

void destroyS(Stack& s){
    while(not(isEmptyS(s))){
        pop(s);
    }
}

