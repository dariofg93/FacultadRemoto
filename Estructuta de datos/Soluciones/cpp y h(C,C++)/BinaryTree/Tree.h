#include <iostream>
#define ET int

using namespace std;

struct TreeNode;
typedef TreeNode* Tree;

Tree NodeT(ET root, Tree izq, Tree der);
Tree EmptyT();

ET root(Tree t);
Tree izq(Tree t);
Tree der(Tree t);

void setRoot(ET root, Tree& t);

bool isEmptyT(Tree t);
