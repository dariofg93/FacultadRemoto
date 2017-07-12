#include "Gobstones.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <map>

#define TOTAL_FILAS 9
#define TOTAL_COLUMNAS 9

using namespace std;

struct Celda
{

    map<Color,int> bolitas;


    Celda()
    {
        Color color = minColor();
        bool fin = false;
        while (!fin)
        {
            bolitas[color] = 0;
            color = siguiente(color);
            fin = color == siguiente(maxColor());
        }
    }


};


struct Gobstones
{
    int x;
    int y;
    Celda celdas[TOTAL_FILAS][TOTAL_COLUMNAS];

    Gobstones()
    {
        x = rand () % TOTAL_COLUMNAS;
        y = rand () % TOTAL_FILAS;
    }
};

Gobstones singleton;


void BOOM(string error)
{
    cout << "BOOM: " << error << endl;
    throw error;
}

bool celdaValida(int x, int y)
{
    return !(x < 0 || x >= TOTAL_COLUMNAS || y < 0 || y >= TOTAL_FILAS);
}

void validarCabezal(int x, int y)
{
    if (!celdaValida(x,y))
        BOOM("Te caiste del tablero!!!!");
}



int getXoffset(Dir d)
{
    if (d==Este)
        return +1;
    if (d==Oeste)
        return -1;
    return 0;
}

int getYoffset(Dir d)
{
    if (d==Norte)
        return +1;
    if (d==Sur)
        return -1;
    return 0;
}

void IniciarGobstones()
{
    singleton = Gobstones();
}

void Mover(Dir d)
{
    int xOfset =  getXoffset(d);
    int yOfset =  getYoffset(d);
    validarCabezal(singleton.x + xOfset,singleton.y +  yOfset);
    singleton.x = singleton.x + xOfset;
    singleton.y = singleton.y + yOfset;
}

void Poner(Color c)
{
    int x = singleton.x;
    int y = singleton.y;
    singleton.celdas[x][y].bolitas[c] ++;
}

void Sacar(Color c)
{
    if (singleton.celdas[singleton.x][singleton.y].bolitas[c] == 0)
        BOOM("No existe la bolita!!!");
    singleton.celdas[singleton.x][singleton.y].bolitas[c] --;
}

bool hayBolitas(Color c)
{
    return singleton.celdas[singleton.x][singleton.y].bolitas[c] > 0;
}

int nroBolitas(Color c)
{
    return singleton.celdas[singleton.x][singleton.y].bolitas[c];
}

bool puedeMover(Dir d)
{
    return celdaValida(singleton.x + getXoffset(d),singleton.y + getYoffset(d));
}




string itos(int intValue)
{
    stringstream b;
    b << intValue;
    return b.str();
}

int cantidadBolitasEnCelda(int col, int fila, Color color)
{
    return singleton.celdas[col][fila].bolitas[color];
}

#include <cstdlib>
#include <iostream>

void clear_screen()
{
#ifdef WINDOWS
    //std::system ( "CLS" );
#else
    // Assume POSIX
    //std::system ( "clear" );
#endif
    //HACK!!! los comandos de arriba no funcionan cygwin
    cout << endl;
    cout << endl;
}
void ImprimirTablero(std::string comments){
    cout << comments << endl;
    ImprimirTablero();
}

void ImprimirTablero(){
    clear_screen();
    int size = 44;
    string tablero[size];
    int i = 0;
    tablero[i++] = "    +---------+---------+---------+---------+---------+---------+---------+---------+---------+   \n";
    for (int f = 8; f >= 0; f--)
    {
        tablero[i++] = "    |         |         |         |         |         |         |         |         |         |    \n";
        tablero[i++] = "  "+itos(f)+" |         |         |         |         |         |         |         |         |         |    \n";
        tablero[i++] = "    |         |         |         |         |         |         |         |         |         |    \n";
        tablero[i++] = "    +---------+---------+---------+---------+---------+---------+---------+---------+---------+    \n";
    }
    tablero[i++] = "         0         1         2         3         4         5         6         7         8       \n";

    //TODO, hacer un mejor prity printing con colores y esas cosas
    for (int fila = TOTAL_FILAS -1; fila >= 0 ; fila--)
    {
        int baseX= 4*(TOTAL_FILAS - fila - 1);
        for (int col = 0 ; col < TOTAL_COLUMNAS ; col++)
        {
            int baseY  = 10* col + 4;
            Color color = minColor();
            bool fin = false;
            while (!fin)
            {
                int count = cantidadBolitasEnCelda(col,fila,color);
                int offsetV = color==Rojo || color==Verde ? 2 : 0;
                int offsetH = color==Verde || color==Negro ? 5 : 0;
                int baseXColor = baseX + offsetV + 1;
                int baseYColor = baseY - offsetH + 6;
                if (count>0)
                {
                    string countToString = itos(count) + getLetraColor(color);
                    tablero[baseXColor] =  tablero[baseXColor].replace(baseYColor,countToString.size(),countToString);
                }
                color = siguiente(color);
                fin = color == siguiente(maxColor());
            }
        }
    }

    int bx = 4*(TOTAL_FILAS - singleton.y - 1);
    int by = 10*singleton.x + 4;
    string filaLarga = "XXXXXXXXX";
    string filaCorta = "X";
    tablero[bx] =  tablero[bx].replace(by + 1,filaLarga.size(),filaLarga);
    tablero[bx + 4] =  tablero[bx + 4].replace(by + 1,filaLarga.size(),filaLarga);
    for (i = 1; i < 4 ; i++)
    {
        tablero[bx + i] =  tablero[bx + i].replace(by,filaCorta.size(),filaCorta);
        tablero[bx + i] =  tablero[bx + i].replace(by + 10,filaCorta.size(),filaCorta);
    }
    for (i = 0; i <size ; i++)
    {
        cout << tablero[i];
    }
  //  cout << "Presione Enter para continuar..." <<endl;
  //  cin.get();
}

