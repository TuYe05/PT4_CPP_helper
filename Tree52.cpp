#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Tree52");
    PNode P1=GetNode() , P2=GetNode();
    PNode P=P1;
    int count=0 , check=-1;
    while(P)
    {
        
        if(P==P2)
        {
            check=count;
            break;
        }
        count++;
        P=P->Parent;
    }
    pt << check;

}
