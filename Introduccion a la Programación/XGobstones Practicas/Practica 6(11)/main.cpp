#include <iostream>
#include "../../Biblioteca(CGobstones)/Gobstones.h"
using namespace std;

//11

int nroBolitasAl(Dir d)
/*Proposito: Devuelve el numero de bolitas en la celda de direccion d.
  Precondicion: Debe haber una celda en direccion d.
*/
{
    int bolitasTotal= 0;
    Mover(d);
    bolitasTotal=nroBolitas(Azul)+nroBolitas(Negro)+nroBolitas(Rojo)+nroBolitas(Verde);
    Mover(opuesto(d));
    return bolitasTotal;
}

int main()
{

    ImprimirTablero();
    return 0;
}
