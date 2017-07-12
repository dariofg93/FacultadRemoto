#include <iostream>
#include "../../Biblioteca(CGobstones)/Gobstones.h"
using namespace std;

//4

void VaciarCelda()
/*Proposito: Sacar todas las bolitas de las celdas.
  Precondicion: NA
*/
{
    int repeat= 0;
    Color c= minColor();
    while(repeat<4)
    {
        while(hayBolitas(c))
        {
            Sacar(c);
        }
        repeat=repeat+1;
        c=siguiente(c);
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

void VaciarColumna()
//Proposito: Vacia la columna donde se encuntra el cabezal.
{
    IrAlExtremo(Norte);
    VaciarCelda();
    while(puedeMover(Sur))
    {
        Mover(Sur);
        VaciarCelda();
    }
}

int main()
{
    VaciarColumna();
    ImprimirTablero();
    return 0;
}
