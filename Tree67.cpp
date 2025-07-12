#include "pt4.h"
using namespace std;

/*
!!!感谢张博帮助我!!!
Tree67.给出了两个指针：P1指向非空搜索树的根，P2指向其不超过一个子节点的节点之一。
从树中删除节点P2，使树仍然是搜索树（如果节点P2有子节点，则将子节点与节点P2的父节点链接）。
如果生成的树不为空，则将指针P3输出到其根，否则输出NULL。
*/

void Solve()
{
    Task("Tree67");
    Node* P1, * P2;
    pt >> P1 >> P2;

    Node* root = P1;
    Node* parent = nullptr;
    Node* current = P1;

    while (current && current != P2)
    {
        parent = current;
        if (P2->Data < current->Data)
            current = current->Left;
        else
            current = current->Right;
    }

    if (!current)
    {
        pt << root;
        return;
    }

    Node* child = (P2->Left) ? P2->Left : P2->Right;
    if (!parent)
    {
        root = child;
    }
    else
    {
        if (parent->Left == P2)
            parent->Left = child;
        else
            parent->Right = child;
    }

    delete P2; 
    pt << root;
}


