// This task must be solved with vector<vector<int>>
// or vector<vector<double>> (not an array!)
#include <vector>
#include "pt4.h"
using namespace std;



void Solve()
{
    Task("ZMatrix14");
    int m;
    pt>>m;
    vector<vector<double>> a(m,vector<double>(m));
    for(auto &row :a)
        for(auto &element : row)
            pt>>element;


    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m-i;j++)
            //pt<<a[j][i];
        for(int j=i+1;j<m;j++)
            //pt<<a[m-i-1][j];
    }        
    
}
