#include <iostream>

using namespace std;

void printNumbers(int arreglo[]){

    cout << "[";
    for(int i=0;i<sizeof(arreglo)+1;i++){
        cout << arreglo[i];
        if (i<sizeof(arreglo))
            cout << ",";
    }
    cout << "]" << endl;

}

//Dada una lista de enteros devuelve la suma de todos sus elementos.
int sumatoria (int array[]){
    int total = 0;
    for(int i=0;i<sizeof(array)+1;i++)
        total = total + array[i];
    return total;
}
/*
//Dada una lista de elementos de algun tipo devuelve el largo de esa lista, es decir,
//la cantidad de elementos que posee.
int longitud(char array[])

//Dada una lista de enteros, devuelve un numero que es el promedio entre todos los elementos
//de la lista. ¿Pudo resolverla utilizando recursion estructural?
int promedio(int array[])

//Dada una lista de enteros, devuelve la lista de los sucesores de cada entero.
int[] mapSucesor(int array[])

//Dada una lista de pares de enteros, devuelve una nueva lista en la que cada elemento es la
//suma de los elementos de cada par.      TAD
//TAD[] mapSumaPar(TAD array[])

//Dada una lista de pares, devuelve una nueva lista en la que cada elemento es el mayor de
//las componentes de cada par.
//TAD[] mapMaxDelPar(TAD array[])

//Dada una lista de booleanos devuelve True si todos sus elementos son True.
bool todoVerdad(bool array[])

//Dada una lista de booleanos devuelve True si alguno de sus elementos es True.
bool algunaVerdad(bool array[])

//Dados un elemento e y una lista xs devuelve True si existe un elemento en xs que sea igual a e.
bool pertenece(int array[], int n)

//Dados un elemento e y una lista xs cuenta la cantidad de apariciones de e en xs.
int apariciones(int array[], int n)

//Dados un numero n y una lista xs, devuelve todos los elementos de xs que son menores a n.
int filtrarMenoresA(int array[], int n)

//Dados un elemento y una lista filtra (elimina) todas las ocurrencias de ese elemento en la lista.
int[] filtrarElemento(int array[], int n)

//Dada una lista de listas, devuelve la lista de sus longitudes. Aplique esta funcion a la lista
//de strings ["Estructuras", "de", "datos"] y observe el resultado.
int[] mapLongitudes(string arStrings[[]])

//Dados un numero n y una lista de listas, devuelve la lista de aquellas listas que tienen mas de n elementos.
int[] longitudMayorA(string arStrings[[]])

//Dado un elemento e y una lista xs, ubica a e entre medio de todos los elementos de xs. Ejemplo:
//intercalar ’,’ "abcde" == "a,b,c,d,e"
int[] intercalar(char array[], char x)
*/
int main()
{
    int list[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << sumatoria(list) << endl;
    return 0;
}
