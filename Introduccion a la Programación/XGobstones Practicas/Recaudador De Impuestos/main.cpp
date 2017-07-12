#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/EntregaListas.h"
#include "../../Biblioteca(CGobstones)/List.h"
using namespace std;

void IrAlExtremoL(Dir d)
{
    while(puedeMover(d))
    {
        Mover(d);
    }
}

void IrAlOrigenL()
//Proposito: Se ubica en el inicio del recorrido.
//Precondicion:NA.
{
    IrAlExtremoL(Sur);
    IrAlExtremoL(Oeste);
}

bool esFinDelRecorrido()
//Proposito: Retorna true si ya termino de recorrer la ciudad.
//Precondicion:NA.
{
    return (not puedeMover(Norte)&&not puedeMover(Este));
}

void CaminarSiguientePosicion()
//Proposito: El recaudador camina hacia la siguiente posicion en busca de una casa.
//Precondicion:NA.
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

List<int> monedasDeDeudas()
//Proposito: Recorre la ciudad realizando la lista de datos de monedas de las deudas para poder sumarla despues en casa.
//Precondicion:NA.
{
    List<int> res=Nil<int>();
    IrAlOrigenL();
    if(hayBolitas(Negro))
        {
            res=Snoc(res,nroBolitas(Rojo));
        }
    while(not esFinDelRecorrido())
    {
        CaminarSiguientePosicion();
        if(hayBolitas(Negro))
        {
            res=Snoc(res,nroBolitas(Rojo));
        }
    }
    return res;
}

int sumarDeudores()  //<-------1) En su casa el recaudador hace la suma de los deudores totales.
//Precondicion:NA.
{
    List<int> rec=monedasDeDeudas();
    int res=0;
    {
        while(not isNil(rec))
        {
            res=res+1;
            rec=tail(rec);
        }
    }
    return res;
}

int sumarDeudoresQueDebenMayorADiez()  //<-------2) En su casa el recaudador hace la suma de los deudores que tienen una deuda
//Precondicion: NA                                           mayor a 10.
{
    List<int> deudas=monedasDeDeudas();
    int res=0;
    while(not isNil(deudas))
    {
        if(head(deudas)>10)
        {
            res=res+1;
        }
        deudas=tail(deudas);
    }
    return res;
}

List<int> interesPorMes()     //<--------3) En su casa, calcula el interes que genero la deuda de cada deudor.
//Precondicion: NA.
{
    List<int> rec=monedasDeDeudas();
    List<int> res=Nil<int>();
    while(not isNil(rec))
    {
        res=Snoc(res,calcularInteres(head(rec)));
        rec=tail(rec);
    }
    return res;
}

List<int> DeudaMasInteres()
//Proposito: Calculo opcional para saber cual es la deuda mas el interes de cada deudor.
//Precondicion: NA.
{
    List<int> rec1=monedasDeDeudas();
    List<int> rec2=interesPorMes();
    List<int> res=Nil<int>();
    while(not isNil(rec1))
    {
        res=Snoc(res,(head(rec1)+head(rec2)));
        rec1=tail(rec1);
        rec2=tail(rec2);
    }
    return res;
}

int mayorDeuda()     //<--------4) Devuelve la mayor deuda representado en un entero.
//Precondicion: NA.
{
    List<int> rec=DeudaMasInteres();
    int res=head(rec);
    while(not isNil(rec))
    {
        if(res<head(rec))
        {
            res=head(rec);
        }
    }
    return res;
}

int main()
{
    GenerarCiudad();
    PrintList(DeudaMasInteres());
    ImprimirTablero();
    return 0;
}
