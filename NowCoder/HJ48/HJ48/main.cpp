#include <iostream>
#include <list>
using namespace std;

class List
{
public:
	int val;
	List * next;
	List(int a) :val(a)
	{
		next = nullptr;
	}
}
;

void Inster(List &list, int a, int b)
{
	List * t = &list;
	List * plist = new List(a);
	while (t && t->val != b)
		t = t->next;
	plist->next = t->next;
	t->next = plist;
}

void Delete(List & list, int a)
{
	List * t = &list;
	if (list.val == a)
	{
		list.val = list.next->val;
		list.next = list.next->next;
	}
	else
	{
		List * pre = t;
		while (t && t->val != a)
		{
			pre = t;
			t = t->next;
		}
		pre->next = t->next;
	}
}

void Print(List & list)
{
	List * t = &list;
	while (t)
	{
		cout << t->val << ' ';
		t = t->next;
	}
}

int main()
{
	int n, a, b;
	cin >> n >> a;
	List list(a);
	while (--n>0)
	{
		cin >> a >> b;
		Inster(list, a, b);
	}
	cin >> a;
	Delete(list, a);
	Print(list);
	return 0;
}
