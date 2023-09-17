#include<iostream>
#include<cmath>
using namespace std;

bool notyes;

double opf(int ops, double a, double b)
{
	switch (ops)
	{
	case 1:
		return a + b; break;
	case 2:
		return a - b; break;
	case 3:
		return a * b; break;
	case 4:
		return a / b; break;
	}
}

void calculate(double val[])
{
	notyes = true;
	double r1, r2, r3;
	for (int j = 1; j <= 4 ; j++)
	{
		for (int k = 1; k <= 4; k++)
		{
			for (int u = 1; u <= 4; u++)
			{
					//((a#b)#c)#d
					r1 = opf(j, val[0], val[1]);
					r2 = opf(k, r1, val[2]);
					r3 = opf(u, r2, val[3]);
					if (r3 == 24)
						//if(abs(r3 - 24) < 0.000001)
					{
						//std::cout<<"yes"<<endl;
						notyes = false;
						break;
					}
					//(a#(b#c))#d
					r1 = opf(j, val[1], val[2]);
					r2 = opf(k, val[0], r1);
					r3 = opf(u, r2, val[3]);
					if (r3 == 24)
						//if(abs(r3 - 24) < 0.000001)
					{
						//std::cout<<"yes"<<endl;
						notyes = false;
						break;
					}
					//a#((b#c)#d)
					r1 = opf(j, val[1], val[2]);
					r2 = opf(k, r1, val[3]);
					r3 = opf(u, val[0], r2);
					if (r3 == 24)
						//if(abs(r3 - 24) < 0.000001)
					{
						//std::cout<<"yes"<<endl;
						notyes = false;
						break;
					}
					//(a#b)#(c#d)
					r1 = opf(j, val[0], val[1]);
					r2 = opf(k, val[2], val[3]);
					r3 = opf(u, r1, r2);
					if (r3 == 24)
						//if(abs(r3 - 24) < 0.000001)
					{
						//std::cout<<"yes"<<endl;
						notyes = false;
						break;
					}
					//a#(b#(c#d))
					r1 = opf(j, val[2], val[3]);
					r2 = opf(k, val[1], r1);
					r3 = opf(u, val[0], r2);
					if (r3 == 24)
						//if(abs(r3 - 24) < 0.000001)
					{
						//std::cout<<"yes"<<endl;
						notyes = false;
						break;
					}
			}
		}
	}
}

int main()
{
	int n;
	double val[4]{ 0 };
	double val1[4]{ 0 };

	cin >> n;
	while (n-->0)
	{
		cin >> val[0] >> val[1] >> val[2] >> val[3];
		notyes = true;

		for (int i = 0; i < 4; i++)
		{
			val1[0] = val[i];
			for (int j = 0; j < 4; j++)
			{
				if (j == i)
					continue;
				val1[1] = val[j];
				for (int k = 0; k < 4; k++)
				{
					if (k == i || k == j)
						continue;
					val1[2] = val[k];
					for (int l = 0; l < 4; l++)
					{
						if (l == i || l == j || l == k)
							continue;
						val1[3] = val[l];
						calculate(val1);
					}
				}
			}
		}
		if (notyes)
			std::cout << "no" << endl;
		else
			std::cout << "yes" << endl;
	}

	return 0;
}