#include "assert.h"
#include <iostream>
#include <cmath>
using namespace std;
//bool notyes;

double opf(double a, double b, int ops)
{
	switch (ops)
	{
	case 0:
		return a + b; break;
	case 1:
		return a - b; break;
	case 2:
		return a * b; break;
	case 3:
		return a / b; break;
	}
}

bool calculate(int num1, int num2, int num3, int num4)
{
	double r1, r2, r3;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				r1 = opf(num1, num2, i);
				r2 = opf(r1, num3, j);
				r3 = opf(r2, num4, k);
				if (abs(r3 - 24) < 0.001)
				{
					return true;
				}

				r1 = opf(num1, num2, i);
				r2 = opf(num3, num4, k);
				r3 = opf(r1, r2, j);
				if (abs(r3 - 24) < 0.001)
				{
					return true;
				}

				r1 = opf(num2, num3, j);
				r2 = opf(num1, r1, i);
				r3 = opf(r2, num4, k);
				if (abs(r3 - 24) < 0.001)
				{
					return true;
				}

				r1 = opf(num2, num3, j);
				r2 = opf(r1, num4, k);
				r3 = opf(num1, r2, i);
				if (abs(r3 - 24) < 0.001)
				{
					return true;
				}

				r1 = opf(num3, num4, k);
				r2 = opf(num2, r1, j);
				r3 = opf(num1, r2, i);
				if (abs(r3 - 24) < 0.001)
				{
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	int nums[4];
	bool flag;
	int n;
	cin >> n;
	while (n-->0)
	{
		flag = false;
		int num1, num2, num3, num4;
		std::cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];
		for (int i = 0; i < 4; i++)
		{
			num1 = nums[i];
			int ret = num1;

			for (int j = 0; j < 4; j++)
			{
				if (j == i)continue;
				num2 = nums[j];
				for (int k = 0; k < 4; k++)
				{
					if (k == i || k == j)continue;
					num3 = nums[k];
					for (int l = 0; l < 4; l++)
					{
						if (l == i || l == j || l == k)continue;
						num4 = nums[l];
						if (calculate(num1, num2, num3, num4))
						{
							flag = true;
							break;
						}
					}
				}
			}
		}
		if (flag)
			std::cout << "yes" << endl;
		else
			std::cout << "no" << endl;
	}

	return 0;
}