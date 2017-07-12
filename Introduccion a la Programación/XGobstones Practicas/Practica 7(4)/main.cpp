#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"
using namespace std;

//4

void PonerColores(List<Color> cs)
/*Proposito: Coloca en la celda actual los colores de la lista asignada.
  Precondicion: Requiere una lista de colores.
*/
{
    List<Color> l=cs;
    while(not isNil(l))
    {
        Poner(head(l));
        l=tail(l);
    }
}

int main()
{
    List<Color> s=Snoc(Snoc(Snoc(Snoc(Nil<Color>(),Verde),Azul),Rojo),Verde);
    PonerColores(s);
    ImprimirTablero();
    return 0;
}
