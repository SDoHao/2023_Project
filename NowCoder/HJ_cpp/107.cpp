#include <iostream>
using namespace std;

int main() 
{

    double l,r,mid;
    double n;
    while (cin >> n) 
    { 
        l = -20,r = 20;
        while(r - l > 1e-3)
        {
            mid = (l + r) / 2;
            if(mid * mid * mid > n)
                r = mid;
            else
                l = mid;
        }
        printf("%.1f",l);
    }
    return 0;
}
