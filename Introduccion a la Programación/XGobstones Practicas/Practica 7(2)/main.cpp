#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"
using namespace std;

//2

List<Dir> direccionesAlBorde()
//Proposito: Devuelve una lista con las direcciones en las que no se puede mover el cabezal.
{
    List<Dir> res=Nil<Dir>();
    int cont=0;
    Dir ds=minDir();
    while(cont<4)
    {
        if(not puedeMover(ds))
        {
            res=Snoc(res,ds);
        }
        cont=cont+1;
        ds=siguiente(ds);
    }
    return res;
}

int main()
{
    PrintList(direccionesAlBorde());
    return 0;
}
