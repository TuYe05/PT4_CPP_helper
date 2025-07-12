

//File55. A string S0, an integer N (≤ 4), and N files of integers called S1, …, SN are given. Create a new file called S0; this file (an archival file) must contain data of all given files in the following format: the amount of components of the file S1 and values of all its components in the same order; the amount of components of the file S2 and values of all its components in the same order; …; the amount of components of the file SN and values of all its components in the same order.
//File57. Two strings S1, S2 and an archival file are given. The archival file contains data of several files; the format of archival file is described in File55. Create two new files called S1, S2; the first resulting file must contain first components of all files, which are contained in the archival file, the second resulting file must contain last components of all files, which are contained in the archival file.

#include "pt4.h"
using namespace std;
#include <fstream>

void Solve()
{
    Task("File57");
    string s,s1,s2;
    pt>>s1>>s2>>s;
    ifstream f(s,ios::binary);
    ofstream f1(s1,ios::binary);
    ofstream f2(s2,ios::binary);

    while(!f.eof())
    {
        int n=0,x=0;
        f.read((char*)&n,4);
        if(n==0)
            break;
   

        f.read((char*)&x,4);
        f1.write((char*)&x,4);

        for(int i=1;i<n-1;i++)
            f.read((char*)&x,4);

        f.read((char*)&x,4);
        f2.write((char*)&x,4);

    

    }

    f.close();
    f1.close();
    f2.close();
}
