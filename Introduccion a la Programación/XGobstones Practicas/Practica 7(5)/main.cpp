#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"
using namespace std;

//5

void RecorrerCamino(List<Dir> ds)
/*Proposito: Mueve el cabezal segun la lista de direcciones asignada.
  Precondicion: Requiere una lista de direcciones y que el cabezal se pueda mover en dichas direcciones.
*/
{
    List<Dir> l=ds;
    while(not isNil(l))
    {
        Mover(head(l));
        l=tail(l);
    }
}

int main()
{
    List<Dir> s=Snoc(Snoc(Snoc(Snoc(Nil<Dir>(),Sur),Oeste),Sur),Oeste);
    RecorrerCamino(s);
    ImprimirTablero();
    return 0;
}
