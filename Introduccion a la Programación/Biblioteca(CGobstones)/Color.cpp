
#include "Color.h"

using namespace std;



Color::Color()
{
    nombre = "NotAColor";
}
Color::Color(const Color &c)
{
    nombre = c.nombre;
}

Color::Color(const std::string &unNombre)
{
    nombre = unNombre;
}

std::ostream& operator<<(std::ostream& out,const Color &c)
{
    out << c.nombre;
    return out;
}

int Color::operator==(const Color&c) const
{
    return nombre == c.nombre;
}
int Color::operator<(const Color&c) const
{
    return nombre < c.nombre;
}

Color opuesto(Color c)
{
    return siguiente(siguiente(c));
}

Color siguiente(Color c)
{
    if (c == Azul){
        return Negro;
    }
    if (c == Negro){
        return Rojo;
    }
    if (c == Rojo){
        return Verde;
    }
    if (c == Verde){
        return Azul;
    }
    throw string("Color inválido: " + c.nombre);
}

Color previo(Color c)
{
     if (c == Azul){
        return Verde;
    }
    if (c == Negro){
        return Azul;
    }
    if (c == Rojo){
        return Negro;
    }
    if (c == Verde){
        return Rojo;
    }
    throw string("Color inválido: " + c.nombre);
}

Color minColor()
{
    return Azul;
}

Color maxColor()
{
    return Verde;
}


char getLetraColor(Color c)
{
    return c.nombre[0];
}
