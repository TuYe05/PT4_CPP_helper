#include "pt4.h"
using namespace std;

void Solve()
{
    Task("String28");
    char c;
    pt>>c;
    string s;
    pt>>s;
    for(int i=0;i<(int)s.length();i++)
    {
        if(s[i]==c)
        {
            s.insert(i,1,c);
            i++;
        }

    }
    pt<<s;

}
