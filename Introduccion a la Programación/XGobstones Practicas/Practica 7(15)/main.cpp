#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"

//15

List<int> cuadrados(List<int> n)
/*Proposito: Devuelve una lista con las operaciones cuadradas de la asignada.
  Precondicion: Requiere una lista de numeros enteros.
*/
{
    List<int> l=n;
    List<int> rec=Nil<int>();
    while (not isNil(l))
    {
        rec=Snoc(rec,(head(l)*head(l)));
        l=tail(l);
    }
    return rec;
}

using namespace std;

int main()
{
    List<int> lista=Snoc(Snoc(Snoc(Nil<int>(),1),2),3);
    PrintList(cuadrados(lista));
    return 0;
}
