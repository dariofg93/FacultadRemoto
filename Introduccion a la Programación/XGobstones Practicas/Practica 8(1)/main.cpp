#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"
using namespace std;

void MoverN(int n, Dir d)
/**Proposito: Mueve el cabezal tantas veces como com n diga en direccion d.
   Precondicion: Se tiene que poder mover el cabezal a la direccion indicada.
**/
{
    int i=0;
    while(i<n)
    {
        Mover(d);
        i=i+1;
    }
}

void IrAlExtremo(Dir d)
/**Proposito: Mueve el cabezal al extremo d del tablero.
   Precondicion: NA.
**/
{
    while(puedeMover(d))
    {
        Mover(d);
    }
}

void IrAlOrigen()
/**Proposito: Mueve el cabezal a una de las puntas del tablero.
   Precondicion: NA.
**/
{
    IrAlExtremo(Sur);
    IrAlExtremo(Oeste);
}

int fila()
/**Proposito: Devuelve la cantidad de filas en entero.
   Precondicion: Mueve al cabezal al extremo norte del tablero.
**/
{
    int cont=1;
    IrAlExtremo(Sur);
    while(puedeMover(Norte))
    {
        Mover(Norte);
        cont=cont+1;
    }
    return cont;
}

int columna()
/**Proposito: Devuelve la cantidad de columnas en entero.
   Precondicion: Mueve al cabezal al extremo este del tablero.
**/
{
    int cont=1;
    IrAlExtremo(Oeste);
    while(puedeMover(Este))
    {
        Mover(Este);
        cont=cont+1;
    }
    return cont;
}

int filaActual()
/**Proposito: Devuelve la fila actual en entero.
   Precondicion: NA.
**/
{
    int cont=1;
    while(puedeMover(Sur))
    {
        Mover(Sur);
        cont=cont+1;
    }
    MoverN(cont,Norte);
    return cont;
}

int columnaActual()
/**Proposito: Devuelve la columna actual en entero.
   Precondicion: NA.
**/
{
    int cont=1;
    while(puedeMover(Oeste))
    {
        Mover(Oeste);
        cont=cont+1;
    }
    MoverN(cont,Este);
    return cont;
}

struct Coord
/**Proposito: Crea un nuevo tipo "Coord".
   Invariante de representacion: fila>0 y columna>0.
**/
{
    int fila;
    int columna;
};

int filaCoord(Coord coor)
///Proposito: Denota la fila de la coordenada.
{
    return coor.fila;
}

int columnaCoord(Coord coor)
///Proposito: Denota la columna de la coordenada.
{
    return coor.columna;
}

bool eqCoord(Coord c1, Coord c2)
///Proposito: Determina si dos coordenadas son iguales.
{
    return c1.fila==c2.fila and c1.columna==c2.columna;
}

bool gtCoord(Coord c1, Coord c2)
///Proposito: Determina si la primer coordenada aparece despues de la segunda en un recorrido que va hacia en noreste.
{
    return c1.fila>c2.fila and c1.columna>c2.columna;
}

Coord mkCoord(int f, int c)
///Proposito: Denota la coordena f y c(fila columna).
{
    Coord res;
    res.fila=f;
    res.columna=c;
    return res;
}

Coord mkOrigen()
///Proposito: Denota la coordena de origen.
{
    return mkCoord(1,1);
}

Coord mkUltima()
///Proposito: Denota la ultima coordena del tablero en un recorrido hacia el noreste.
{
    return mkCoord(fila(),columna());
}

void IrAcoord(Coord c)
/**Proposito: Mueve al cabezal hacia las coordenadas indicadas.
   Precondicion: Las coordenas deben ser enteros dentro del rango de lo que permite el tablero.
**/
{
    IrAlOrigen();
    MoverN(c.fila,Norte);
    MoverN(c.columna,Este);
}

Coord coordActual()
///Proposito: Devuelve la coordena en la que se encuentra el cabezal.
{
    return mkCoord(filaActual(), columnaActual());
}

Coord reflejo(Coord coor)
///Proposito: Devuelve las coordenas con la fila y la columna intercambiadas entre si.
{
    return mkCoord(coor.columna,coor.fila);
}

bool sobreLaDiagonal(Coord c)
///Proposito: Devuelve true si la coordena se encuentra sobre la diagonal que va del origen hasta la ultima celda.
{
    return c.fila==c.columna;
}

int main()
{
    IrAcoord(mkCoord(2,4));
    ImprimirTablero();
    return 0;
}
