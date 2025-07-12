#include "pt4.h"
using namespace std;

PNode Build_level_tree(int num, int level)
{

    if (num == 0) return nullptr;
    
    PNode P = new Node;
    P->Data = level;

    if (num == 1)
    {
        P->Left = nullptr;
        P->Right = nullptr;
        return P;
    }

    num=num-1;
    P->Left = Build_level_tree(num-num/2, level+1);
    P->Right = Build_level_tree(num/2, level+1);
    return P;

}


void Solve()
{
    Task("Tree33");
    int n=GetInt();
    pt << Build_level_tree(n , 0);
    

}
