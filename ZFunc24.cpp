#include "pt4.h"
using namespace std;

#include <cmath>

void Mean(double a, double b)
{
    double amean, bmean;
    amean = (a+b)/2;
    bmean = sqrt(a*b);
    pt<<amean<<bmean;
}
void Solve()
{
    Task("ZFunc24");
    double a,b,c,d;
    pt>>a>>b>>c>>d;
    Mean(a,b);
    Mean(a,c);
    Mean(a,d);


}
