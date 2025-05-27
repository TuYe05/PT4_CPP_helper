#include "pt4.h"
#include<fstream>
using namespace std;

ofstream f;
string s;
int n,k;

void step(int n0, int k0)
{
    s+=k0+'0';
    if(n0==n)
    {
        f<<s<<"\n";
    }
    else
    {
        for(int i=1;i<=k;i++)
        {
            step(n0+1,i);
        }
    }
    s.pop_back();
}
void Solve()
{
    Task("Recur25");
    string fname;
    pt>>n>>k>>fname;
    f.open(fname);
    step(0,0);


    f.close();


}

