#include "pt4.h"
using namespace std;

string tree_to_str(PNode current)
{

    if (!current)
        return "";
    return std::to_string(current->Data)+"("+tree_to_str(current->Left)+","+tree_to_str(current->Right)+")";  
}


void Solve()
{
    Task("Tree73");
    PNode root = GetNode();
    pt<<tree_to_str(root);

}
