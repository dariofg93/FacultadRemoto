#include "../../Biblioteca(CGobstones)/Gobstones.h"
#include "../../Biblioteca(CGobstones)/List.h"
using namespace std;

struct Parcial
{
    int tema;
    int nota;
};

struct Alumno
{
    int legajo;
    List<Parcial> parciales;
};

struct Curso
{
    List<Alumno> alumno;
    List <int> temas;
};

Curso mkCurso(List<Alumno> a, List<int> i)
{
    Curso c;
    c.alumno=a;
    c.temas=i;
    return c;
}

Alumno mkAlumno(int l, List<Parcial> p)
{
    Alumno a;
    a.legajo=l;
    a.parciales=p;
    return a;
}

Parcial mkParcial(int t, int n)
{
    Parcial p;
    p.tema=t;
    p.nota=n;
    return p;
}

Alumno setParcial(Alumno a, Parcial p)
{
    Alumno b=a;
    b.parciales=Snoc(b.parciales,p);
    return b;
}

Alumno agregarParcial(Alumno a, Parcial p)
{
    Alumno b=a;
    setParcial(mkParcial(p.tema,p.nota));
    return b;
}

Curso agregarAlumno(Curso cur, Alumno a)
{
    Curso c=cur;
    c.alumno=Snoc(c.alumno,a);
    return c;
}

Curso agregarParcialAlumno(Curso c, int legajo, Parcial p)
{

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
