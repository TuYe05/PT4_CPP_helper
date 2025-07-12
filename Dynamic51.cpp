//Dynamic51.给出了两个非空双链表；指针P1和P2指第一列表的第一个和最后一个组件、指针P0指第二列表的组件之一。通过在第二个列表的给定组件之前插入第一个列表的所有组件（顺序相同）来组合给定的列表。输出组合列表的第一个和最后一个组件的地址。不要使用分配和释放内存的操作。

#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Dynamic51");
    
    // 获取输入指针
    PNode P1 = GetNode(), P2 = GetNode(), P0 = GetNode();
    
    // 找到第二个链表的原首节点和尾节点
    PNode S = P0;
    while (S->Prev != nullptr)
        S = S->Prev;
    PNode E = P0;
    while (E->Next != nullptr)
        E = E->Next;
    
    // 保存P0的原始前驱节点
    PNode P0_Prev = P0->Prev;
    
    // 连接第一个链表到P0之前
    PNode newHead = S;
    if (P0_Prev != nullptr)
    {
        P0_Prev->Next = P1;
        P1->Prev = P0_Prev;

        P2->Next = P0;
        P0->Prev = P2;
    }
    else
    {
        //P0_Prev->Next = P1;
        //P1->Prev = P0_Prev;

        P2->Next = P0;
        P0->Prev = P2;

        newHead = P1;
    }
    PNode newTail = E;
    // 输出结果
    pt << newHead << newTail;
}