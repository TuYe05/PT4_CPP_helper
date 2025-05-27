#include "pt4.h"
using namespace std;

struct TListB {
    PNode Barrier;  // 哨兵节点
    PNode Current;  // 当前有效节点
};

TListB LBInsertBefore(TListB &L, int D) {
    PNode newNode = new Node;
    newNode->Data = D;

    // 插入到当前节点前
    newNode->Next = L.Current;
    newNode->Prev = L.Current->Prev;
    
    // 更新相邻节点指针
    L.Current->Prev->Next = newNode;
    L.Current->Prev = newNode;
    
    // 设置新节点为当前节点
    L.Current = newNode;
    
    return L;
}

void Solve() {
    Task("Dynamic76");
    
    // 获取初始链表配置
    PNode barrier = GetNode();
    PNode current = GetNode();
    TListB list = {barrier, current};
    
    // 插入5个整数
    for(int i = 0; i < 5; i++) {
        int value = GetInt();
        list = LBInsertBefore(list, value);
    }
    
    // 输出当前节点地址
    pt << list.Current;
}
