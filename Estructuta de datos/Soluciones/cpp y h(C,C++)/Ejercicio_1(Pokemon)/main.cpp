#include <iostream>
#include <stdio.h>
#include "Pokemon.h"

using namespace std;

int main()
{
    Pokemon p = crearPokemon("Pikachu");
    restarVida(p);
    Pokemon f = crearPokemon("Charizard");
    Pokemon h = crearPokemon("Yvasuour");
    Pokemon a = crearPokemon("Saquirtle");
    cambiarNombre(a,"Suicune");
    lucharN(100,f,h);
    //PREGUNTAR DELETE.
    cout << getVida(p) << endl;
    cout << estaVivo(p) << endl;
    cout << estaVivo(f) << endl;
    cout << getNombre(a) << endl;

    return 0;
}
