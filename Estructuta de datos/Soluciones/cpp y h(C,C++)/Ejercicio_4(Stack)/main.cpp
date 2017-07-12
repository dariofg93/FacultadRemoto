#include <iostream>
#include "Stack.h"

using namespace std;

Stack reverseS(Stack s){
    Stack s1 = s;
    Stack s2 = emptyS();
    while (not(isEmptyS(s1))){
        push(top(s1),s2);
        pop(s1);
    }
    return (s2);
}

int main()
{
    Stack s1 = emptyS();
    push(3,s1);
    push(2,s1);
    push(1,s1);
    pop(s1);

    cout << reverseS(s1) << endl;
    cout << s1 << endl;
    cout << isEmptyS(s1) << endl;
    cout << size(s1) << endl;
    return 0;
}
