#include "pt4.h"
using namespace std;
#include <fstream>
#include <string>

void Solve() {
    Task("File67");
    
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
        
        f1.write((char*)&day[i],4);
        f2.write((char*)&month[i],4);

    }

}
