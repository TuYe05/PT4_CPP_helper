#include "pt4.h"
using namespace std;

#include <sstream>
#include <fstream>

void Solve()
{
    Task("Text9");
    int k;
    string name,str;
    pt>>k>>name;

    ifstream fin(name);
    stringstream buffer;
    buffer<<fin.rdbuf();
    str=buffer.str();

    int count=0;
    for(int i=0; i<(int)str.length(); i++)
    {
        if (str[i]=='\n')
            count++;
    }
    fin.close();

    if(k<=count)
    {
        int count1=0;
        for(int i=0; i<(int)str.length(); i++)
        {
            if (str[i]=='\n')
                count1++;
            if(count1==k-1)
            {
                str.insert(i,1,'\n');
                break;
            }
        }
        ofstream fout(name);
        fout<<str;
        fout.close();

    }
}
