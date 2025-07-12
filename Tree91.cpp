#include "pt4.h"
using namespace std;
/*
Tree91. A pointer P1 to the root of a nonempty general tree and an integer
L (≥ 0) are given. Output the values of nodes of the level L and their amount 
N (nodes must be ordered from left to right). If nodes of the level L are absent 
then output 0.
Tree91.给出了一个指向非空一般树根的指针P1和一个整数L（≥0）。
输出级别L的节点值及其数量N（节点必须从左到右排序）。如果级别L的节点不存在，则输出0。
*/

#include <queue>
void OutputLevelL(PNode P1, int L)
{
    if (P1 == NULL)
    {
        pt << 0;
        return;
    }

    queue<pair<PNode, int>> q; // 使用队列进行广度优先搜索，队列中存储节点及其对应的层级
    q.push({P1, 0}); // 将根节点加入队列，初始层级为 0

    vector<int> levelNodes; // 用于存储第 L 层的节点值

    while (!q.empty())
    {
        PNode current = q.front().first; // 获取当前节点
        int currentLevel = q.front().second; // 获取当前层级
        q.pop(); // 移除队列中的当前节点

        if (currentLevel == L)
        {
            // 如果当前层级等于 L，将节点值加入 levelNodes
            levelNodes.push_back(current->Data);
        } 
        else if (currentLevel > L)
        {
            // 如果当前层级大于 L，说明已经遍历到第 L 层之后了，可以提前结束
            break;
        } 
        else
        {
            // 如果当前层级小于 L，继续遍历子节点
            PNode child = current->Left;
            while (child != NULL)
            {
                q.push({child, currentLevel + 1});
                child = child->Right;
            }
        }
    }

    // 输出结果
    if (levelNodes.empty())
    {
        pt << 0; // 如果没有找到第 L 层的节点，输出 0
    }
    else
    {
        for (int value : levelNodes)
        {
            pt << value; // 输出第 L 层的节点值
        }
        pt << levelNodes.size(); // 输出第 L 层的节点数量
    }
}

void Solve()
{
    Task("Tree91");
    PNode P1 = GetNode(); // 获取二叉树的根节点
    int L = 0;
    pt >> L; // 读取输入的层级 L

    OutputLevelL(P1, L); // 调用函数输出第 L 层的节点值及其数量
}
