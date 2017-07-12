#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List l = empty();
    Cons(6,l);
    Cons(5,l);
    Cons(4,l);
    Cons(3,l);
    Cons(2,l);
    Cons(1,l);

    cout << length(l) << endl;
    cout << l << endl;
    cout << empty() << endl;
    cout << isEmpty(l) << endl;
    cout << tail(l) << endl;

    return 0;


}
