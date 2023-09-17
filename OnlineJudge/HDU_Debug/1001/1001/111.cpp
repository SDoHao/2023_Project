#include "assert.h"
#include <iostream>

double operate(double num1, double num2, int op)
{
	assert(op >= 0 && op < 4);

	if (op == 0) {
		return num1 + num2;
	}
	else if (op == 1) {
		return num1 - num2;
	}
	else if (op == 2) {
		return num1 * num2;
	}
	else {
		return num1 / num2;
	}
}

int calculate(int num1, int num2, int num3, int num4)
{
	char operators[] = "+-*/";

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				double ret = operate(num1, num2, i);
				ret = operate(ret, num3, j);
				ret = operate(ret, num4, k);
				if (abs(ret - 24) < 0.001) {
					printf("((%d %c %d) %c %d) %c %d = %f\n", num1, operators[i],
						num2, operators[j],
						num3, operators[k],
						num4, ret);
				}

				ret = operate(num1, num2, i);
				double ret2 = operate(num3, num4, k);
				ret = operate(ret, ret2, j);
				if (abs(ret - 24) < 0.001) {
					printf("(%d %c %d) %c (%d %c %d) = %f\n", num1, operators[i],
						num2, operators[j],
						num3, operators[k],
						num4, ret);
				}

				ret = operate(num2, num3, j);
				ret = operate(num1, ret, i);
				ret = operate(ret, num4, k);
				if (abs(ret - 24) < 0.001) {
					printf("(%d %c (%d %c %d)) %c %d = %f\n", num1, operators[i],
						num2, operators[j],
						num3, operators[k],
						num4, ret);
				}

				ret = operate(num2, num3, j);
				ret = operate(ret, num4, k);
				ret = operate(num1, ret, i);
				if (abs(ret - 24) < 0.001) {
					printf("%d %c ((%d %c %d) %c %d) = %f\n", num1, operators[i],
						num2, operators[j],
						num3, operators[k],
						num4, ret);
				}

				ret = operate(num3, num4, k);
				ret = operate(num2, ret, j);
				ret = operate(num1, ret, i);
				if (abs(ret - 24) < 0.001) {
					printf("%d %c (%d %c (%d %c %d)) = %f\n", num1, operators[i],
						num2, operators[j],
						num3, operators[k],
						num4, ret);
				}
			}
		}
	}
	return 0;
}

int main(int argc, char* argv[])
{

	int nums[4] = { 0, 0, 0, 0 };
	std::cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];

	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
	{
		int num1 = nums[i];
		int ret = num1;

		for (int j = 0; j < sizeof(nums) / sizeof(nums[0]); j++)
		{
			if (j == i)
				continue;

			int num2 = nums[j];

			for (int k = 0; k < sizeof(nums) / sizeof(nums[0]); k++)
			{
				if (k == i || k == j)
					continue;

				int num3 = nums[k];

				for (int l = 0; l < sizeof(nums) / sizeof(nums[0]); l++)
				{
					if (l == i || l == j || l == k)
						continue;

					int num4 = nums[l];
					calculate(num1, num2, num3, num4);
				}
			}
		}
	}

	return 0;
}