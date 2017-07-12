#include <iostream>
#include "../../Biblioteca(CGobstones)/Gobstones.h"
using namespace std;

//3

bool EstanEnElBorde()
{
    return not puedeMover(Norte) || not puedeMover(Este) || not puedeMover(Sur) || not puedeMover(Oeste);
}

int main()
{
    if(EstanEnElBorde())
    {
        Poner(Rojo);
    }
    ImprimirTablero();
    return 0;
}
