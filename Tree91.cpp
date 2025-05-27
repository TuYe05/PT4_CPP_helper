#include "pt4.h"
using namespace std;

void OutputLevelL(PNode P1, int L) {
    if (!P1) {
        pt << 0;
        return;
    }

    vector<PNode> currentLevel;  // 当前层节点集合
    currentLevel.push_back(P1);
    int currentDepth = 0;        // 当前遍历深度

    // 逐层遍历直到目标层
    while (currentDepth < L && !currentLevel.empty()) {
        vector<PNode> nextLevel;
        
        // 收集当前层所有节点的子节点
        for (auto node : currentLevel) {
            PNode child = node->Left;
            while (child) {
                nextLevel.push_back(child);
                child = child->Right;
            }
        }
        
        currentLevel = nextLevel;
        currentDepth++;
    }

    // 处理结果输出
    if (currentDepth == L && !currentLevel.empty()) {
        for (auto node : currentLevel) {
            pt << node->Data;
        }
        pt << currentLevel.size();
    } else {
        pt << 0;
    }
}

void Solve() {
    Task("Tree91");
    PNode P1 = GetNode();
    int L;
    pt >> L;
    OutputLevelL(P1, L);
}
