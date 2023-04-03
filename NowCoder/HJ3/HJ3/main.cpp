#include <iostream>
#include <vector>
using namespace std;


int cmp(const void *p1,const void *p2)
{
	return *((int*)p1) - *(int*)p2;
}

int main() 
{
	bool flag;
	int n,i = 0,_temp;	
	vector<int> arr;
	vector<int>::iterator index;
	cin >> n;
	while (i < n)
	{
		cin >> _temp;
		flag = true;
		for (index = arr.begin(); index < arr.end(); index++)
		{
			if (*index == _temp)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			arr.push_back(_temp);
		}	
		i++;
	}
	qsort(&arr[0], arr.size(), sizeof(int), cmp);
	for (i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;
	return 0;
}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int compareType(const void* a, const void* b)
//{
//	return (*(int*)a - *(int*)b);
//}
//
//int main() {
//	int n, _temp, i, num;
//	vector<int> arr;
//	cin >> n;
//	num = 0;
//	while (n > 0)
//	{
//		cin >> _temp;
//		for (i = 0; i <= num; i++)
//		{
//			if (num > 0 && _temp == arr[i])
//				break;
//		}
//		if (i == num + 1)
//		{
//			arr.push_back(_temp);
//			num++;
//		}
//		n--;
//	}
//	qsort(&arr[0], arr.size(), sizeof(int), compareType);
//	for (i = 0; i < arr.size(); i++)
//		cout << arr[i] << endl;
//	return 0;
//}