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
void GradientDescentMomentum(float x)
{
    float xp = x;
    float k = 0.4*ga(x) - 0.6*(x-xp);
    while(abs(k) >= 0.001)
    {
        xp = x;
        k = 0.4*ga(x) - 0.6*(x-xp);
        x = x - k;
    }
    cout << "Gia tri x de f(x) cau a nho nhat la: " << x << endl;
    k = 0.1*gb(x) - 0.9*(x-xp);
    while(abs(k) >= 0.001)
    {
        xp = x;
        k = 0.1*gb(x) - 0.9*(x-xp);
        x = x - k;
    }
    cout << "Gia tri x de f(x) cau b nho nhat la: " << x << endl;
}
main()
{
    float x = 10;
    GradientDescentMomentum(x);
}