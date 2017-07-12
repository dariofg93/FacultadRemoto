#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"

struct Fecha
{
    int dia;
    int mes;
    int anio;

};

Fecha mkFecha(int d, int m, int a)
{
    Fecha f;
    f.dia=d;
    f.mes=m;
    f.anio=a;
    return f;
}

struct Persona
{
    int dni;
    int domicilio;
    bool esVaron;
    Fecha fechaNacimiento;
};

Fecha edad(Persona p)
{
    return p.fechaNacimiento;
}

bool primerFechaEsMayor(Fecha a, Fecha b)
{
    Fecha asd=a;
    Fecha asdf=b;
    bool var=false;
    if(asd>asdf) ///averiguar como sacar una fecha mayor que la otra blablablablalbablablablablabla...
    {
        var=true;
    }
    return var;
}

Persona elMasViejo(List<Persona> p)
{
    List<Persona> rec=p;
    Fecha eV=mkFecha(0,0,0);
    Persona var=head(p);
    while(not isNil(rec))
    {
        if(primerFechaEsMayor(head(rec),eV)) ///hacer funcion que dada dos fechas retorne un bool si el 1º es mayor
        {
            eV=edad(head(rec));
            var=head(p);
        }
        rec=tail(rec);
    }
    return var;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
