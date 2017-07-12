#include <iostream>
#include "../../Biblioteca(CGobstones)/Gobstones.h"
using namespace std;

//8

void MoverN(int x, Dir d)
/*Proposito: Mueve el cabezal a direccion d, tantas veces como 5 lo diga.
  Precondicion: Deben haber tantas celdas como diga n en la direccion en que diga d.
*/
{
    int i=0;
    while(i<x)
    {
        Mover(d);
        i=i+1;
    }
}

void IrAlExtremo(Dir d)
//Proposito: Mueve el cabezal hacia el extremo de direccion d.
{
    while(puedeMover(d))
    {
        Mover(d);
    }
}

void UbicarCabezal(int x, Dir d)
/*Proposito: Mueve al cabezal a direccion que indique d con respecto al extremo opusto que indique ese parametro.
  Precondicion: Deben haber tantas celdas como x requiera.
*/
{
    IrAlExtremo(opuesto(d));
    MoverN(x,d);
}

int main()
{
    UbicarCabezal(3,Sur);
    ImprimirTablero();
    return 0;
}
