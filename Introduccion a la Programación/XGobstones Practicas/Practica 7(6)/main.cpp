#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"
using namespace std;

//6

void IrAlExtremo(Dir d)
{
    while(puedeMover(d))
    {
        Mover(d);
    }
}

List<int> aparicionesDeColorEnFila(Color c)
/*Proposito: Devuelve una lista con las cantidad de bolitas en cada celda desde el Oeste al Este en la fila actual.
  Precondicion: Requiere un Color c.
*/
{
    IrAlExtremo(Oeste);
    List<int> l=Nil<int>();
    while(puedeMover(Este))
    {
        l=Snoc(l,nroBolitas(c));
        Mover(Este);
    }
    return l=Snoc(l,nroBolitas(c));
}

int main()
{
    Poner(Verde);
    Mover(Oeste);
    Mover(Oeste);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    Mover(Oeste);
    Mover(Oeste);
    Mover(Oeste);
    Mover(Este);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    PrintList(aparicionesDeColorEnFila(Verde));
    return 0;
}
