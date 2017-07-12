#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"

//17

List<int> sumarVecinos(List<int> ns)
/*Proposito: Dada una lista ns = [n1;...; nk], retorna la lista ms = [m2;...;mk-1] tal que mi es la suma de ni-1; ni y ni+1.
  Precondicion: Requiere una lista de enteros.
*/
{
    List<int> l=ns;
    List<int> res=Nil<int>();
    while(not isNil(l)&& not isNil(tail(l))&& not isNil(tail(tail(l))))
    {
        res= Snoc(res,head(l)+head(tail(l))+head(tail(l)));
        l=tail(l);
    }
    return res;
}

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
