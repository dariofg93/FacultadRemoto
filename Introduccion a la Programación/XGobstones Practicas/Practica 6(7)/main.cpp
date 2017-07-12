#include <iostream>
#include "../../Biblioteca(CGobstones)/Gobstones.h"
using namespace std;

//7

void MoverN(int n, Dir d)
/*Proposito: Mueve el cabezal a direccion d, tantas veces como 5 lo diga.
  Precondicion: Deben haber tantas celdas como diga n en la direccion en que diga d.
*/
{
    int i=0;
    while(i<n)
    {
        Mover(d);
        i=i+1;
    }
}

int main()
{
    MoverN(5,Sur);
    ImprimirTablero();
    return 0;
}
