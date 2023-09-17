#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string str1,str2;
    int n;
    cin>>str1;
    cin>>n;
    str2 = str1.substr(0,n);
    cout<<str2<<endl;
    return 0;
}