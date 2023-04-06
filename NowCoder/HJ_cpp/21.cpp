#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s;
    int i,n;
    while(cin>>s)
    {
        i = 0;
        n = s.size();
        for(i = 0;i < n;i++)
        {
            if(islower(s[i]))
            {
                switch(s[i])
                {
                    case 'a':;case 'b':;case 'c':
                        s[i] = '2';
                    break;
                    case 'd':;case 'e':;case 'f':
                        s[i] = '3';
                    break;
                    case 'g':;case 'h':;case 'i':
                        s[i] = '4';
                    break;
                    case 'j':;case 'k':;case 'l':
                        s[i] = '5';
                    break;
                    case 'm':;case 'n':;case 'o':
                        s[i] = '6';
                    break;
                    case 'p':;case 'q':;case 'r':;case 's':
                        s[i] = '7';
                    break;
                    case 't':;case 'u':;case 'v':
                        s[i] = '8';
                    break;
                    case 'w':;case 'x':;case 'y':;case 'z':
                        s[i] = '9';
                    break;
                }
            } 
            else if(isupper(s[i]))
            {
                if( s[i]=='Z')
                    s[i] = 'a';
                else
                  s[i] = tolower(s[i]) + 1;
            }
        }
        cout<<s<<endl;
    }
    return 0;  
}