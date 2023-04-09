#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() 
{
    
    int i, n,alphabet,space,digit,other;
    string line;
    while(getline(cin,line))
    {
        i = alphabet = space = digit = other = 0;    
        n = line.size();
        for(;i<n;i++)
        {
            if(isalpha(line[i]))
            {
                alphabet++;
            }
            else if(line[i] == ' ')
            {
                space++;
            }
            else if(isdigit(line[i]))
            {
                digit++;
            }
            else 
            {
                other++;
            }
        }
        cout<<alphabet << endl << space << endl << digit << endl << other << endl;
    }
    return 0;
}