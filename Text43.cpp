#include "pt4.h"
using namespace std;

#include<fstream>
#include<sstream>
#include<cmath>
#include <iomanip>
void Solve()
{
    Task("Text43");
    double a,b;
    int n;
    string name;
    pt>>a>>b>>n>>name;
    double h=(b-a)/n;
    ofstream fout(name);
    fout << fixed;
    for(int i=0;i<=n;i++)
    {
        double x=a+i*h;
        fout << setw(8) << setprecision(4) << x 
             << setw(12) << setprecision(8) << sin(x) 
             << setw(12) << setprecision(8) << cos(x) << endl;
    }

    fout.close();



}
