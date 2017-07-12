#include <iostream>
#include "../../Biblioteca(CGobstones)/Gobstones.h"
using namespace std;

//12

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

bool aislada()
//Proposito: Devuelve TRUE si hay alguna bolita en algunas de las celdas vecinas.
{
    int bolitas=0;
    int repeat=0;
    Dir dir=minDir();
    while(repeat<4)
    {
        if(puedeMover(dir))
        {
            bolitas=bolitas+nroBolitasAl(dir);
        }
        dir=siguiente(dir);
        repeat=repeat+1;
    }
    bool hayBolitasTotal=false;
    if(bolitas>0)
    {
        hayBolitasTotal=true;
    }
    return hayBolitasTotal;
}

int main()
{
    ImprimirTablero();
    return 0;
}
