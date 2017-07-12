#include <iostream>
#include "../../Biblioteca(CGobstones)/Gobstones.h"
using namespace std;

//19

void PonerN(int n,Color c)
//Proposito: Pone tantas bolitas c, como sea el parametro n.
{
    int i=1;
    while(i<=n)
    {
        Poner(c);
        i=i+1;
    }
}

int cubo(int x)
//Proposito: Devuelve x³.
{
    int numero=x;
    int repeat=1;
    while(repeat<3)
    {
        numero=numero*x;
        repeat=repeat+1;
    }
    return numero;
}

int areaRectangulo(int xBase, int yAltura)
//Proposito: Devuelve el area de un rectangulo, dando las medidas xBase e yAltura.
{
    int area=xBase*yAltura;
    return area;
}

int abs(int n)
//Proposito: Devuelve el valor absoluto de n.
{
    int numero=n;
    if(n<0)
    {
        numero=-(numero);
    }
    return numero;
}

int max(int n1, int n2)
//Proposito: Dado 2 numeros (n1 y n2) devuelve el maximo entre ellos.
{
    int max=n1;
    if(n1<n2)
    {
        max=n2;
    }
    return max;
}

int max3(int n1,int n2,int n3)
//Proposito: Dado 3 numeros (n1, n2 y n3) devuelve el maximo entre ellos.
{
    int maxTotal=max(n1,n2);
    if(maxTotal<n3)
    {
        maxTotal=n3;
    }
    return maxTotal;
}

int main()
{
    PonerN(max3(1,2,3),Rojo);
    ImprimirTablero();
    return 0;
}
