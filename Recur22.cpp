#include "pt4.h"
using namespace std;
#include <string>

int insfind(string s,char m)
{
    int count=0;
    for(int i=0;i<(int)s.length();i++)
            count++;
    return count;
}
char Mstringtonum(string str)
{
    int num=0;
    for(int i=0;i<(int)str.length();i++)
    {
        if(str[i]>='0' && str[i]<='9' && (int)str[i]>num) num=(int)(str[i]);
    }
    return (char)num;
}
char mstringtonum(string str)
{
    int num=10;
    for (char ch : str) 
        if (ch >= '0' && ch <= '9' && ch - '0' < num) num = ch - '0';
    
    ShowN(num);
    return (num == 10) ? '0' : (num+'0'); 
}

int oppofind(string s)
{
    int count=0;
    for(int i=(int)s.length();i>=0;i--)
    {
        if(s[i]==')'){count++;}
        if(count==2){return i;}
    }
    return -1;
}

string cauculate(string str)
{ 
    ShowS(str);
    if((int)str.find('M',0)==-1 && (int)str.find('m',0)==-1) return str;
    string ssss="";
    int end=oppofind(str);
    ShowN(end);
    if(end==-1 && str[0]=='M') return ssss+Mstringtonum(str);
    if(end==-1 && str[0]=='m') return ssss+mstringtonum(str);
    
    int start=0;

    if(str.find('m')<str.find('M'))
    start=str.find('(',str.find('m')+2);
    else
    start=str.find('(',str.find('M')+2);

    
    ShowS(str.substr(0,start-1));
    ShowS(str.substr(start-1,end-start+2));
    ShowS(str.substr(end+1,str.length()-end-1)); 

    return cauculate(str.substr(0,start-1)+cauculate(str.substr(start-1,end-start+2))+str.substr(end+1,str.length()-end-1));
}

void Solve()
{
    Task("Recur22");
    string s;
    pt>>s;
    int result=stoi(cauculate(s));
    ShowN(result);
    pt<<result;

}

