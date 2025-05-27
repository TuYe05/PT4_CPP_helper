#include "pt4.h"
using namespace std;

/**
 * 递归构建层级树，每个节点的数据域存储其所在层数
 * @param total_nodes 当前子树需要创建的节点总数
 * @param current_level 当前所在的层级
 * @return 构建好的子树根节点
 */
PNode BuildLevelTree(int total_nodes, int current_level) 
{
    // 递归终止条件：无节点需要创建
    if (total_nodes == 0) return nullptr;
    
    // 创建当前节点并设置层级数据
    PNode current_node = new Node;
    current_node->Data = current_level;
    
    // 递归终止条件：只剩当前节点需要创建（叶子节点）
    if (total_nodes == 1) {
        current_node->Left = current_node->Right = nullptr;
        return current_node;
    }

    // 计算子节点分配：当前节点占1个，剩余分配左右子树
    const int remaining_nodes = total_nodes - 1;
    const int right_subtree_nodes = remaining_nodes / 2;  // 较小的部分给右子树
    const int left_subtree_nodes = remaining_nodes - right_subtree_nodes; // 剩余给左子树
    
    // 递归构建左右子树（注意层级+1）
    current_node->Left = BuildLevelTree(left_subtree_nodes, current_level + 1);
    current_node->Right = BuildLevelTree(right_subtree_nodes, current_level + 1);
    
    return current_node;
}

void Solve()
{
    Task("Tree33");
    const int total_nodes = GetInt();
    pt << BuildLevelTree(total_nodes, 0);  // 从根节点（层级0）开始构建
}
