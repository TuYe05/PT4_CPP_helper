#include "pt4.h"
using namespace std;

// 递归构建树结构（先序填充）
PNode BuildDepthTree(int L, int& valueIndex, vector<int>& values, int currentDepth) {
    // 终止条件：超过可用值或达到最大深度
    if (valueIndex >= values.size() || currentDepth > L) 
        return nullptr;

    // 创建当前节点
    PNode node = new Node;
    node->Data = values[valueIndex++];
    
    // 递归构建子树（先左后右）
    if (currentDepth < L) {
        node->Left = BuildDepthTree(L, valueIndex, values, currentDepth + 1);
        node->Right = BuildDepthTree(L, valueIndex, values, currentDepth + 1);
    } else {  // 叶子节点不创建子树
        node->Left = node->Right = nullptr;
    }
    return node;
}

void Solve() 
{
    Task("Tree31");
    
    // 读取输入参数
    int L = GetInt();    // 目标深度
    int N = GetInt();    // 元素总数
    vector<int> values;  // 存储输入序列
    
    // 读取N个元素到容器
    for (int i = 0; i < N; ++i)
        values.push_back(GetInt());

    // 构建深度为L的树
    int index = 0;  // 当前元素索引
    PNode root = BuildDepthTree(L, index, values, 0);
    
    // 输出根节点地址
    pt << root;
}
