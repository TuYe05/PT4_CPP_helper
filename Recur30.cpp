#include "pt4.h"
#include <fstream>
using namespace std;

int N;
ofstream fout;

void Generate(string path, int level, int sum, char lastChar) 
{
    if (level == N)
    {
        if (sum == 0)
            fout << path << '\n';
        return;
    }
    
    // 根据前一个字符决定可选的子节点
    if (lastChar != 'A')
        Generate(path + "A", level + 1, sum + 1, 'A');
    
    if (lastChar != 'B')
        Generate(path + "B", level + 1, sum, 'B');
    
    if (lastChar != 'C')
        Generate(path + "C", level + 1, sum - 1, 'C');
}

void Solve()
{
    Task("Recur30");
    string filename;
    pt >> N >> filename;
    fout.open(filename);
    Generate("D", 0, 0, 'D'); // 初始节点D作为根的特殊标记
    fout.close();
}
