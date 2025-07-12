#include "pt4.h"
using namespace std;

#include <sstream>
#include <fstream>

void Solve()
{
    Task("Text6");
    string s1,s2;
    pt>>s1>>s2;
    ofstream fout(s1, ios::app);    // 以追加模式打开第一个文件
    ifstream fin(s2);
    fout<<fin.rdbuf();    // 将文件f1的内容，输出到f2
    
    


}
