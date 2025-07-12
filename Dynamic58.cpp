#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Dynamic58");
    int k=GetInt();
    PNode P1 = GetNode(), P2 = GetNode();
    P2->Next=P1;
    P1->Prev=P2;

    PNode P=P1,start,end;
    for(int i=0;i<k;i++)
    {
        P=P->Next;
    }

    start=P;
    end=P->Prev;

    start->Prev=nullptr;
    end->Next=nullptr;

    pt<<start<<end;

}
