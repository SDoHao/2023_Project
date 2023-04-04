#include <iostream>
using namespace std;

int main() 
{
    int n;
    int total;
    while(cin >> n) 
    { 
        if(n)
        {
            total = 0;
            while(n > 2)
            {
                n = n - 3 + 1;
                total +=1;
            }
            if(n==2)
                total +=1; 
            cout<<total<<endl;        
        }
        else 
            break;
    }
}
