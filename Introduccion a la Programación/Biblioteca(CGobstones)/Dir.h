#pragma once
#include <string>
#include <iostream>

//Tipo Dir, los valores posibles son: Norte, Este, Sur y Oeste

#define Norte Dir("Norte")
#define Este Dir("Este")
#define Sur Dir("Sur")
#define Oeste Dir("Oeste")


struct Dir{

    std::string nombre;

    Dir();

    Dir(const Dir &o);

    Dir(const std::string &o);

    int operator==(const Dir&o) const;

    int operator<(const Dir&o) const;

    int operator!=(const Dir&o) const{
        return !((*this) == o);
    }

    int operator>(const Dir&o) const{
        return !((*this) <= o);
    }

    int operator<=(const Dir&o) const{
        return (*this) < o || (*this) == o;
    }

    int operator>=(const Dir&o) const{
        return !((*this) < o);
    }
};


std::ostream& operator<<(std::ostream& out,const Dir &o);

/*
La expresión siguiente(<dir>), representa la dirección siguiente a <dir> en el orden.
Es cirular, la dirección siguiente a Oeste es Norte.
*/
Dir siguiente(Dir dir);

/*
La expresión previo(<dir>), representa la dirección previa a <dir> en el orden.
Es cirular, la dirección previa a Norte es Oeste.
*/
Dir previo(Dir dir);

/*
La expresión opuesto(<dir>), representa la dirección opuesta a <dir>.
La dirección opuesta de Norte es Sur, de Sur es Norte, de Este es Oeste y de Oeste es Este.
*/
Dir opuesto(Dir dir);

/*
La expresión minDir es la dirección mínima en el orden: Norte
*/
Dir minDir();

/*
La expresión maxDir es la dirección máxima en el orden: Oeste
*/
Dir maxDir();
