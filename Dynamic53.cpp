#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Dynamic53");
    PNode PX = GetNode();
    PNode PY = GetNode();
    
    
    PNode P1,P2;

    PNode PX_prev = (PX->Prev) ? PX->Prev : NULL;
    PNode PY_next = (PY->Next) ? PY->Next : NULL;
    if(PX_prev && PY_next)
    {
        P1=PY;while(P1->Prev!=NULL){P1=P1->Prev;}

        PX_prev->Next = PY_next;
        PY_next->Prev = PX_prev;

        PX->Prev = NULL;
        PY->Next = NULL;

        P2=PX;
    }
    else if(PX_prev && !PY_next)
    {
        P1=PY;while(P1->Prev!=NULL){P1=P1->Prev;}

        PX_prev->Next =NULL;
        PX->Prev = NULL;
        P2=PX;
    }
    else if(!PX_prev && PY_next)
    {
        P2=PX;
        P1=PY_next;
        
        PY->Next = NULL;
        PY_next->Prev = NULL;
    }
    else
    {
        P2=PX;
        P1=NULL;
    }
        
        
    
    pt << P1 << P2;
}
