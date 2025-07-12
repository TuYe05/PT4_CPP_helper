#include "pt4.h"
using namespace std;
int count = 0;

int countK(PNode current_node, int K)
{
    if (current_node == nullptr)
        return 0;
    if (current_node->Data == K)
        count++;
    return count + countK(current_node->Left, K) + countK(current_node->Right, K);
}

void Solve()
{
    Task("Tree3");
    
    PNode root = GetNode();
    int K=GetInt();
    
    countK(root, K);
    
    pt<<count;
    

}
