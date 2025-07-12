#include "pt4.h"
using namespace std;

void ReleaseSubtree(PNode node)
{
    if (node==nullptr) return;
    ReleaseSubtree(node->Left);
    ReleaseSubtree(node->Right);
    DeleteNode(node);
}

PNode delete_node(PNode node, int num)
{
    if (!node) return nullptr;
    node->Left = delete_node(node->Left, num);
    node->Right = delete_node(node->Right, num);
    if (node->Data < num)
    {
        PNode P_prev = node->Parent;
        if (P_prev)
        {
            if (P_prev->Left == node)
                P_prev->Left = nullptr;
            else
                P_prev->Right = nullptr;
        }
        ReleaseSubtree(node);
        return nullptr;
    }
    return node;
}

void Solve(){
    Task("Tree42");
    PNode root = GetNode();
    root = delete_node(root, root->Data);
}