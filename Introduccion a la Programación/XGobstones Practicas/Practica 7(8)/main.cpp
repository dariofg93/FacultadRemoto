#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"
using namespace std;

//8

void PonerN(int n, Color c)
{
    int i=0;
    while(i<n)
    {
        Poner(c);
        i=i+1;
    }
}

void PonerLista(List<int> i, List<Color> cs)
/*Proposito: Pone en el tablero la cantidad de bolitas en la celda actual, segun las listas.
  Precondicion: Requiere una lista de colores y otra de enteros.
*/
{
    List<int> n=i;
    List<Color> c=cs;
    while(not isNil(n) && not isNil(c))
    {
        PonerN(head(n),head(c));
        n=tail(n);
        c=tail(c);
    }

}

int main()
{
    List<int> s=Snoc(Snoc(Snoc(Snoc(Nil<int>(),2),4),8),16);
    List<Color> d=Snoc(Snoc(Snoc(Snoc(Nil<Color>(),Verde),Rojo),Azul),Verde);
    PonerLista(s,d);
    ImprimirTablero();
    return 0;
}
