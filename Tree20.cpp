#include "pt4.h"
using namespace std;
int count = 0 ;

void findmin(PNode current_node, int &min) 
{
    if (current_node== nullptr) 
        return ;
    if (current_node->Data < min)
        min = current_node->Data;
    findmin(current_node->Left, min);
    findmin(current_node->Right, min);
}

int count_leave(PNode current_node, int K) 
{
    if (current_node == nullptr)
        return 0;
    if (current_node->Data == K and current_node->Left == nullptr and current_node->Right == nullptr)
        count++;
    return count + count_leave(current_node->Left, K) + count_leave(current_node->Right, K);
}

void Solve()
{
    Task("Tree20");
    
    PNode root = GetNode();
    int min = 256;
    findmin(root , min);

    count_leave(root, min);
    
    pt << min << count;
    

}