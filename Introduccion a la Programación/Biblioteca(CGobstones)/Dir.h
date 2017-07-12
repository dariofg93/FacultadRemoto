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
La expresi�n siguiente(<dir>), representa la direcci�n siguiente a <dir> en el orden.
Es cirular, la direcci�n siguiente a Oeste es Norte.
*/
Dir siguiente(Dir dir);

/*
La expresi�n previo(<dir>), representa la direcci�n previa a <dir> en el orden.
Es cirular, la direcci�n previa a Norte es Oeste.
*/
Dir previo(Dir dir);

/*
La expresi�n opuesto(<dir>), representa la direcci�n opuesta a <dir>.
La direcci�n opuesta de Norte es Sur, de Sur es Norte, de Este es Oeste y de Oeste es Este.
*/
Dir opuesto(Dir dir);

/*
La expresi�n minDir es la direcci�n m�nima en el orden: Norte
*/
Dir minDir();

/*
La expresi�n maxDir es la direcci�n m�xima en el orden: Oeste
*/
Dir maxDir();
