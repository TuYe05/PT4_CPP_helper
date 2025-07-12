#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Dynamic17");
    PNode newNode = new Node;
    newNode->Data = GetInt();
    newNode->Next = nullptr;

    auto p1 = GetNode();
    auto p2 = GetNode();

    if (p1 == nullptr)
    {
        newNode->Prev = nullptr;
        p1 = newNode;
        p2 = newNode;
    }
    else
    {
        p2->Next = newNode;
        p2 = newNode;
    }

    pt << p1 << p2;



}
