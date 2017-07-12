#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"

//Representa una cantidad de bolitas de cada color
struct NumeroColores {
int azul;
int negro;
int rojo;
int verde;
};
//Representa un color con una cantidad de bolitas
struct Color_y_Cantidad {
Color color;
int cantidad;
};
//Representa una distancia en una direccion
struct Dir_y_Dist {
Dir dir;
int dist;
};

NumeroColores mkNumerosColores()
{
    NumeroColores res;

    res.azul = 0;
    res.negro = 0;
    res.rojo = 0;
    res.verde = 0;

    return res;
}

int azul(NumeroColores r)
{
    return r.azul;
}

int negro(NumeroColores r)
{
    return r.negro;
}

int rojo(NumeroColores r)
{
    return r.rojo;
}

int verde(NumeroColores r)
{
    return r.verde;
}

NumeroColores agregarNumBolitasEnCelda(NumeroColores num)
{
    NumeroColores res = num;

    res.azul= azul(res) + nroBolitas(Azul);
    res.rojo = rojo(res) + nroBolitas(Rojo);
    res.verde = verde(res) + nroBolitas(Verde);
    res.negro = negro(res) + nroBolitas(Negro);

    return res;
}

void IrAlExtremo(Dir d)
{
    while(puedeMover(d))
    {
        Mover(d);
    }
}

NumeroColores totalColumnaEnNumeroColores()
{
    IrAlExtremo(Sur);
    NumeroColores res = mkNumerosColores();

    while (puedeMover(Norte))
    {
        res = agregarNumBolitasEnCelda(res);
        Mover(Norte);
    }

    res = agregarNumBolitasEnCelda(res);

    return res;
}

Color_y_cantidad agregarColorCantidad(Color c, int n)
{
    Color_y_cantidad res;

    res.color = c;
    res.cantidad = n;

    return res;
}

List<Color_y_cantidad> totalColumnaEnColorCantidad()
{
    List<Color_y_cantidad> koru= nil<Color_y_cantidad>();

    NumeroColores jejo= totalColumnaEnNumeroColores();

    koru = Snoc(koru, agregarColorCantidad(Azul, jejo.azul));
    koru = Snoc(koru, agregarColorCantidad(Negro, jejo.negro));
    koru = Snoc(koru, agregarColorCantidad(Rojo, jejo.rojo));
    koru = Snoc(koru, agregarColorCantidad(Verde, jejo.verde));

    return koru;
}

bool hayBolitasT()
{
    Color c = minColor();
    bool res = false;
    while(c != maxColor())
    {
        res = res or hayBolitas(c);
        c = siguiente(c);
    }

    res = res or hayBolitas(c);

    return res;
}

NumeroColores primeraBolitaEnFila()
{
    IrAlExtremo(Oeste);
    NumeroColores res = mkNumerosColores();

    while(puedeMover(Este) and not hayBolitasT())
    {
        Mover(Este);
    }

    res = agregarNumBolitasEnCelda(res);

    return res;
}

List<NumeroColores> primeraBolitaPorFila()
{
    List<NumeroColores> res = Nil<NumeroColores>();

    IrAlExtremo(Sur);

    while(puedeMover(Norte))
    {
        res = Snoc(res, primeraBolitaEnFila());
        Mover(Norte);
    }

    res = Snoc(res, primeraBolitaEnFila());

    return res;
}

void MoverN(Dir d, int n)
{
    int i = 1;

    while(i<=n)
    {
        Mover(d);
    }
}

Dir_y_Dist mkDir_y_Dist(Dir d, int n)
{
    Dir_y_Dist dis;
    dis.dir =d;
    dis.dist =n;
    return dis;
}
int moverYcontarHastaBolita(d)
{
    int cont = 0;
    while(puedeMover(Este) and not hayBolitasT())
    {
        Mover(Este);
        cont = cont + 1;
    }
    MoverN(-d,cont);
    return cont;
}

Dir_y_Dist compararPasosA(Dir d , Dir_y_Dist dd)
{
    Dir_y_Dist dyd = dd;
    int newDist = moverYcontarHastaBolita(d);
    if(newDist < dyd.dist)
    {
        dyd.dir=d;
        dyd.dist=newDist;
    }
    return dyd;
}

Dir_y_Dist bolitaMasCercanaEnFilaOColumna()
{
    Dir d = minDir();
    Dir_y_Dist dis;

    while (d != maxDir())
    {
        dis = compararPasosA(d,dis);
        d = siguiente(d);
    }
    dis = compararPasosA(d,dis);

    return dis;
}

List<Dir_y_Dist> mapaDeDistanciasEnFila()
{
    List<Dir_y_Dist> lista = Nil<Dir_y_Dist>();

    IrAlExtremo(Oeste);
    while(puedeMover(Este))
    {
        lista = Snoc(lista, bolitaMasCercanaEnFilaOColumna());
    }
    lista = Snoc(lista, bolitaMasCercanaEnFilaOColumna());

    return lista;
}

List<List<Dir_y_Dist>> mapaDeDistancias()
{
    List<List<Dir_y_Dist>> lista = Nil<List<Dir_y_Dist>>();

    IrAlExtremo(Sur);
    while(puedeMover(Norte))
    {
        lista = Snoc(lista, mapaDeDistanciasEnFila());
    }
    lista = Snoc(lista, mapaDeDistanciasEnFila());

    return lista;
}

Dir_y_Dist compararPasosB(Dir d , Dir_y_Dist dd)
{
    Dir_y_Dist dyd = dd;
    int newDist = moverYcontarHastaBolita(d);
    if(newDist > dyd.dist)
    {
        dyd.dir=d;
        dyd.dist=newDist;
    }
    return dyd;
}

Dir_y_Dist bolitaMasLejanaEnFilaOColumna()
{
    Dir d = minDir();
    Dir_y_Dist dis;

    while (d != maxDir())
    {
        dis = compararPasosB(d,dis);
        d = siguiente(d);
    }
    dis = compararPasosB(d,dis);

    return dis;
}

int main()
{

    return 0;
}
