#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"
using namespace std;

//7

List<int> aparicionesDeColorEnDirs(List<Dir> ds, Color c)
/*Proposito: Mueve el cabezal segun la lista de direcciones asignada y retorna una lista con la cantidad de bolitas del color c.
  Precondicion: Requiere un color c y una lista de direcciones y que el cabezal se pueda mover en dichas direcciones.
*/
{
    List<int> res=Nil<int>();
    List<Dir> l=ds;
    while(not isNil(l))
    {
        res=Snoc(res,nroBolitas(c));
        Mover(head(l));
        l=tail(l);
    }
    return res=Snoc(res,nroBolitas(c));
}

int main()
{
    Poner(Verde);
    List<Dir> s=Snoc(Snoc(Snoc(Snoc(Nil<Dir>(),Sur),Oeste),Sur),Oeste);
    PrintList(aparicionesDeColorEnDirs(s,Verde));
    ImprimirTablero();
    return 0;
}
