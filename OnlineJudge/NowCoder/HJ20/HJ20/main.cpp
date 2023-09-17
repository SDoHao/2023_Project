#include <iostream>
#include <string>
using namespace std;

int main()
{
	bool Ualp, Lalp, digit, other, isNotRepat;
	int count, n;
	string str;
	while (getline(cin, str))
	{
		n = str.size();
		if (str.size()<9)
			cout << "NG" << endl;
		else
		{
			Ualp = Lalp = digit = other = false;
			isNotRepat = true;
			count = 0;
			for (int i = 0; i < n; i++)
			{
				if ((str[i] >= 'A') && (str[i] <= 'Z'))
				{
					Ualp = true;
				}
				else if ((str[i] >= 'a') && (str[i] <= 'z'))
				{
					Lalp = true;
				}
				else if ((str[i] >= '0') && (str[i] <= '9'))
				{
					digit = true;
				}
				else
				{
					other = true;
				}
			}
			if (Ualp)
				count++;
			if (Lalp)
				count++;
			if (digit)
				count++;
			if (other)
				count++;
			if (count <= 2)
				cout << "NG" << endl;
			else
			{
				for (int i = 0; i <= n - 6; i++)
				{
					for (int j = i + 3; j <= n - 3; j++)
					{
						if ((str[i] == str[j]) && (str[i + 1] == str[j + 1]) && (str[i + 2] == str[j + 2]))
						{
							isNotRepat = false;
						}
					}
				}
				if (isNotRepat)
					cout << "OK" << endl;
				else
					cout << "NG" << endl;
			}
		}
	}
	return 0;
}