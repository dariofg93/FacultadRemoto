#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"
using namespace std;

struct Color_y_Cantidad
{
    Color color;
    int cantidad;
};

void IrAlExtremoL(Dir d1)
{
    while(puedeMover(d1))
    {
        Mover(d1);
    }
}

struct NumeroColores
{
    int azul;
    int negro;
    int rojo;
    int verde;
};

Color_y_Cantidad mkColorYCantidad(Color c, int cant)
{
    Color_y_Cantidad res;
    res.color=c;
    res.cantidad=cant;
    return res;
}

NumeroColores mkNumeroColores()
{
    NumeroColores c;
    c.azul=0;
    c.negro=0;
    c.rojo=0;
    c.verde=0;
    return c;
}

NumeroColores totalColumnaEnNumeroColores()
{
    NumeroColores c=mkNumeroColores();
    IrAlExtremoL(Norte);
    while(puedeMover(Sur))
    {
        c.azul=c.azul+nroBolitas(Azul);
        c.negro=c.negro+nroBolitas(Negro);
        c.rojo=c.rojo+nroBolitas(Rojo);
        c.verde=c.verde+nroBolitas(Verde);
        Mover(Sur);
    }
    c.azul=c.azul+nroBolitas(Azul);
    c.negro=c.negro+nroBolitas(Negro);
    c.rojo=c.rojo+nroBolitas(Rojo);
    c.verde=c.verde+nroBolitas(Verde);
    return c;
}

List<Color_y_Cantidad> totalColumnaEnColorCantidad()
{
    List<Color_y_Cantidad> res=Nil<Color_y_Cantidad>();
    NumeroColores var=totalColumnaEnNumeroColores();
    Color_y_Cantidad ccazul=mkColorYCantidad(Azul,obtenerCantAzul(var));
    Color_y_Cantidad ccnegro=mkColorYCantidad(Azul,obtenerCantnegro(var));
    Color_y_Cantidad ccrojo=mkColorYCantidad(Azul,obtenerCantrojo(var));
    Color_y_Cantidad ccverde=mkColorYCantidad(Azul,obtenerCantverde(var));
    res= Snoc(Snoc(Snoc(Snoc(res,ccazul),ccnegro),ccrojo),ccverde);
    return res;
}

void agregarBolitaSiNoHay(Color c)
{
    if(not hayBolitas(Azul))
    {
        Poner(Azul);
    }
}

void agregarTantasVeces(int n,Color c)
 {
     int i=0;
     while(i<n)
     {
         agregarBolitaSiNoHay(c);
     }
 }

int main()
{
    agregarTantasVeces(50,Verde);
    ImprimirTablero();
    return 0;
}
