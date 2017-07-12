#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"
using namespace std;

void PonerN(int n, Color c)
{
    int i=0;
    while(i<n)
    {
        Poner(c);
        i=i+1;
    }
}

struct Fecha
/**Proposito: Crea nuevo tipo con 3 campos
   Invariante de representacion: los valores deben ser validos: dia(1-31), mes(1-12), año(x>0).
**/
{
    int dia;
    int mes;
    int anho;
};

Fecha mkFecha(int d, int m, int a)
///Proposito: Crea una nueva fecha completando los parametros.
{
    Fecha f;
    f.dia=d;
    f.mes=m;
    f.anho=a;
    return f;
}

Fecha dia(Fecha f)
///Propsito: Llama a la funcion para devolver el dia.
{
    Fecha fechaCon;
    fechaCon.dia=f.dia;
    return fechaCon;
}

Fecha mes(Fecha f)
///Propsito: Llama a la funcion para devolver el mes.
{
    Fecha fechaCon;
    fechaCon.mes=f.mes;
    return fechaCon;
}

Fecha anho(Fecha f)
///Propsito: Llama a la funcion para devolver el año.
{
    Fecha fechaCon;
    fechaCon.anho=f.anho;
    return fechaCon;
}

bool eqFecha(Fecha f1, Fecha f2)
///Proposito: Dada dos fechas devuelve true si ambas son iguales.
{
    bool res=false;
    if(f1.anho==f2.anho and f1.mes==f2.mes and f1.dia==f2.dia)
    {
        res=true;
    }
    return res;
}

bool itFecha(Fecha f1, Fecha f2)
///Proposito: Dadas dos fechas, devuelve true si la primera es menor a la segunda y false si la primera es menor o son iguales las dos.
{
    bool res=false;
    if(f1.anho<f2.anho)
    {
        res=true;
    }
    if(f1.anho==f2.anho)
    {
        if(f1.mes<f2.mes)
        {
            res=true;
        }
        if (f1.mes==f2.mes)
        {
            if(f1.dia<f2.dia)
            {
                res=true;
            }
        }
    }
    return res;
}

int abs(int n)
//Proposito: Devuelve el valor absoluto de n.
{
    int numero=n;
    if(n<0)
    {
        numero=-(numero);
    }
    return numero;
}

int anhosEntre(Fecha f1, Fecha f2)
///Proposito: Dadas dos fechas devuelve la cantidad de años completos entre ellas
{
    int cont=abs(f1.anho-f2.anho);
    if(itFecha(f1,f2))
    {
        f1.anho=f1.anho-cont;
        if(itFecha(f1,f2))
        {
            cont=cont-1;
            f1.anho=f1.anho+cont+1;
        }
    }
    else
    {
        if(not(itFecha(f1,f2)))
        {
            f2.anho=f2.anho-cont;
            if(itFecha(f2,f1))
            {
                cont=cont-1;
                f2.anho=f2.anho+cont+1;
            }
        }
    }
    return cont;
}

bool bisiesto(Fecha f)
///Proposito: Dada una fecha retorna true si el año es bisiesto.
{
    bool var=false;
    if(f.anho%4==0)
    {
        var=true;
    }
    return var;
}

int main()
{
    PonerN(anhosEntre(mkFecha(16,11,1993),mkFecha(16,10,1998)),Rojo);
    ImprimirTablero();
    return 0;
}
