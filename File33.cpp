#include "pt4.h"
using namespace std;

#include <fstream>
void Solve()
{
    Task("File33");
    string name1,name2="$$.tmp";
    pt>>name1;
    ifstream f1(name1,ios::binary);
    ofstream f2(name2,ios::binary);
    f1.seekg(0,ios::end);
    int n=f1.tellg()/4;
    
    f1.seekg(0,ios::beg);
    ShowN(n);

    for(int i=1;i<=n;i++)
    {
        int x;
        f1.read((char*)&x,sizeof(int));
        if(i%2==1)
            f2.write((char*)&x,sizeof(int));
    }
    f1.close();
    f2.close();
    remove(name1.c_str());
    rename(name2.c_str(),name1.c_str());
}
