#include<iostream>
#include<math.h>
using namespace std;
// cau a:
float ga(float x)
{
    return 2*(log(x*x + 20) + x - 20)*(2*x/(x*x + 20) + 1);
}
float derivga(float x)
{
    return 2*((2*x/(x*x + 20) + 1)*(2*x/(x*x + 20) + 1) + (log(x*x + 20) + x - 20)*((40 - 2*x*x)/((x*x + 20)*(x*x + 20))));
}
// cau b:
float gb(float x)
{
    return 2*(exp(x) + 1)*(exp(x) + x - 20) + 2*x;
}
float derivgb(float x)
{
    return 2*((exp(x) + 1)*(exp(x) + 1) + exp(x)*(exp(x) + x - 20)) + 2;
}
// Newton Raphson
void newtonraphson(float x)
{
    float h = ga(x)/derivga(x);
    while((abs(h) >= 0.001))
    {
        h = ga(x)/derivga(x);
        x = x - h;
    }
    cout << "Gia tri x de f(x) cau a nho nhat la: " << x << endl;
    h = gb(x)/derivgb(x);
    while((abs(h) >= 0.001))
    {
        h = gb(x)/derivgb(x);
        x = x - h;
    }
    cout << "Gia tri x de f(x) cau b nho nhat la: " << x;
}
main()
{
    float x = 10;
    newtonraphson(x);
}