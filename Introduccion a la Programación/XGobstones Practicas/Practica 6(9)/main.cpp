#include <iostream>
#include "../../Biblioteca(CGobstones)/Gobstones.h"
using namespace std;

//9

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

void IrAlExtremo(Dir d)
//Proposito: Mueve el cabezal hacia el extremo de direccion d.
{
    while(puedeMover(d))
    {
        Mover(d);
    }
}

void IrAFila(int n1, Dir d1)
/*Proposito: Mueve al cabezal a direccion que indique d con respecto al extremo opusto que indique ese parametro.
  Precondicion: Deben haber tantas celdas como x requiera.
*/
{
    IrAlExtremo(opuesto(d1));
    MoverN(n1,d1);
}

void IrAColumna(int n2, Dir d2)
/*Proposito: Mueve al cabezal a direccion que indique d con respecto al extremo opusto que indique ese parametro.
  Precondicion: Deben haber tantas celdas como x requiera.
*/
{
    IrAlExtremo(opuesto(d2));
    MoverN(n2,d2);
}

int main()
{
    IrAColumna(2,Oeste);
    ImprimirTablero();
    return 0;
}
