//    Dynamic26Dynamic26.给出指向队列头部和尾部的指针P1和P2（如果队列为空，则指针等于NULL）。还给出了一个整数N（>0）和一个N个整数的序列。定义一个名为TQueue的新类型，它是一个具有PNode类型的Head和Tail两个字段的记录（字段分别指队列的头部和尾部）。还要编写一个过程Enqueue（Q，D），将值为D的新组件添加到队列Q的末尾（TQueue类型的记录Q是输入和输出参数，整数D是输入参数）。使用此过程，将给定序列的所有元素添加到给定队列的末尾。输出队列头部和尾部的新地址。
#include "pt4.h"
using namespace std;

// 定义队列结构类型
struct TQueue 
{
    PNode Head; // 队列头指针
    PNode Tail; // 队列尾指针
};

int Dequeue(TQueue &Q)
{
    // 保存待移除节点及其数据
    PNode oldHead = Q.Head;
    int value = oldHead->Data;

    // 更新队列头指针
    Q.Head = Q.Head->Next;
    
    // 处理队列变空的情况
    if (Q.Head == nullptr) 
        Q.Tail = nullptr;
    
    // 释放节点内存
    //delete oldHead;
    DeleteNode(oldHead);

    return value;
}

void Solve()
{
    Task("Dynamic27");
    PNode P1 = GetNode();
    PNode P2 = GetNode();
    TQueue Q = {P1, P2};

    for (int i = 0; i < 5; ++i)
        pt << Dequeue(Q);
    
    pt << Q.Head << Q.Tail;

}

