#include <iostream>
#include "Pokemon.h"

using namespace std;

struct PokemonSt {
    string nombre;
    int vida;
};

Pokemon crearPokemon(string nombre){
    Pokemon p = new PokemonSt;
    p->nombre = nombre;
    p->vida = 100;
    return p;
}

void restarVida(Pokemon& p){
    p->vida = p->vida -1;
}

void cambiarNombre(Pokemon& p, string nombre){
    p->nombre = nombre;
}

bool estaVivo(Pokemon p){
    return (not(p->vida == 0));
}

string getNombre(Pokemon p){
    return (p->nombre);
}

int getVida(Pokemon p){
    return (p->vida);
}

void luchar(Pokemon& p, Pokemon& r){
    restarVida(p);
    restarVida(r);
}

void restarVidaN(Pokemon& p, int n){
    p->vida = p->vida - n;
}

void lucharN(int n, Pokemon& p, Pokemon& r){
    restarVidaN(p,n);
    restarVidaN(r,n);
}
