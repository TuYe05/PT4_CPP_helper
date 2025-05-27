#include "pt4.h"
using namespace std;

// 定义队列结构类型
struct TQueue 
{
    PNode Head; // 队列头指针
    PNode Tail; // 队列尾指针
};

// 入队操作函数
void Enqueue(TQueue &Q, int D)
{
    // 创建新节点并初始化数据
    PNode newNode = new Node;
    newNode->Data = D;
    newNode->Next = nullptr;

    if (Q.Head == nullptr) {
        // 空队列时设置头和尾都指向新节点
        Q.Head = newNode;
        Q.Tail = newNode;
    } else {
        // 非空队列时将新节点链接到队尾
        Q.Tail->Next = newNode;
        Q.Tail = newNode; // 更新尾指针
    }
}

void Solve()
{
    Task("Dynamic26");
    PNode P1 = GetNode(); // 获取原始队列头指针
    PNode P2 = GetNode(); // 获取原始队列尾指针
    
    // 初始化队列结构
    TQueue Q;
    Q.Head = P1;
    Q.Tail = P2;
    //TQueue Q = {P1, P2};

    int N = GetInt();  // 获取整数N
    // 逐个添加序列元素到队列
    for (int i = 0; i < N; ++i) {
        int D = GetInt(); // 读取序列元素
        Enqueue(Q, D);    // 执行入队操作
    }
    
    // 输出更新后的队列头尾地址
    pt << Q.Head << Q.Tail;

}
