#include<iostream>
#include<math.h>
using namespace std;
float ga(float x)
{
    return 2*(log(x*x + 20) + x - 20)*(2*x/(x*x + 20) + 1);
}
float gb(float x)
{
    return 2*(exp(x) + 1)*(exp(x) + x - 20) + 2*x;
}
void GradientDescent(float x)
{
    float t = 0.5;
    if(ga(x) < 0) t = t*-1;
    float k = t*ga(x);
    while(abs(k) >= 0.001)
    {
        if(ga(x) < 0) t = t*-1;
        k = t*ga(x);
        x = x - k;
    }
    cout << "Gia tri x de f(x) cau a nho nhat la: " << x << endl;
    if(gb(x) < 0) t = t*-1;
    k = t*gb(x);
    while(abs(k) >= 0.001)
    {
        if(gb(x) < 0) t = t*-1;
        k = t*gb(x);
        x = x - k;
    }
    cout << "Gia tri x de f(x) cau b nho nhat la: " << x << endl;
}
main()
{
    float x = 10;
    GradientDescent(x);
}