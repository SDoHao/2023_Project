#include<iostream>
using namespace std;
struct list
{
	public:
		int val;
		list * next;
		list()
		{
			next = nullptr;
		}
		list(int a) :val(a) 
		{
			next = nullptr;
		}
		void Insert(int a)
		{
			list *plist = new list();
			plist->val = val;
			plist->next = next;
			next = plist;
			val = a;
		}
		void Print(int a)
		{
			
			if (a == 0||a==1)
				cout << val << endl;
			else
			{
				list *plist = next;
				int i = 1;
				for (; i < a - 1; i++)
					plist = plist->next;
				cout << plist->val << endl;
			}
		}
};

int main()
{
	int i,n, a;
	while (cin >> n)
	{
		i = n;
		cin >> a;
		list l(a);
		while (--i > 0)
		{
			cin >> a;
			l.Insert(a);
		}
		cin >> a;
		l.Print(a);
	}

	return 0;
}