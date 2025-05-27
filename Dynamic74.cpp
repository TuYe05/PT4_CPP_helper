#include "pt4.h"
using namespace std;

struct TListB
{
    PNode Barrier;
    PNode Current;
};

void LBInsertLast(TListB &L, int D)
{
    // 创建新节点并初始化数据
    PNode newNode=new Node;
    newNode->Data=D;
    
    // 获取当前尾节点（屏障的前驱）
    PNode lastNode = L.Barrier->Prev;
    
    // 建立新节点连接关系
    newNode->Prev = lastNode;
    newNode->Next = L.Barrier;
    
    // 更新相邻节点指针
    lastNode->Next = newNode;
    L.Barrier->Prev = newNode;
    
    // 设置新节点为当前节点
    L.Current = newNode;
}


void Solve()
{
    Task("Dynamic74");

}
