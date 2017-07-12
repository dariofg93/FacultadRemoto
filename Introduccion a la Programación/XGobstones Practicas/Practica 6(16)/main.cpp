#include <iostream>
#include "../../Biblioteca(CGobstones)/Gobstones.h"
using namespace std;

//16

void IrAlExtremo(Dir d)
//Proposito: Mueve el cabezal hacia el extremo de direccion d.
{
    while(puedeMover(d))
    {
        Mover(d);
    }
}

void IralInicio(Dir d1, Dir d2)
//Proposito: Pone al cabezal en una esquina del tablero.
{
    IrAlExtremo(d1);
    IrAlExtremo(d2);
}

void MoverN(int n, Dir d)
/*Proposito: Mueve el cabezal a direccion d, tantas veces como 5 lo diga.
  Precondicion: Deben haber tantas celdas como diga n en la direccion en que diga d.
*/
{
    int i=1;
    while(i<n)
    {
        Mover(d);
        i=i+1;
    }
}

int fila()
//Proposito: Devuelve el numero de fila en la que se encuentra el cabezal.
{
    int filas=0;
    while(puedeMover(Sur))
    {
        Mover(Sur);
        filas=filas+1;
    }
    Mover(Norte);
    MoverN(filas,Norte);
    return filas;
}

int columna()
//Proposito: Devuelve el numero de columna en la que se encuentra el cabezal.
{
    int columnas=0;
    while(puedeMover(Oeste))
    {
        Mover(Oeste);
        columnas=columnas+1;
    }
    Mover(Este);
    MoverN(columnas,Este);
    return columnas;
}

void IrAFila(int n1, Dir d1)
/*Proposito: Mueve al cabezal a direccion que indique d con respecto al extremo opusto que indique ese parametro.
  Precondicion: Deben haber tantas celdas como x requiera.
*/
{
    IrAlExtremo(opuesto(d1));
    MoverN(n1,d1);
}

void IrAColumna(int n2, Dir d2)
/*Proposito: Mueve al cabezal a direccion que indique d con respecto al extremo opusto que indique ese parametro.
  Precondicion: Deben haber tantas celdas como x requiera.
*/
{
    IrAlExtremo(opuesto(d2));
    MoverN(n2,d2);
}

void MoverSobreElTableroA(int n1, Dir dFila, int n2, Dir dColumna)
//Proposito: Ubica el cabezal en la fila y columna seleccionada.
{
    IrAFila(n1,dFila);
    IrAColumna(n2,dColumna);
}

bool esFinDelRecorrido()
//Proposito: Devuelve True si puede moverse en direccion Norte y Oeste.
{
    return(not puedeMover(Norte)&& not puedeMover(Este));
}

void SiguienteCelda()
//Proposito: Pasa al siguiente lugar disponible en el recorrido.
{
    if(puedeMover(Norte))
    {
        Mover(Norte);
    }
    else
    {
        Mover(Este);
        IrAlExtremo(Sur);
    }
}

int totalBolitas(Color c)
//Devuelve el numero de bolitas c totales en el tablero.
{
    int estaEnFila=fila();
    int estaEnColumna=columna();
    int nroBolitasTotal=0;
    IralInicio(Sur,Oeste);
    while(not esFinDelRecorrido())
    {
        nroBolitasTotal=nroBolitasTotal+nroBolitas(c);
        SiguienteCelda();
    }
    nroBolitasTotal=nroBolitasTotal+nroBolitas(c);
    MoverSobreElTableroA(estaEnFila,Norte,estaEnColumna,Este);
    Mover(Norte);
    Mover(Este);
    return nroBolitasTotal;
}

int main()
{
    ImprimirTablero();
    return 0;
}
