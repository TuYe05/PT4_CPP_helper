#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Dynamic2");
    auto p1 = GetNode(); // 从平台获取链表头节点指针（自动类型推导）
    PNode p2;           // 声明辅助指针用于记录前一个节点
    int count = 0;      // 节点计数器初始化

    // 遍历链表的循环结构
    while (p1 != nullptr)  // 当当前节点不为空时继续循环
    {
        count++;             // 增加节点计数
        pt << p1->Data;      // 向平台输出当前节点的Data值
        p2 = p1;            // 保存当前节点指针（此时p2总是指向当前节点）
        p1 = p1->Next;      // 移动指针到下一个节点
    }

    // 最终输出结果：总节点数和链表尾节点的地址
    pt << count   // 输出链表总长度
       << p2;     // 输出链表尾节点指针（循环结束后p2指向最后一个节点）
}