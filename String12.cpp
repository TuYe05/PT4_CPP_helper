#include "pt4.h"
using namespace std;

void Solve()
{
    Task("String12");
    string s;
    pt>>s;
    //s.size();
    int l=s.length(),n=GetInt();
    for(int i=0;i<l-1;i++)
            s.insert(1+i+i*n,n,'*');

    pt<<s;
    
}
