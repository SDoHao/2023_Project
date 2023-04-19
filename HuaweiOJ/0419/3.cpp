#include<iostream>
#include<vector>

int left, right, min_l, min_r, mid, min_l_t, min_r_t;
bool isleft;

void count(int i, std::vector<int>& data)
{
	if (i >= 2)
	{
		isleft = false;
		int t = i,n = data.size();
		int temp = data[i];
		while (t < n)
		{
			if (data[t] < temp)
				break;
			if (data[t] > data[i - 2])
			{
				isleft = true;
				right--;
				//min_r_t = data[right];
				break;
			}
			t++;
		}
	}
	int sum = 0;
	min_l_t > min_l ? min_l : min_l_t;
	min_r_t > min_r ? min_r : min_r_t;
	if (i == data.size() - 1) 
		i +=0;
	int sub = min_l_t > min_r_t ? min_r_t : min_l_t;
	for (int j = left; j <= right; j++)
		sum += data[j];
	sum -= (right - left + 1) * sub;
	std::cout << sum << ' ';
}

int main()
{
	std::vector<int> data;
	int a,n,i = 0,sign;
	//int t = 11;
	while (std::cin >> a)
		data.push_back(a);
	//while (t-- >= 0)
	//{
	//	std::cin >> a;
	//	data.push_back(a);
	//}
	n = data.size();
	min_l = data[0];
	min_r = data[n - 1];
	min_l_t = min_l;
	min_r_t = min_r;
	sign = 0;
	right = n;
	while(i < n)
	{
		if (sign == 0)// ÕÒ×ó¶Ëµã
		{
			if (data[i] <= min_l_t)
				left = i;
			else
			{
				//->°¼²Û
				sign = 1;
				mid = data[i];
				right = i;
			}
		}
		else if (sign == 1)//->°¼²Û
		{
			if (data[i] >= mid)
			{
				mid = data[i];
				right = i;
			}
			else// ->ÓÒ¶Ëµã
			{
				sign = 2;
				right = i;
				min_r_t = data[right];
				if(i == n - 1)//Ä©Î²
					count(i, data);
			}
		}
		else if (sign == 2)
		{
			if (data[i] <= data[right])//->ÓÒ¶Ëµã
				right = i;
			else
			{
				count(i, data);
				sign = 1;
				if(i < n)
					mid = data[i];
				if (isleft)
				{
					min_l_t = data[i - 1];
					left = i - 1;
				}
				else
				{
					min_l_t = data[i];
					left = i;
				}
			}
		}
		i++;
	}
	return 0;
}