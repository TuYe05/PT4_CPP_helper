// This task must be solved with vector<int>
// or vector<double> (not an array!)
#include <vector>
#include "pt4.h"
using namespace std;

void Solve()
{
    Task("ZArray86");
    int k;
    vector<double> a(GetInt()); 

    //push      plus element at end;
    //pop       minus element at end;
    //shift     plus element at begin;
    //unshift   minus element at begin;
    //insert(index,element)  exp. a.insert(a.begin(),0)
    //Show(a.begin(),a.end());  show vector a

    for (int i=0;i<(int)a.size();i++)
        //a.push_back(GetDouble());  same with next sentence
        pt>>a[i];

    pt>>k;
    
    
    

    for (int i=k;i<(int)a.size();i++)
        pt<<a[i];

    for (int i=0;i<k;i++)
        pt<<a[i];

    
}
