#pragma once
#include <string>
#include "Color.h"
#include "Dir.h"


/*
Destrucci�n del tablero. El string <msj> es la causa de la destucci�n.
*/
void BOOM(std::string msj);

/*
Inicializa el ambiente gobstones:
- Vacia las celdas
- Pone el cabezal en una posici�n aleatoria
*/
void IniciarGobstones();

/*
La instrucci�n Mover(<dir>) indica al cabezal que debe moverse una celda en la direcci�n <dir>, si es posible.
*/
void Mover(Dir dir);

/*
La instrucci�n Poner(<color>) indica al cabezal que coloque una bolita del color <color> en la celda actual.
*/
void Poner(Color color);

/*
La instrucci�n Sacar(<color>) indica al cabezal que quite una bolita del color <color> de la celda actual, si hay alguna.
*/
void Sacar(Color color);

/*
La expresi�n hayBolitas(<color>) describe el hecho de que exista una bolita de color <color> en la celda actual.
*/
bool hayBolitas(Color color);

/*
La expresi�n nroBolitas(<color>) representa al n�umero de bolitas de color <color> que hay en la celda actual.
*/
int nroBolitas(Color color);

/*
La expresi�n puedeMover(<dir>) representa a un booleano que indica si el cabezal
se puede mover en la direcci�n <dir> sin provocar su autodestrucci�n.
*/
bool puedeMover(Dir dir);

/*
Imprime el tablero en consola con un comentario.
*/
void ImprimirTablero(std::string comments);

/*
Imprime el tablero en consola.
*/
void ImprimirTablero();


