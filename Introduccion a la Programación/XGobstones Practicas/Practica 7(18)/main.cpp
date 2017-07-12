#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"

//18

List<Color> quitarColor(List<Color> cs, Color c)
/*Proposito: Saca el de la lista el color c, tantas veces como aparesca en la misma.
  Precondicion: Requiere una lista y un color.
*/
{
    List<Color> cols=cs;
    List<Color> res=Nil<Color>();
    while(not isNil(cols))
    {
        if(head(cols)!=c)
        {
            res=Snoc(res,head(cols));
        }
        cols=tail(cols);
    }
    return res;
}

using namespace std;

int main()
{
    List<Color> lista=Snoc(Snoc(Snoc(Snoc(Nil<Color>(),Verde),Rojo),Azul),Verde);
    PrintList(quitarColor(lista,Verde));
    return 0;
}
