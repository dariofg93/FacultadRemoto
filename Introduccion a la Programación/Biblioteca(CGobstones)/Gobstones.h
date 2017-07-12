#pragma once
#include <string>
#include "Color.h"
#include "Dir.h"


/*
Destrucción del tablero. El string <msj> es la causa de la destucción.
*/
void BOOM(std::string msj);

/*
Inicializa el ambiente gobstones:
- Vacia las celdas
- Pone el cabezal en una posición aleatoria
*/
void IniciarGobstones();

/*
La instrucción Mover(<dir>) indica al cabezal que debe moverse una celda en la dirección <dir>, si es posible.
*/
void Mover(Dir dir);

/*
La instrucción Poner(<color>) indica al cabezal que coloque una bolita del color <color> en la celda actual.
*/
void Poner(Color color);

/*
La instrucción Sacar(<color>) indica al cabezal que quite una bolita del color <color> de la celda actual, si hay alguna.
*/
void Sacar(Color color);

/*
La expresión hayBolitas(<color>) describe el hecho de que exista una bolita de color <color> en la celda actual.
*/
bool hayBolitas(Color color);

/*
La expresión nroBolitas(<color>) representa al núumero de bolitas de color <color> que hay en la celda actual.
*/
int nroBolitas(Color color);

/*
La expresión puedeMover(<dir>) representa a un booleano que indica si el cabezal
se puede mover en la dirección <dir> sin provocar su autodestrucción.
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


