#include <iostream>
#include "../../Biblioteca(CGobstones)/Gobstones.h"
using namespace std;

//13

void PonerN(int n, Color c)
/*Proposito: Mueve el cabezal a direccion d, tantas veces como 5 lo diga.
  Precondicion: Deben haber tantas celdas como diga n en la direccion en que diga d.
*/
{
    int i=1;
    while(i<=n)
    {
        Poner(c);
        i=i+1;
    }
}

bool hayBolitasAl(Dir d, Color c)
/*Proposito: Devuelve TRUE si hay bolitas en la celda de direccion d.
  Precondicion: Debe haber una celda en direccion d.
*/
{
    bool bolitasHay=false;
    Mover(d);
    if(hayBolitas(c))
    {
        bolitasHay=true;
    }
    Mover(opuesto(d));
    return bolitasHay;
}

int vecinosConColor(Color c)
//Proposito: Devuelve el numero de vecinos que tiene bolitas de color c.
{
    int bolitas=0;
    int repeat=0;
    Dir dir=minDir();
    while(repeat<4)
    {
        if(puedeMover(dir)&&hayBolitasAl(dir,c))
        {
            bolitas=bolitas+1;
        }
        dir=siguiente(dir);
        repeat=repeat+1;
    }
    return bolitas;
}

int main()
{
    Mover(Oeste);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    Mover(Este);
    Mover(Sur);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    Mover(Norte);
    Mover(Este);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    Poner(Verde);
    Mover(Oeste);
    PonerN(vecinosConColor(Verde),Rojo);
    ImprimirTablero();
    return 0;
}
