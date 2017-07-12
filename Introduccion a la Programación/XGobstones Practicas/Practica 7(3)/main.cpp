#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"
using namespace std;

//3

List<Color> coloresCelda()
//Proposito: Devuelve una lista con los colores que hay debajo del cabezal.
{
    List<Color> res=Nil<Color>();
    int cont=0;
    Color cs=minColor();
    while(cont<4)
    {
        if(hayBolitas(cs))
        {
            res=Snoc(res,cs);
        }
        cont=cont+1;
        cs=siguiente(cs);
    }
    return res;
}

int main()
{
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    Poner(Azul);
    Poner(Azul);
    Poner(Azul);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    PrintList(coloresCelda());
    return 0;
}
