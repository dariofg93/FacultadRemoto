#include <iostream>
#include "List.h"
#include "Iterator.h"

using namespace std;

int sumatoria(List l){
    Iterator it = getiterator(l);
    int total = 0;

    while(not(atend(it))){
        total=total+getelem(it);
        iterate(it);
    }
    return total;
}

int longitud(List l){
    Iterator it = getiterator(l);
    int total = 0;

    while(not(atend(it))){
        total++;
        iterate(it);
    }
    return total;
}

int promedio(List l){
    return (sumatoria(l)/longitud(l));
}

List mapSucesor(List l){
    List newL = nil();
    Iterator it = getiterator(l);

    while (!atend(it)) {
        snoc(newL,getelem(it)+1);
        iterate(it);
    }
    return newL;
}

bool pertenece(List l, int n){
    bool retorno = false;
    Iterator it = getiterator(l);

    while (!atend(it)) {
        retorno = retorno || getelem(it)==n;
        iterate(it);
    }
    return retorno;
}

int apariciones(List l, int n){
    int appear = 0;
    Iterator it = getiterator(l);

    while (!atend(it)) {
        if(getelem(it)==n) appear++;
        iterate(it);
    }
    return appear;
}

List filtrarMenoresA(List l, int n){
    List newL = nil();
    Iterator it = getiterator(l);

    while (!atend(it)) {
        if(getelem(it)>=n) snoc(newL,getelem(it));
        iterate(it);
    }
    return newL;
}

List filtrarElemento(List l, int n){
    List newL = nil();
    Iterator it = getiterator(l);

    while (!atend(it)) {
        if(getelem(it)!=n) snoc(newL,getelem(it));
        iterate(it);
    }
    return newL;
}

int main()
{
    /* creo una lista de prueba */
    List l = nil();
    snoc(l,1);
    snoc(l,2);
    snoc(l,3);
    snoc(l,4);
    snoc(l,5);

    List l2 = nil();
    snoc(l2,2);
    snoc(l2,2);
    snoc(l2,3);
    snoc(l2,2);
    snoc(l2,5);

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

    cout << sumatoria(l) << endl;
    cout << longitud(l) << endl;
    cout << promedio(l) << endl;
    printl(mapSucesor(l));
    cout << pertenece(l,3) << endl;
    cout << apariciones(l2,2) << endl;
    printl(filtrarMenoresA(l,3));
    printl(filtrarElemento(l2,2));


    /* destruyo la lista */
    destroyl(l);

    return 0;
}
