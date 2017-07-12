#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"
using namespace std;

//25

bool perteneceInt(List<int> l, int v)
/*Proposito: Devuelve true si un elemento esta en la lista.
  Precondicion: Requiere una lista de numeros enteros y un valor entero "v".
*/
{
    List<int> rec=l;
    while(not isNil(rec)&&head(rec)!=v)
    {
        rec=tail(rec);
    }
    return not isNil(rec);
}

List<int> quitarNumerosDuplicados(List<int> ns)
/*Proposito: Duevulve una lista de numeros enteros sin los elementos duplicados.
  Precondicion: Requiere una lista de numeros enteros.
*/
{
    List<int> rec=ns;
    List<int> res=Nil<int>();
    while(not isNil(rec))
    {
        if(not perteneceInt(res,head(rec)))
        {
            res=Snoc(res,head(rec));
        }
        rec=tail(rec);
    }
    return res;
}

int main()
{
    List<int> lista=Snoc(Snoc(Snoc(Snoc(Snoc(Snoc(Snoc(Nil<int>(),1),3),4),2),4),3),5);
    PrintList(quitarNumerosDuplicados(lista));
    return 0;
}
