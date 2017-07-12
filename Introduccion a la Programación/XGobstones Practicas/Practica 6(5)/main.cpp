#include <iostream>
#include "../../Biblioteca(CGobstones)/Gobstones.h"
using namespace std;

//5

void PonerN(int n,Color c)
//Proposito: Pone tantas bolitas c, como sea el parametro n.
{
    int i=1;
    while(i<=n)
    {
        Poner(c);
        i=i+1;
    }
}

void CambiarPorColorSiguiente()
/*Proposito: Cambia las bolitas de la celda actual por el color siguiente.
  Precondicion: NA
*/
{
    int repeat= 1;
    Color c= minColor();
    int nroDelColor= 0;
    while(repeat<=4)
    {
        while(hayBolitas(c))
        {
            Sacar(c);
            nroDelColor=nroDelColor+1;
        }
        PonerN(nroDelColor,c);
        repeat=repeat+1;
        c=siguiente(c);
    }
}

int main()
{
    Poner(Azul);
    Poner(Negro);
    Poner(Negro);
    Poner(Rojo);
    Poner(Rojo);
    Poner(Rojo);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    CambiarPorColorSiguiente();
    ImprimirTablero();
    return 0;
}
