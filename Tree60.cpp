#include "pt4.h"
using namespace std;
int K,C,N;  

void count_k(PNode node)
{
    if (!node) return; 


    N++;
    if (node->Data > K)
        count_k(node->Left);
        
    else if (node->Data < K)
        count_k(node->Right);
        
    else
    {
        C++;
        count_k(node->Left);
        count_k(node->Right);
    }

}


void Solve()
{
    Task("Tree60");
    PNode root = GetNode();
    K = GetInt();
    C = 0;
    N = 0;

    count_k(root);
    
    pt<<C<<N;
}
