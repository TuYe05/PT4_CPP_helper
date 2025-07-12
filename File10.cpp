#include "pt4.h"
using namespace std;

#include <fstream>
void Solve()
{
    Task("File10");
    string s1,s2;
    pt>>s1>>s2;
    ifstream f1(s1,ios::binary);
    ofstream f2(s2,ios::binary);

    f1.seekg(0,ios::end);
    int n=f1.tellg()/4;
    f1.seekg(0,ios::beg);
    ShowN(n);
    int arr[n];

    for(int i=1;i<=n;i++)
    {
        f1.read((char*)&arr[i-1],4);
    }

    for(int i=1;i<=n;i++)
    {
        f2.write((char*)&arr[n-i],4);
    }

    f1.close();
    f2.close();
}
