#include "pt4.h"
using namespace std;
string result="";

string BuildExpression(PNode node)
{
    if(node->Data>=0 && node->Data<=9)
        return to_string(node->Data);
    if(node->Data == -1)
        return "("+BuildExpression(node->Left)+"+"+BuildExpression(node->Right)+")";
    if(node->Data == -2)
        return "("+BuildExpression(node->Left)+"-"+BuildExpression(node->Right)+")";
    if(node->Data == -3)
        return "("+BuildExpression(node->Left)+"*"+BuildExpression(node->Right)+")";

}

void Solve() {
    Task("Tree80");
    PNode P1;
    pt >> P1;
    result = BuildExpression(P1);
    pt << result;
}
