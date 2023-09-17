#include <iostream>
using namespace std;

int main() 
{
    int n;
    int line = 1;
    int add = 2,add_t;
    int val = 1,val_t,val_p = 1;
    cin >> n;
    add_t = add;
    val_t = val;
    for(int i = 0;i < n;i++)
    {  
        for(int j = 0;j < n - line + 1 ;j++)
        {
            cout<< val_t <<' ';
            val_t += add_t;
            add_t++;
        }
        cout << endl;
        add_t = ++add;
        val += (val_p++);
        val_t = val;
        line++; 
    }
    return 0;
}