#include <iostream>
#include "Stack.h"

using namespace std;

struct StackNode {

    ELEM_TYPE elem;
    StackNode* next;
};

Stack emptyS() {

    return NULL;
}

bool isEmptyS(Stack s) {

    return s == NULL;
}

void push(ELEM_TYPE x, Stack& s) {

    StackNode* newStackNode = new StackNode;
    newStackNode->elem = x;
    newStackNode->next = s;

    s = newStackNode;
}

void pop(Stack& s) {

    StackNode* newS = s->next;
    delete s;
    s = newS;
}

ELEM_TYPE top(Stack s) {

    return s->elem;
}

int lenS(Stack s) {

    int lenS = 0;
    while(s != NULL) {

        lenS ++;
        s = s->next;
    }
    return lenS;
}

void printS(Stack s) {

    cout << "new print stack" << endl;
    cout << "---------" << endl;
    StackNode* current = s;
    while(current != NULL) {
        cout << "| " << current->elem << endl;
        cout << "-----" << endl;
        s =s->next;
    }
}

Stack copyS(Stack s) {

    StackNode* stackCopy = new StackNode;
    while (s != NULL) {
        StackNode* newStackNode = new StackNode;
        newStackNode->elem = s->elem;
        newStackNode->next = s->next;
    }
}

ELEM_TYPE splitTop(Stack& s){
    ELEM_TYPE x = s->elem;
    pop(s);

    return x;
}

void destroyS(Stack& s){
    while(not(isEmptyS(s))){
        StackNode* sNew = s->next;
        s == NULL;
        delete s;

        s = sNew;
    }
}
// Stack myStack = new StackNode;
// myStack->elem = 1
// myStack->next = NULL


