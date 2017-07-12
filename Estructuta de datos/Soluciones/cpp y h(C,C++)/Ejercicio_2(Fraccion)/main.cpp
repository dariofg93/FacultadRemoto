#include <iostream>
#include "Fraccion.h"

using namespace std;

int main()
{
    Fraccion f1 = fraccion(200,40);
    simplificar(f1);

    cout << getDen(f1) << endl;

    return 0;
}
