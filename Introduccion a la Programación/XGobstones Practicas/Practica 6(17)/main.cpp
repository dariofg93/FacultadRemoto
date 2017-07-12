#include <iostream>
#include "../../Biblioteca(CGobstones)/Gobstones.h"
using namespace std;

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

int celdasHastaElExtremo(Dir direccion)
/*Proposito: Devuelve el numero de celdas hasta el extremo direccion.
  Precondicion: NA.
*/
{
    int celdas=0;
    while(puedeMover(direccion))
    {
        Mover(direccion);
        celdas=celdas+1;
    }
    MoverN(celdas,opuesto(direccion));
    return celdas;
}

int main()
{
    ImprimirTablero();
    return 0;
}
