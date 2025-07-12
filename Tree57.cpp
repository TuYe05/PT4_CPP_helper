#include "pt4.h"
using namespace std;

/*
Tree57。给出指向非空树根的指针P1。如果树是搜索树，也就是说，它的节点值在树
遍历中形成一个非递减序列，然后输出NULL；否则，输出破坏搜索树属性的第一个节点（按顺序树遍历）的地址。

算法：
搜索树（二叉搜索树，Binary Search Tree，BST）: 完全符合 BST 规则：每个节点的左子树 ≤ 当前节点 ≤ 右子树。

例子1：符合 BST
        10
       /  \
      5    15
     / \    \
    3   7    20
   /   / \
  2   6   8

中序遍历：2 → 3 → 5 → 6 → 7 → 8 → 10 → 15 → 20

例子2：非法 BST
        5
       / \
      3   7
     / \
    2   6

中序遍历：2 → 3 → 6 → 5 → 7（6 > 5 破坏有序性）
第一个违规节点：5（因为 6 出现在其左侧）

*/

PNode RESULT = NULL, PREV = NULL; // 添加前驱指针

void check_search_tree(PNode P) // 从根节点开始，中序遍历
{
    if (!P || RESULT) return;
    
    check_search_tree(P->Left);    // 左子树
    
    if (PREV && P->Data < PREV->Data && !RESULT) // 检查顺序性
    { 
        RESULT = P;               // 记录第一个违规节点
        return;
    }
    PREV = P;                     // 更新前驱指针
    
    check_search_tree(P->Right);   // 右子树
}

void Solve()
{
    Task("Tree57");
    PNode P;
    pt >> P;          
    
    check_search_tree(P);

    pt << (RESULT); 
}
