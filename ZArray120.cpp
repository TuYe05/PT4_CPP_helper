// This task must be solved with vector<int>
// or vector<double> (not an array!)
#include <vector>
#include "pt4.h"
using namespace std;

void Solve()
{
    Task("ZArray120");
    int n,count;
    pt>>n;
    vector<int> a(n); 

    for (int i=0;i<n;i++)
        pt>>a[i];
    
    for(int i=a.size()-1;i>=0;i--)
    {
        if(a[i-1]==a[i])    
        {
            a.erase(a.begin()+i);
            n=n-1;
            break;
        }
        else
        {
            a.erase(a.begin()+i);
            n=n-1;
        }
    }
    
    count=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1]) 
            count++;
        if(a[i]!=a[i-1])
        {
            a.erase(a.begin()+i-1);
            i=i-1;
            count=1;
        }
    }

    Show(a.begin(),a.end());

    pt<<a;
}
