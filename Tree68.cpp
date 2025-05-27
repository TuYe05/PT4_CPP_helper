#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Tree68");
    Node* P1, * P2;
    pt >> P1 >> P2;

    // 找到P2左子树中的最大节点P及其父节点
    Node* parent_P = P2;
    Node* P = P2->Left;

    while (P->Right != nullptr) {
        parent_P = P;
        P = P->Right;
    }

    // 将P的值赋给P2
    P2->Data = P->Data;

    // 处理P的删除，类似Tree67的逻辑
    Node* child = P->Left;

    // 确定P是父节点的左还是右子节点，并链接子节点
    if (parent_P->Left == P) {
        parent_P->Left = child;
    } else {
        parent_P->Right = child;
    }

    delete P;

}
