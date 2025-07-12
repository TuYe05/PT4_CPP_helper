#include "pt4.h"
using namespace std;

void SortDec3(double a, double b, double c)
{
    if (a<b) 
        swap(a,b);
    if (a<c) 
        swap(a,c);
    if (b<c) 
        swap(b,c);
    pt<<a<<b<<c;
}

void Solve()
{
    Task("ZFunc34");
    double a1,a2,b1,b2,c1,c2;
    pt>>a1>>b1>>c1>>a2>>b2>>c2;
    SortDec3(a1,b1,c1);
    SortDec3(a2,b2,c2);
}
