#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"
using namespace std;

struct Fecha
/**Proposito: Crea nuevo tipo con 3 campos
   Invariante de representacion: los valores deben ser validos: dia(1-31), mes(1-12), año(x>0).
**/
{
    int dia;
    int mes;
    int anio;
};

struct Persona
///Proposito: Crea nuevo tipo con 4 campos
{
    int   dni;
    int   domicilio;
    bool  esVaron;
    Fecha fecha;
};

Persona mkPersona(int d, int dom, bool v, Fecha f)
/**Proposito: Crea una persona nueva completando los parametros.
   Invariante de representacion: Todos los valores deben ser validos.
**/
{
    Persona p;
    p.dni=d;
    p.domicilio=dom;
    p.esVaron=v;
    p.fecha=f;
    return p;
}

int obtenerDni(Persona p)
///Proposito: Dada una persona, devuelve su DNI.
{
    return p.dni;
}

int obtenerDomicilio(Persona p)
///Proposito: Dada una persona, devuelve su domicilio.
{
    return p.domicilio;
}

bool obtenerSexo(Persona p)
///Proposito: Dada una persona, devuelve si es hombre o no.
{
    return p.esVaron;
}

Fecha obtenerDNI(Persona p)
///Proposito: Dada una persona, devuelve su fecha de nacimiento.
{
    return p.fecha;
}

bool convivientes(Persona p1, Persona p2)
///Proposito: Devuelve true si dos personas viven en la misma vivienda.
{
    return p1.domicilio==p2.domicilio;
}

Persona mkNacimiento(Persona m, bool v, Fecha f)
///Proposito: Devuelve una persona hija/o dada una persona madre un sexo y una fecha de nacimiento.
{
    Persona p=m;
    p.esVaron=v;
    p.fecha=f;
    return p;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
