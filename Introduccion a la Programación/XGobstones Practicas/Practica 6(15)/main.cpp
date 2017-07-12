#include <iostream>
#include "../../Biblioteca(CGobstones)/Gobstones.h"
using namespace std;

//15

void MoverN(int n, Dir d)
/*Proposito: Mueve el cabezal a direccion d, tantas veces como 5 lo diga.
  Precondicion: Deben haber tantas celdas como diga n en la direccion en que diga d.
*/
{
    int i=1;
    while(i<n)
    {
        Mover(d);
        i=i+1;
    }
}

int columna()
//Proposito: Devuelve el numero de columna en la que se encuentra el cabezal.
{
    int columnas=0;
    while(puedeMover(Oeste))
    {
        Mover(Oeste);
        columnas=columnas+1;
    }
    Mover(Este);
    MoverN(columnas,Este);
    return columnas;
}

int main()
{
    ImprimirTablero();
    return 0;
}
