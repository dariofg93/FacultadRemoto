#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"
using namespace std;

//9

List<int> rango(int n, int m)
/*Proposito: Dado una lista de enteros devuelve los numeros que estan entre los mayores o iguales a n y menores a m.
  Precondicion: requieren los dos numeros del rango como paramentros.
*/
{
    List<int> rank=Nil<int>();
    int i=n;
    while(i<m)
    {
        rank=Snoc(rank,i);
        i=i+1;
    }
    return rank;
}

int main()
{
    PrintList(rango(8,250));
    return 0;
}
