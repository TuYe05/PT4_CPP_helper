// This task must be solved with vector<vector<int>>
// or vector<vector<double>> (not an array!)
#include <vector>
#include "pt4.h"
using namespace std;

void Solve()
{
    Task("ZMatrix67");

    int m,n;
    pt>>m>>n;

    vector<vector<double>> a(m,vector<double>(n));
    

    for(auto &row :a)
        for(auto &element : row)
            pt>>element;

    vector<int> b(n);
    for(int j=0;j<n;j++)
        b[j]=0;

    for(int j=0;j<n;j++)
    {
        for(int i=0;i<m;i++)
            if(a[i][j]<0)b[j]=1;

    }        
        

    for(int i=0;i<m;i++)
    {
        {
            for(int j=0;j<n;j++)
                if(b[j]==1)pt<<a[i][j];
        }

    }       


 

}
