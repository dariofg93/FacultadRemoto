#include <iostream>

using namespace std;

struct MaybeSt;
typedef MaybeSt* Maybe;

Maybe nothing ();
Maybe just(int n);
int fromJust(Maybe may);
bool isNothing(Maybe may);
