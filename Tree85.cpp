#include "pt4.h"
using namespace std;

string BuildExpression(PNode node) {
    if (!node->Left && !node->Right) {
        return to_string(node->Data);
    }
    
    string left = BuildExpression(node->Left);
    string right = BuildExpression(node->Right);
    
    char op = (node->Data == -1) ? 'M' : 'm';
    return string(1, op) + "(" + left + "," + right + ")";
}

void Solve() {
    Task("Tree85");
    PNode root;
    pt >> root;
    
    pt << BuildExpression(root);
}
