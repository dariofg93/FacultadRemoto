#include "Fraccion.h"

using namespace std;

struct FraccionNode{
    int num;
    int den;
};

Fraccion fraccion(int x, int y){
    Fraccion f = new FraccionNode;
    f->num = x;
    f->den = y;
    return f;
}

Fraccion sumar(Fraccion f1, Fraccion f2){
    return(fraccion(((f1->num)*(f2->den))+
                    ((f2->num)*(f1->den)),
                    (f1->den)*(f2->den)));
}

Fraccion restar(Fraccion f1, Fraccion f2){
    return(fraccion(((f1->num)*(f2->den))-
                    ((f2->num)*(f1->den)),
                    (f1->den)*(f2->den)));
}

Fraccion multiplicar(Fraccion f1, Fraccion f2){
    return(fraccion(((f1->num)*(f2->num)),
                    ((f1->den)*(f2->den))));
}

Fraccion dividir(Fraccion f1, Fraccion f2){
    Fraccion fDiv = fraccion(f2->den,f2->num);
    return(multiplicar(f1,fDiv));
}

void invertir(Fraccion& f1){
    int numerador = f1->den;
    f1->den = f1->num;
    f1->num = numerador;
}

bool puedeDividir(Fraccion f1,int n){
    return((f1->num % n == 0) && (f1->den % n == 0));
}

void simplificarPor(Fraccion& f1,int n){
    f1->num = f1->num / n;
    f1->den = f1->den / n;
}

void simplificar(Fraccion& f1){
    for(int divisor=20; divisor>1; divisor--){
        if(puedeDividir(f1,divisor))
            simplificarPor(f1,divisor);
    }
}

int getNum(Fraccion f){
    return(f->num);
}
int getDen(Fraccion f){
    return(f->den);
}
