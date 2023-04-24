#include <iostream>
using namespace std;

int main() 
{
    double a,r;
    int b;
    cin>>a;
    b = a / 1;
    r = a - b * 1.0;
    if(r < 0.5)
        cout<<b<<endl;
    else
     cout<<b + 1<<endl;;

    // float a;
    // cin>>a;
    // cout<<(int)(a + 0.5)<<endl;
    // return 0;
}