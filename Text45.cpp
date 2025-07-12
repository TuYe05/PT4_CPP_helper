#include "pt4.h"
using namespace std;

#include<fstream>
#include<sstream>

bool infd(string s)
{
    for(int i=0;i<(int)s.length();i++)
    {
        if(s[i]=='.')
            return true;
    }
    return false;
}
void Solve()
{
    Task("Text45");
    string name;
    pt>>name;
    ifstream f(name);
    string line;
    int count=0;
    double sum=0;
    while(getline(f,line))
    {
        string str=line;
        stringstream ss(str);
        if(infd(line))
        {
            double num=stod(line);
            sum+=num;
            count++;
        }
    }
    pt<<count<<sum;
}
