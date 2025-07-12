// This task must be solved with vector<int>
// or vector<double> (not an array!)
#include <vector>
#include "pt4.h"
using namespace std;

void Solve()
{
    Task("ZArray93");
    int n;
    pt>>n;
    vector<int> a(n); 
    for (int i=0;i<n;i++)
        pt>>a[i];
    for (int i=0;i<n;i+=2)
        pt<<a[i];
     

}
