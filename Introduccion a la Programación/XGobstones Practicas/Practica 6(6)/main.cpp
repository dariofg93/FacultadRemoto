#include <iostream>
#include "../../Biblioteca(CGobstones)/Gobstones.h"
using namespace std;

//6

void PonerAl(Dir d, Color c)
//Proposito: Pone una bolita de color c en la direccion d.
{
    if(puedeMover(d))
    {
        Mover(d);
        Poner(c);
    }
}

int main()
{
    PonerAl(Sur,Verde);
    ImprimirTablero();
    return 0;
}
