#include "pt4.h"
using namespace std;

// 递归求值函数
int evaluate(PNode node) {
    // 叶子节点直接返回值
    if (!node->Left && !node->Right)
        return node->Data;
    
    // 递归计算子树
    int leftVal = evaluate(node->Left);
    int rightVal = evaluate(node->Right);
    
    // 根据节点类型处理操作
    switch (node->Data) {
        case -1: return max(leftVal, rightVal); // M函数取最大值
        case -2: return min(leftVal, rightVal); // m函数取最小值
        default: return 0; // 无效节点（题目保证输入合法）
    }
}

void Solve() {
    Task("Tree84");
    PNode P1;
    pt >> P1;   // 读取输入树根节点
    
    int result = evaluate(P1);
    pt << result;
}
