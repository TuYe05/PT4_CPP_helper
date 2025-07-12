#include "pt4.h"
using namespace std;

void Solve()
{
    Task("String32");
    string s,s0;
    pt>>s>>s0;
    size_t pos=s.find(s0);
    int count=0;

    while(pos!=s.npos)
    {
        pos=s.find(s0,pos+1);
        count++;
    }

    pt<<count;
}
