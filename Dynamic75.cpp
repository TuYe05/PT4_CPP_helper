#include "pt4.h"
using namespace std;

struct TListB 
{
    PNode Barrier;  // Sentinel node for easier edge case handling
    PNode Current;  // Pointer to current/first element in list
};

TListB LBInsertFirst(TListB &Q, int x)
{
    PNode newnode = new Node;
    newnode->Data = x;

    newnode->Next = Q.Current;       
    Q.Current->Prev = newnode;       

    newnode->Prev = Q.Barrier;       
    Q.Barrier->Next = newnode;

    return { Q.Barrier, newnode };
}

void Solve()
{
    Task("Dynamic75");
    PNode P1 = GetNode(), P2 = GetNode();

    //TListB Q = { P1, P1->Next };
    
    TListB Q ;
    Q.Barrier = P1;
    Q.Current = P1->Next;

    int n = GetInt();
    for (int i = 0; i < n; i++)
    {
        Q = LBInsertFirst(Q, GetInt());
    }
    pt << Q.Current;
}
