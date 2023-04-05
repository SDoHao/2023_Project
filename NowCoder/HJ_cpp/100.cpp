#include <iostream>
using namespace std;

int main()
{
	int n;
	int a1 = 2, an;
	int sum;
	while (cin >> n)
	{
		sum = 0;
		an = a1 + 3 * (n - 1);
		sum = (a1 + an)* n / 2;
		cout << sum << endl;
	}
	return 0;
}
