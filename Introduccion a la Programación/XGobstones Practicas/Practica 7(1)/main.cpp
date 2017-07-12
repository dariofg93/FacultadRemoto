#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"

bool esSingularColor(List<Color> ns)
/*Proposito: Devuelve true si la lista de colores contiene solo un elemento.
  Precondicion: Requiere una lista de colores como parámetro.
*/
{
    List<Color> l=ns;
    if(not isNil(l))
    {
        l=tail(l);
    }
    return isNil(l);
}

using namespace std;

int main()
{
    List<Color> mi_ds=Snoc(Snoc(Nil<Color>(),Verde),Azul);
    if(esSingularColor(mi_ds)==true)
    {
        Poner(Verde);
    }
    else
    {
        Poner(Rojo);
    }
    ImprimirTablero();
    return 0;
}
