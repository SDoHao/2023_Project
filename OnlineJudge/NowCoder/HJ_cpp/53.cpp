#include <iostream>
using namespace std;

int main() 
{
    int n,r;
    cin>>n;
    if(n > 2)
    {
        r = n%4;
        if(r==0)
            cout<<3;
        if(r==1)
            cout<<2;
        if(r==2)
            cout<<4;
        if(r==3)
            cout<<2;      
    }
    else 
    {
        cout<<-1;
    }
    return 0;
}
