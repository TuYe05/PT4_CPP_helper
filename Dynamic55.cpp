#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Dynamic55");
    PNode P1 = GetNode();
    
    // 查找原链表的最后一个节点
    PNode Last = P1;
    while (Last->Next != nullptr) 
    {
        Last = Last->Next;
    }
    
    // 将链表转换为循环双向链表
    Last->Next = P1;    // 尾节点Next指向头节点
    P1->Prev = Last;    // 头节点Prev指向尾节点
    
    // 输出原尾节点地址
    pt << Last;

}
