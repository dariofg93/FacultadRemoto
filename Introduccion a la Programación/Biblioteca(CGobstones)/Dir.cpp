
#include "Dir.h"

using namespace std;



Dir::Dir()
{
    nombre = "NotAColor";
}
Dir::Dir(const Dir &d)
{
    nombre = d.nombre;
}

Dir::Dir(const std::string &unNombre)
{
    nombre = unNombre;
}

std::ostream& operator<<(std::ostream& out,const Dir &d)
{
    out << d.nombre;
    return out;
}

int Dir::operator==(const Dir&d) const
{
    return nombre == d.nombre;
}
int Dir::operator<(const Dir&d) const
{
    return nombre < d.nombre;
}


Dir siguiente(Dir d)
{
     if (d == Norte){
        return Este;
    }
    if (d == Este){
        return Sur;
    }
    if (d == Sur){
        return Oeste;
    }
    if (d == Oeste){
        return Norte;
    }
    throw string("Dirección inválida: " + d.nombre);
}

Dir previo(Dir d)
{
    if (d == Norte){
        return Oeste;
    }
    if (d == Este){
        return Norte;
    }
    if (d == Sur){
        return Este;
    }
    if (d == Oeste){
        return Sur;
    }
    throw string("Dirección inválida: " + d.nombre);
}
Dir opuesto(Dir d)
{
    return siguiente(siguiente(d));
}

Dir minDir()
{
    return Norte;
}

Dir maxDir()
{
    return Oeste;
}
