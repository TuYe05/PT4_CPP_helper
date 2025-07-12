// This task must be solved with vector<int>
// or vector<double> (not an array!)
#include <vector>
#include "pt4.h"
using namespace std;

void Solve()
{
    Task("ZArray104");
    int n,k,m;
    pt>>n;
    vector<double> a(n+10); 
    for (int i=0;i<n;i++)
        pt>>a[i];
    pt>>k>>m;

    for (int i=0;i<m;i++)
        a.insert(a.begin()+k,0);

    for (int i=0;i<n+m;i++)
        pt<<a[i];
}
