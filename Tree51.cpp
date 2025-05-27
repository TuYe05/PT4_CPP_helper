#include "pt4.h"
using namespace std;

int GetLevel(PNode node)
{
    int level = 0;
    while (node->Parent)
    {
        level++;
        node = node->Parent;
    }
    return level;
}

void Solve()
{
    Task("Tree51");
    PNode P1 = GetNode(), P2 = GetNode(), P3 = GetNode();
    pt << GetLevel(P1) << GetLevel(P2) << GetLevel(P3);
}
