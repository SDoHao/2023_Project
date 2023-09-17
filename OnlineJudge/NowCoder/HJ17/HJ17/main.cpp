#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int i, n;
	int flag;
	int num;
	int x, y;
	while (cin >> str)
	{
		x = y = flag = i = 0;
		n = str.size();
		char dir;
		while (i < n)
		{
			//取方向
			if (flag == 0)
			{
				if (str[i] == 'A' || str[i] == 'W' || str[i] == 'S' || str[i] == 'D')
				{
					dir = str[i];
					flag = 1;
					i++;
				}
				else
				{
					flag = 2;
				}
			}
			//取数字
			else if (flag == 1)
			{
				num = 0;
				if (str[i] <= '9' && str[i] >= '0')
				{
					num = str[i] - '0';
					i++;
					if (str[i] <= '9' && str[i] >= '0')
					{
						num = num * 10 + str[i] - '0';
						i++;
					}
					else if (str[i] != ';')
						flag = 2;
				}
				else
					flag = 2;
				if (flag == 1)
				{
					switch (dir)
					{
					case('W') :
						y += num;
						break;
					case('S') :
						y -= num;
						break;
					case('A') :
						x -= num;
						break;
					case('D') :
						x += num;
						break;
					}
				}

			}
			//取分隔符
			else if (flag == 2)
			{
				i++;
			}
			if (str[i] == ';')
			{
				flag = 0;
				i++;
			}
		}
		cout << x << ',' << y << endl;
	}
	return 0;
}