#include "pt4.h"
#include <list>
using namespace std;

// 题目：删除二叉树中的叶子节点

struct leaf_parent
{
    PNode leaf; // 队列头指针
    PNode parent; // 队列尾指针
};

list<leaf_parent> leaf_parent_list; // 存储待删除的叶子节点及其父节点

int check_leaf(PNode node) // 从根节点开始，中序遍历
{
    if (!node) return 0;
    if (!node->Left && !node->Right)
        return 1; // 叶子节点
    else 
        return 0;
}

void RemoveLeaves(PNode node, PNode parent)
{
    if (!node) return;

    RemoveLeaves(node->Left, node);
    RemoveLeaves(node->Right, node);

    // 判断当前节点是否为叶子节点
    if (!node->Left && !node->Right)
    {
        leaf_parent_list.push_back({ node, parent }); // 加入待删除的叶子节点及其父节点队列
    }
}

void Solve() {
    Task("Tree41");
    PNode root = GetNode() ,par ,lea;
    if (!root) return;
    RemoveLeaves(root, nullptr); // 遍历树，将叶子节点及其父节点加入待删除的队列   

    while(!leaf_parent_list.empty())
    {
        par = leaf_parent_list.front().parent;
        lea = leaf_parent_list.front().leaf;

        if(par->Left == lea)
            par->Left = nullptr;
        else
            par->Right = nullptr;

        DeleteNode(lea);
        leaf_parent_list.pop_front();
    }


}
