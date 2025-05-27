// This task must be solved with vector<vector<int>>
// or vector<vector<double>> (not an array!)
#include <vector>
#include "pt4.h"
using namespace std;

void Solve()
{
    Task("ZMatrix16");
    int m;
    pt>>m;
    vector<vector<double>> a(m,vector<double>(m));
    for(auto &row :a)
        for(auto &element : row)
            pt>>element;

    int r=0,count=0,ele=m*m;
    while(true)
    {
        for(int i=0+r;i<m-r;i++)
        {
            pt<<a[i][r];
            count++;
            if(count==ele)break;
        }
        if(count==ele)break;

        for(int i=0+r+1;i<m-r-1;i++)
        {
            pt<<a[m-r-1][i];
            count++;
            if(count==ele)break;
        }
        if(count==ele)break;

        for(int i=m-r-1;i>=0+r;i--)
        {
            pt<<a[i][m-r-1];
            count++;
            if(count==ele)break;
        }
        if(count==ele)break;

        for(int i=m-r-2;i>=0+r+1;i--)
        {
            pt<<a[0+r][i];
            count++;
            if(count==ele)break;
        }
        if(count==ele)break;
        
        r++;
    }
    

}
