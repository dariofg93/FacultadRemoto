#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"
using namespace std;

struct Cliente
{
    int horaIngresoCola;
    int cantProductos;
};

struct Caja
{
    int nroCaja;
    List<Cliente> clientesEsperando;
};

struct Super
{
    int horaActual;
    List<Caja> lineaDeCajas;
    List<Cliente> clientesComprando;
};

Caja mkCaja(int n, List<Cliente> c)
///Proposito: Crea una nueva caja con los valores que se generen al completar los parametros.
{
    Caja ca;
    ca.nroCaja=n;
    ca.clientesEsperando=c;
    return ca;
}

int cantClientes(Caja c)
///Proposito: Dada una caja, devuelve la cantidad de su lista de clientes.
{
    int cont=0;
    List<Cliente> rec=c.clientesEsperando;
    while(not isNil(rec))
    {
        cont=cont+1;
        rec=tail(rec);
    }
    return cont;
}

int obtenerNumeroCaja(Caja c)
///Proposito: Dada una caja, Devuelve el numero de la misma.
{
    return c.nroCaja;
}

Caja cajaMasVacia(List<Caja> cajas)
/**Proposito: Devuelve la caja con menos cliente y en caso de empate, devuelve la caja con menor numero.
   Precondicion: La lista lineaDeCajas debe ser no vacia.
**/
{
    Caja total;
    int minimoTemporal=25000;
    List<Caja> rec=cajas;
    List<Caja> rec2=cajas;
    while(not isNil(rec))
    {
        if(cantClientes(head(rec))<minimoTemporal)
        {
            minimoTemporal=cantClientes(head(rec));
            total=mkCaja(head(rec).nroCaja,head(rec).clientesEsperando);
        }
        rec=tail(rec);
    }
    while(not isNil(rec2))
    {
        if(obtenerNumeroCaja(head(rec2))<total.nroCaja and cantClientes(head(rec2))==cantClientes(total))
        {
            total=mkCaja(obtenerNumeroCaja(head(rec2)),head(rec2).clientesEsperando);
        }
        rec2=tail(rec2);
    }
    return total;
}

List<Caja> agregarCliente(List<Caja> lineaDeCajas, Cliente c)
/**Proposito: Dadas una lineaDeCajas y un cliente, agrega al cliente a la caja mas vacia del super.
   Precondicion: La lista lineaDeCajas debe ser no vacia.
**/
{
    List<Caja> cajas=lineaDeCajas;
    Caja var=cajaMasVacia(cajas);
    var.clientesEsperando=Snoc(var.clientesEsperando,c);
    return cajas;
}

Caja buscarCajaPorNro(List<Caja> c, int n)
///Proposito: Dado una lista de cajas y un numero, devuelve la caja con el numero asignado.
{
    List<Caja> rec=c;
    Caja res;
    while(not isNil(rec))
    {
        if(head(rec).nroCaja==n)
        {
            res=mkCaja(n,head(rec).clientesEsperando);
        }
        rec=tail(rec);
    }
    return res;
}

List<Cliente> obtenerCliente(Caja c)
///Proposito: Dada una caja, devuelve la lista de clientes de la misma.
{
    return c.clientesEsperando;
}

List<Caja> avanzarCaja(List<Caja> lineaDeCajas, int nroCaja)
/**Proposito: Dada una lista de cajas, analiza la caja que tenga el numero dado.
   Precondicion: Debe haber una caja identicada por el numero nroCaja.
**/
{
    List<Caja> ca=lineaDeCajas;
    Caja analizar=buscarCajaPorNro(ca,nroCaja);
    if(not isNil(analizar.clientesEsperando))
    {
        if(head(obtenerCliente(analizar)).cantProductos>0)
        {
            head(obtenerCliente(analizar)).cantProductos=head(obtenerCliente(analizar)).cantProductos-1;
        }
        else
        {
            analizar.clientesEsperando=tail(analizar.clientesEsperando);
        }
    }
    return ca;
}

List<Caja> avanzarLineaDeCajas(List<Caja> lineaDeCajas)
{
    List<Caja> rec=lineaDeCajas;
    List<Caja> res=Nil<Caja>();
    while(not isNil(rec))
    {
        res=Snoc(res,head(avanzarCaja(rec,obtenerNumeroCaja(head(rec)))));
        rec=tail(rec);
    }
    return res;
}

int main()
{
    cout << "Hello world jojooojo!" << endl;
    return 0;
}
