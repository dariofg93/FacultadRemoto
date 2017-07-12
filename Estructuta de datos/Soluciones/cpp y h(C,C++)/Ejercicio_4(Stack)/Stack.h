#include <iostream>

using namespace std;

struct StackSt;

typedef StackSt* Stack;

Stack emptyS();
bool isEmptyS(Stack s);
void push(int x, Stack& s);
int top(Stack s);
void pop(Stack& s);
int size(Stack s);
void destroyS(Stack& s);
