#include "pt4.h"
#include <fstream>
using namespace std;
int N;
ofstream fout;

void Generate(string path, int level, int sum)
{
    if (sum > 0) return; 
    if (level == N)
    {
    if(sum == 0) 
        fout << path << '\n';
        return;
    }

    Generate(path + "A", level + 1, sum + 1); 
    Generate(path + "B", level + 1, sum);
    Generate(path + "C", level + 1, sum - 1); 
}
void Solve()
{
    Task("Recur29");
    string filename;
    pt >> N >> filename;
    fout.open(filename);
    Generate("D", 0, 0);
    fout.close();
}
