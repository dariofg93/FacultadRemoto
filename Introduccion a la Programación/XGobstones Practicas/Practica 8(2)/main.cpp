#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"
using namespace std;

bool esFinDelRecorrido()
{
    return not puedeMover(Norte) && not puedeMover(Este);
}

void IrAlExtremoL(Dir d)
{
    while(puedeMover(d))
    {
        Mover(d);
    }
}

void IrAlOrigenL(Dir d1, Dir d2)
{
    IrAlExtremoL(d1);
    IrAlExtremoL(d2);
}

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

void PonerN(int n, Color c)
///Proposito: Pone tantas bolitas como com n diga de color c.
{
    int i=0;
    while(i<n)
    {
        Poner(c);
        i=i+1;
    }
}

int filaActual()
/**Proposito: Devuelve la fila actual en entero.
   Precondicion: NA.
**/
{
    int cont=0;
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
    int cont=0;
    while(puedeMover(Oeste))
    {
        Mover(Oeste);
        cont=cont+1;
    }
    MoverN(cont,Este);
    return cont;
}

void MoverACoordeana(int f, int c)
/**Proposito: Mueve el cabezal a las coordenas f y c
   Precondicion: Debe ser una posicion valida para el tablero.
**/
{
    IrAlExtremoL(Sur);
    IrAlExtremoL(Oeste);
    MoverN(f,Norte);
    MoverN(c,Este);
}

struct Coord
/**Proposito: Crea un nuevo tipo "Coord".
   Invariante de representacion: fila>0 y columna>0.
**/
{
    int fila;
    int columna;
};

Coord mkCoord(int f, int c)
///Proposito: Denota la coordena f y c(fila columna).
{
    Coord res;
    res.fila=f;
    res.columna=c;
    return res;
}

struct Celda
/**Proposito: Crea un nuevo tipo "Celda".
   Invariante representacion: Todos los campos deben ser mayor a 0.
**/
{
    int azul;
    int negro;
    int rojo;
    int verde;
};

Celda mkCelda(int a, int n, int r, int v)
///Proposito: Dado cuatro enteros que representan las bolitas de cada color el registro de celda correspondiente.
{
    Celda res;
    res.azul=a;
    res.negro=n;
    res.rojo=r;
    res.verde=v;
    return res;
}

Celda mkCeldaActual()
///Proposito: Devuelve el registro Celda sobre la celda actual.
{
    return mkCelda(nroBolitas(Azul),nroBolitas(Negro),nroBolitas(Rojo),nroBolitas(Verde));
}

Celda mkCeldaEnCoord(int f, int c)
///Proposito: Denota el registro con las coordenas f y c.
///Invariante representacion: Deben ser coordenadas que se encuentren dentro del tablero.
{
    Coord d=mkCoord(f,c);
    IrAlExtremoL(Sur);
    IrAlExtremoL(Oeste);
    MoverN(d.fila,Norte);
    MoverN(d.columna,Este);
    return mkCeldaActual();
}

void VolcarCelda(Celda d)
///Proposito: Deposita en la celda la contidad de bolitas que dice celda de cada color.
{
    PonerN(d.azul,Azul);
    PonerN(d.negro,Negro);
    PonerN(d.rojo,Rojo);
    PonerN(d.verde,Verde);
}

void IntercambiarCeldas(Coord c1, Coord c2)
///Dada dos coordenas validas para el cabezal, intercambia las bolitas entre si.
{
    Coord cUno=c1;
    Coord cDos=c2;
    MoverACoordeana(cUno.fila,cUno.columna);
    Celda celda1=mkCeldaActual();
    MoverACoordeana(cDos.fila,cDos.columna);
    Celda celda2=mkCeldaActual();
    VolcarCelda(celda1);
    MoverACoordeana(cUno.fila,cUno.columna);
    VolcarCelda(celda2);
}

void ReflejarCelda(Coord c)
///Proposito: Refleja la celda de coordena actual, sin mover el cabezal.
{
    Celda cel=mkCeldaActual();
    Coord coor=c;
    MoverACoordeana(c.columna,c.fila);
    VolcarCelda(cel);
    MoverACoordeana(c.fila,c.columna);
}

Coord coordActual()
///Proposito: Devuelve la coordena en la que se encuentra el cabezal.
{
    return mkCoord(filaActual(), columnaActual());
}

void ReflejarCeldaActual()
///Proposito: Refleja la celda actual, sin mover el cabezal.
{
    Celda cel=mkCeldaActual();
    Coord c=coordActual();
    MoverACoordeana(c.columna,c.fila);
    VolcarCelda(cel);
    MoverACoordeana(c.fila,c.columna);
}

void SiguienteElemento()
{
    if(puedeMover(Norte))
    {
        Mover(Norte);
    }
    else
    {
        Mover(Este);
        IrAlExtremoL(Sur);
    }
}

void ReflejarTablero()
{
    IrAlOrigenL(Oeste,Sur);
    while(not esFinDelRecorrido())
    {
        ReflejarCeldaActual();
        SiguienteElemento();
    }
    ReflejarCeldaActual();
}

int main()
{
    ReflejarTablero();
    ImprimirTablero();
    return 0;
}
