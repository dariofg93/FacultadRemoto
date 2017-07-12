#include <iostream>
#include "../../Biblioteca(CGobstones)/Gobstones.h"
using namespace std;

//14

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

int fila()
//Proposito: Devuelve el numero de fila en la que se encuentra el cabezal.
{
    int filas=0;
    while(puedeMover(Sur))
    {
        Mover(Sur);
        filas=filas+1;
    }
    Mover(Norte);
    MoverN(filas,Norte);
    return filas;
}

int main()
{
    ImprimirTablero();
    return 0;
}
