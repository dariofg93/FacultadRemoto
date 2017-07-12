#include <iostream>

using namespace std;

struct Node;
typedef Node* List;

List empty();
void Cons(int x, List& xs);
bool isEmpty(List xs);
int head (List xs);
List tail(List xs);
int length(List xs);
