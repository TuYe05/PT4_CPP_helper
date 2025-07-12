//    Dynamic2
#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Dynamic4");  // 声明任务名称

    int n = GetInt();  // 读取整数N
    PNode top = nullptr; // 初始化栈顶指针
    
    // 循环创建N个节点构建栈结构
    for (int i = 0; i < n; i++)
    {
        // 动态分配新节点内存
        PNode newNode = new Node;

        // 读取输入数据存入新节点
        newNode->Data = GetInt();

        // 新节点指向当前栈顶（链表头插法）
        newNode->Next = top;
        
        // 更新栈顶指针为新节点
        top = newNode;
    }

    // 输出栈顶指针（题目要求返回最后一个节点的地址）
    pt << top;
}
