#include <iostream>
#include "List.h"
#include "Iterator.h"

using namespace std;

int main()
{
    /* creo una lista de prueba */
    List l = nil();
    snoc(l,1);
    snoc(l,2);
    snoc(l,3);
    snoc(l,4);
    snoc(l,5);

    /* la printeo para verla */
    printl(l);

    /* la itero sumandole 1 a todos sus elementos y despues destruyo el iterador */
    Iterator it = createiterator(l);

    while (!atend(it)) {
        setelem(getelem(it) +1, it);
        iterate(it);
    }

    destriyit(it);

    /* la vuelvo a printear para ver como quedo */
    printl(l);

    /* destruyo la lista */
    destroyl(l);

    return 0;
}
