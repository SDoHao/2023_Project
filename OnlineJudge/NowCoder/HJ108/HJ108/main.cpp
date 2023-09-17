#include<iostream>
using namespace std;
int main()
{
	int a, b,t,i;
	while (cin >> a >> b)
	{
		if (a < b)
		{
			t = a;
			a = b;
			b = t;
		}
		i = 1;
		while(i <= b)
		{
			t = a * i;
			if (t % b == 0)
			{
				cout << t << endl;
				break;
			}
			i++;
		}
	}

	return 0;
}