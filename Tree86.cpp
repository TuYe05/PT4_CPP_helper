#include "pt4.h"
using namespace std;

// 定义函数 CreateNode，将二叉树转换为一般的树
PNode CreateNode(PNode p)
{
    // 如果源节点为空，则返回 NULL
    if (p == NULL)
        return NULL;

    // 创建新的节点用于一般的树
    PNode p0 = new TNode;
    // 复制源节点的数据到新节点
    p0->Data = p->Data;
    // 新节点的 Right 字段设置为 NULL，因为新节点还没有右兄弟
    p0->Right = NULL;

    // 重新定义指向源节点的子节点的指针
    PNode p1 = p->Left,  // p1 指向源节点的左子节点
          p2 = p->Right; // p2 指向源节点的右子节点

    // 如果左子节点为空，则将右子节点设为第一个子节点
    if (p1 == NULL)
    {
        p1 = p2; // 现在 p1 指向源节点的右子节点
        p2 = NULL; // p2 设置为 NULL，因为源节点只有一个子节点
    }

    // 形成新节点的子节点列表
    p0->Left = CreateNode(p1); // 递归创建新节点的第一个子节点（左子节点），并将其连接到新节点的 Left 字段
    if (p1 != NULL) // 如果源节点至少有一个子节点
        p0->Left->Right = CreateNode(p2); // 递归创建新节点的第二个子节点（右子节点），并将其作为第一个子节点的右兄弟连接到 Right 字段

    // 返回指向新节点的指针，该节点现在是一般树的子树的根节点
    return p0;
}

// 定义函数 Solve，调用 CreateNode 并输出结果
void Solve()
{
    // 指定任务名称
    Task("Tree86");
    // 获取二叉树的根节点，并调用 CreateNode 函数将其转换为一般树
    // 将结果（指向一般树根节点的指针）通过 pt 输出
    pt << CreateNode(GetNode());
}
