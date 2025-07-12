#include "pt4.h"
using namespace std;
#include <fstream>


int YYYYMMDD(string s)
{
    int y=stol(s.substr(6,4)),m=stol(s.substr(3,2)),d=stol(s.substr(0,2));
    return y,m;
}
void Solve()
{
    Task("File68");
        
    string s,s1,s2;
    pt>>s>>s1>>s2;
    ifstream f(s,ios::binary);
    ofstream f1(s1,ios::binary);
    ofstream f2(s2,ios::binary);

    f.seekg(0,ios::end);
    int n=f.tellg()/80;
    f.seekg(0,ios::beg);

    int year[n],month[n],day[n];

    for(int i=0;i<n;i++)
    {
        char buf[80];
        f.read(buf,80);
        string s=buf;
        int y=stol(s.substr(6,4)),m=stol(s.substr(3,2)),d=stol(s.substr(0,2));
        year[i]=y;
        month[i]=m;
        day[i]=d;
    }

    for(int i=0;i<n;i++)
    {
        f2.write((char*)&year[n-1-i],4);
        f1.write((char*)&month[n-1-i],4);

    }

    

}
