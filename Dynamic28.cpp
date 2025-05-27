#include "pt4.h"
using namespace std;

struct TQueue 
{
    PNode Head;
    PNode Tail;
};

int Dequeue(TQueue &Q)
{
    PNode oldHead = Q.Head;
    int value = oldHead->Data;
    
    Q.Head = Q.Head->Next;
    if (Q.Head == nullptr)
        Q.Tail = nullptr;
    
    DeleteNode(oldHead);
    return value;
}

bool QueueIsEmpty(TQueue Q)
{
    return Q.Head == nullptr;
}

void Solve()
{
    Task("Dynamic28");
    
    PNode P1 = GetNode();
    PNode P2 = GetNode();
    TQueue Q = {P1, P2};
    
    int count = 0;
    while (count < 5 && !QueueIsEmpty(Q))
    {
        pt << Dequeue(Q);
        count++;
    }
    
    pt << QueueIsEmpty(Q);
    pt << Q.Head << Q.Tail;
}
