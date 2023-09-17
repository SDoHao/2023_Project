#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int i(0);
	int _temp;
	int dnum(0);
	cin >> str;
	while (i < str.size())
	{
		switch (str[i])
		{
		case('A') :
			_temp = 10;
			break;
		case('B') :
			_temp = 11;
			break;
		case('C') :
			_temp = 12;
			break;
		case('D') :
			_temp = 13;
			break;
		case('E') :
			_temp = 14;
			break;
		case('F') :
			_temp = 15;
			break;
		default:
			_temp = str[i] - '0';
			break;
		}
		dnum = dnum * 16 + _temp;
		i++;
	}
	cout << dnum << endl;
	return 0;
}
