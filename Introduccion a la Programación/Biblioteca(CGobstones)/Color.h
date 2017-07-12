#pragma once
#include <string>
#include <iostream>

#define Azul Color("Azul")
#define Negro Color("Negro")
#define Rojo Color("Rojo")
#define Verde Color("Verde")

/*
Tipo Color, los valores posibles son: Azul, Negro,Rojo y Verde

enum Color {
  Azul,
  Negro,
  Rojo,
  Verde
};
*/

struct Color{

    std::string nombre;

    Color();

    Color(const Color &o);

    Color(const std::string &o);

    int operator==(const Color&o) const;

    int operator<(const Color&o) const;

    int operator!=(const Color&o) const{
        return !((*this) == o);
    }

    int operator>(const Color&o) const{
        return !((*this) <= o);
    }

    int operator<=(const Color&o) const{
        return (*this) < o || (*this) == o;
    }

    int operator>=(const Color&o) const{
        return !((*this) < o);
    }
};



std::ostream& operator<<(std::ostream& out,const Color &o);

/*
La expresión siguiente(<color>), representa el color siguiente a <color> en el orden.
Es cirular, el color siguiente a Verde es Azul.
*/
Color siguiente(Color color);


/*
La expresión previo(<color>), representa el color previo a <color> en el orden.
Es cirular, el color  previo a Azul es Verde.
*/
Color previo(Color color);


/*
La expresión opuesto(<color>), representa el color opuesto a <dir>.
El color opuesto de Azul es Rojo, de Rojo es Azul, de Negro es Verde y de Verde es Negro.
*/
Color opuesto(Color color);


/*
La expresión minColor es el color mínimo en el orden: Azul.
*/
Color minColor();

/*
La expresión maxColor es el color máximo en el orden: Verde.
*/
Color maxColor();

/*
Retorna la primera letra del nombre del color
*/
char getLetraColor(Color c);
