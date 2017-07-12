#include <iostream>

using namespace std;

struct QueueNode;
typedef QueueNode* Queue;

Queue emptyQ();
bool isEmptyQ(Queue q);
void queue(Queue& q, int x);
int firstQ(Queue q);        //PARCIAL EN NULL
void dequeue(Queue& q);     //PARCIAL EN NULL
void destroyQ(Queue& q);
